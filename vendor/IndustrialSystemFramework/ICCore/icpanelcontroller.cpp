#include "icpanelcontroller.h"
#include "icappsettings.h"

#include <QFormLayout>
#include <QDeclarativeContext>
#include <qmath.h>
#include <QMessageBox>

#ifdef Q_WS_QWS
int ICPanelController::wdFD = -1;
int ICPanelController::checkTime = 60;
int ICPanelController::dummy = 0;
#endif





ICSplashScreen::ICSplashScreen(const QPixmap &pixmap, const QString &swVersion, const QString &hwVersion, const QString &customInfo, const QString &shipDate, Qt::WindowFlags f) :
    QSplashScreen(pixmap, f)
{
    progressBar_ = new QProgressBar(this);
    progressBar_->resize(this->width() - 200, 20);
    progressBar_->move(100, height() * 7 / 8 );
    versionContainer_ = new QWidget(this);
    QFormLayout *flayout = new QFormLayout();
    swVersionLabel_ = new QLabel(tr("SW Version:"), this);
    swVersion_ = new QLabel(swVersion, this);
    hwVersionLabel_ = new QLabel(tr("HW Version:"), this);
    hwVersion_ = new QLabel(hwVersion, this);
    clientLabel_ = new QLabel(tr("Client:"), this);
    client_ = new QLabel(customInfo, this);
    //    client_ = new QLabel(ICParametersSave::Instance()->Client(), this);
    if(client_->text().isEmpty())
    {
        clientLabel_->hide();
        client_->hide();
    }
    dateLabel_ = new QLabel(tr("Shiment Date:"), this);
    date_ = new QLabel(shipDate, this);
    if(date_->text().isEmpty())
    {
        dateLabel_->hide();
        date_->hide();
    }
    flayout->addRow(swVersionLabel_, swVersion_);
    flayout->addRow(hwVersionLabel_, hwVersion_);
    flayout->addRow(clientLabel_, client_);
    flayout->addRow(dateLabel_, date_);

    versionContainer_->setLayout(flayout);

    int h = height() * 0.65;
    versionContainer_->move(20, h);
    connect(this,
            SIGNAL(messageChanged(QString)),
            this,
            SLOT(OnMessageChanged(QString)));

}

void ICSplashScreen::OnMessageChanged(const QString &message)
{
    Q_UNUSED(message)
    progressBar_->setValue(progressBar_->value() + 1);
}

ICPanelController::ICPanelController(QSplashScreen *splash, ICLog* logger, QObject *parent) :
    QObject(parent),
    logger_(logger),
    customSettings_("usr/customsettings.ini", QSettings::IniFormat)
{
    mainView_ = NULL;
//    getConfigRange_ = NULL;
    QDir backupDir(ICAppSettings::UserPath);
    if(!backupDir.exists())
    {
#ifdef Q_WS_QWS
        backupDir.mkpath(ICAppSettings::UserPath);
#else
        QDir::current().mkdir(ICAppSettings::UserPath);
#endif
    }
    connect(this,
            SIGNAL(LoadMessage(QString)),
            splash,
            SLOT(showMessage(QString)));
    emit LoadMessage("Start");
//    connect(qApp,
//            SIGNAL(focusChanged(QWidget*,QWidget*)),
//            SIGNAL(focusChanged(QWidget*,QWidget*)));
}

ICPanelController::~ICPanelController()
{
#ifdef Q_WS_QWS
    close(wdFD);
#endif
}

void ICPanelController::InitMainView()
{
    if(mainView_ != NULL)
    {
        mainView_->close();
    }
    emit LoadMessage("Initing ui...");
    qDebug("Init MainView");
    mainView_ = new QtQuick1ApplicationViewer;
    mainView_->rootContext()->setContextProperty("panelController", this);
    mainView_->rootContext()->setContextProperty("virtualKeyboard", &virtualKeyboard);
    mainView_->addImportPath(QLatin1String("modules"));
    mainView_->setOrientation(QtQuick1ApplicationViewer::ScreenOrientationAuto);
#ifdef Q_WS_QWS
    mainView_->setWindowFlags(Qt::FramelessWindowHint);
#endif
    ICAppSettings settings;
    QString uiMain = settings.UIMainName();
    QDir appDir = QDir::current();
    if(uiMain.isEmpty() || !appDir.exists(uiMain))
    {
#ifdef Q_WS_QWS
        uiMain = "Init";
#else
        uiMain = "../Init";
#endif
    }
    appDir.cd(uiMain);
    emit LoadMessage(appDir.filePath("main.qml"));
    mainView_->setMainQmlFile(appDir.filePath("main.qml"));
    mainView_->showExpanded();
}

QString ICPanelController::usbDirs() const
{
    QDir usb(ICAppSettings::UsbPath);
    if(!usb.exists())
        return QString();
    QStringList dirs = usb.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    for(int i = 0; i != dirs.size(); ++i)
    {
        dirs[i] = QString("\"%1\"").arg(dirs.at(i));
    }
    QString ret = QString("[%1]").arg(dirs.join(","));
    return ret;
}

QString ICPanelController::localUIDirs() const
{
    QDir qml(ICAppSettings::QMLPath);
    if(!qml.exists())
        return QString();
    QStringList dirs = qml.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    for(int i = 0; i != dirs.size(); ++i)
    {
        dirs[i] = QString("\"%1\"").arg(dirs.at(i));
    }
    QString ret = QString("[%1]").arg(dirs.join(","));
    return ret;
}

void ICPanelController::setToRunningUIPath(const QString &dirname)
{
    QDir qml(ICAppSettings::QMLPath);
    if(qml.exists(dirname))
    {
        qml.cd(dirname);
        if(qml.exists("main.qml"))
        {
            ICAppSettings settings;
            settings.SetUIMainName(qml.path());
            settings.sync();
#ifdef Q_WS_QWS
            ::system("reboot");
#endif
        }
    }
}

bool ICPanelController::setCurrentTranslator(const QString &name)
{
    QMessageBox box;
    box.setText("Language Chaning...");
    box.show();
    //    qApp->processEvents();
    qApp->processEvents();

    ICAppSettings().SetTranslatorName(name);
    return LoadTranslator_(name);
}

QString ICPanelController::records() const
{
    QString content;
    ICRecordInfos infos = mold_->RecordInfos();
    for(int i = 0; i != infos.size(); ++i )
    {
        content += infos.at(i).toJSON() + ",";
    }
    content.chop(1);
    QString ret = QString("[%1]").arg(content);
    return ret;
}

quint32 ICPanelController::getConfigValue(const QString &addr) const
{
    ICAddrWrapperCPTR configWrapper = ICAddrWrapper::AddrStringToAddr(addr);
    if(configWrapper == NULL)
    {
        qWarning()<<addr<<"is invalid";
        return 0;
    }
    if(configWrapper->AddrType() == ICAddrWrapper::kICAddrTypeMold)
    {
        return mold_->MoldFnc(configWrapper);
    }
    if(configWrapper->AddrType() == ICAddrWrapper::kICAddrTypeSystem)
    {
        return machineConfigs_->MachineConfig(configWrapper);
    }
    if(configWrapper->AddrType() == ICAddrWrapper::kICAddrTypeCrafts)
    {
        host_->HostStatusValue(configWrapper);
    }
    return 0;
}

QString ICPanelController::getConfigValueText(const QString &addr) const
{
    ICAddrWrapperCPTR configWrapper = ICAddrWrapper::AddrStringToAddr(addr);
    if(configWrapper == NULL)
    {
        qWarning()<<addr<<"is invalid";
        return QString();
    }
    quint32 v = getConfigValue(addr);
    ICRange range = ICConfigRangeGetter(addr);
    if((range.min < 0) && (v >> (configWrapper->Size() - 1)))
    {
        v |= ((-1) << configWrapper->Size());
    }
    return QString::number(qint32(v) / qPow(10, configWrapper->Decimal()),
                           'f',
                           configWrapper->Decimal());

}

void ICPanelController::setConfigValue(const QString &addr, const QString &v)
{
    ICAddrWrapperCPTR configWrapper = ICAddrWrapper::AddrStringToAddr(addr);
    if(configWrapper == NULL) return;
    qDebug()<<"PanelRobotController::setConfigValue"<<addr<<v;
    quint32 intV = AddrStrValueToInt(configWrapper, v);
    ICAddrWrapperValuePair p = qMakePair<ICAddrWrapperCPTR, quint32>(configWrapper, intV);
    if(configWrapper->AddrType() == ICAddrWrapper::kICAddrTypeMold)
    {
        moldFncModifyCache_.append(p);
    }
    if(configWrapper->AddrType() == ICAddrWrapper::kICAddrTypeSystem)
    {
        machineConfigModifyCache_.append(p);
    }
    //    qDebug()<<moldFncModifyCache_;
}

void ICPanelController::syncConfigs()
{
    if(!moldFncModifyCache_.isEmpty())
    {
        QList<QPair<int, quint32> > addrVals = mold_->SetMoldFncs(moldFncModifyCache_);
        host_->SendConfigs(addrVals);
        moldFncModifyCache_.clear();
    }
    else if(!machineConfigModifyCache_.isEmpty())
    {
        QList<QPair<int, quint32> > addrVals = machineConfigs_->SetMachineConfigs(machineConfigModifyCache_);
        host_->SendConfigs(addrVals);
        machineConfigModifyCache_.clear();
    }
}
ICRange ICPanelController::ICConfigRangeGetter(const QString& addrName) const
{
    QScriptValueList args;
    args<<addrName;
    QMap<QString, QVariant> ranges = getConfigRange_.call(QScriptValue(),args).toVariant().toMap();
    QVariant minVariant = ranges.value("min");
    QVariant maxVariant = ranges.value("max");
    double min, max;
    if(minVariant.type() != QVariant::String)
        min = minVariant.toDouble();
    else
    {
        ICRange ret = ICConfigRangeGetter(minVariant.toString());
        qint32 v = getConfigValue(minVariant.toString());
        ICAddrWrapperCPTR configWrapper = ICAddrWrapper::AddrStringToAddr(minVariant.toString());
        if(ret.min < 0  && (v >> (configWrapper->Size() - 1)))
        {
            v |= (-1 << configWrapper->Size());
        }
        min = v / qPow(10, configWrapper->Decimal());
    }
    if(maxVariant.type() != QVariant::String)
        max = maxVariant.toDouble();
    else
    {
        ICRange ret = ICConfigRangeGetter(maxVariant.toString());
        qint32 v = getConfigValue(maxVariant.toString());
        ICAddrWrapperCPTR configWrapper = ICAddrWrapper::AddrStringToAddr(maxVariant.toString());
        if(ret.min < 0  && (v >> (configWrapper->Size() - 1)))
        {
            v |= (-1 << configWrapper->Size());
        }
        max = v / qPow(10, configWrapper->Decimal());
    }
    return ICRange(min,max,ranges.value("decimal").toInt());
}

quint32 ICPanelController::AddrStrValueToInt(ICAddrWrapperCPTR addr, const QString& value) const
{
    double v = value.toDouble();
    double diff = 5 * (v < 0 ? -1 : 1) / qPow(10, addr->Decimal() + 1);
    v += diff;
    qint32 ret = v * qPow(10, addr->Decimal());
    return static_cast<quint32>(ret);
}

int ICPanelController::statusValue(const QString& addr) const
{
    ICAddrWrapperCPTR configWrapper = ICAddrWrapper::AddrStringToAddr(addr);
    if(configWrapper == NULL) return 0;
    return host_->HostStatusValue(configWrapper);
}

QString ICPanelController::statusValueText(const QString &addr) const
{
    ICAddrWrapperCPTR configWrapper = ICAddrWrapper::AddrStringToAddr(addr);
    if(configWrapper == NULL) return "*";
    return QString(host_->HostStatus(configWrapper));
}

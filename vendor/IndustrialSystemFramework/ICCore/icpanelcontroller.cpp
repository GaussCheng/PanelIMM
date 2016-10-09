#include "icpanelcontroller.h"
#include "icappsettings.h"

#include <QFormLayout>
#include <QDeclarativeContext>

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
    logger_(logger),
    customSettings_("usr/customsettings.ini", QSettings::IniFormat),
    QObject(parent)
{
    mainView_ = NULL;
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

#include "icpanelcontroller.h"
#include "icappsettings.h"
#include "icregister.h"
#include "icupdatesystem.h"
#include "icutility.h"

#include <QFormLayout>
#include <QDeclarativeContext>
#include <qmath.h>
#include <QMessageBox>

#ifdef Q_WS_QWS
int ICPanelController::wdFD = -1;
int ICPanelController::checkTime = 60;
int ICPanelController::dummy = 0;
#endif


QString scanHelper(const QString& filter, const QString &path = ICAppSettings::UsbPath)
{
    QDir usb(path);
    QStringList updaters = usb.entryList(QStringList()<<filter);
    QString ret = "[";
    for(int i = 0; i != updaters.size(); ++i)
    {
        ret.append(QString("\"%1\",").arg(updaters.at(i)));
    }
    if(updaters.size() != 0)
        ret.chop(1);
    ret.append("]");
    return ret;
}



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


    if(ICRegister::Instance()->IsTryTimeOver())
    {
        emit tryTimeOver();
    }


#ifdef Q_WS_QWS
    screenSaver_ = new ICDefaultScreenSaver();
    ScreenFunctionObject* fo = new ScreenFunctionObject();
    screenSaver_->SetScreenFunction(fo);
    connect(fo,
            SIGNAL(ScreenSaved()),
            SIGNAL(screenSave()));
    connect(fo,
            SIGNAL(ScreenRestored()),
            SIGNAL(screenRestore()));
    QWSServer::setScreenSaver(screenSaver_);
    QWSServer::setScreenSaverBlockLevel(-1);
    connect(&watchDogTimer_, SIGNAL(timeout()),
            SLOT(OnWatchDogTimeOut()));
    wdFD = open("/dev/watchdog", O_RDWR);
    if(wdFD < 0)
    {
        qWarning("Open watchdog error\n");
    }
    else
    {
        ioctl(wdFD, WDIOC_SETTIMEOUT, &checkTime);
        int options = WDIOS_ENABLECARD	;
        ioctl(wdFD, WDIOC_SETOPTIONS, &options);
    }

    watchDogTimer_.start(20000);

#endif

    emit LoadMessage("Controller inited.");

}

ICPanelController::~ICPanelController()
{
#ifdef Q_WS_QWS
    close(wdFD);
#endif
}

void ICPanelController::OnWatchDogTimeOut()
{
#ifdef Q_WS_QWS
    ioctl(wdFD, WDIOC_KEEPALIVE, &dummy);
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
    appID_ = "base";
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
    qDebug()<<"ICPanelController::setConfigValue"<<addr<<v;
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


QString ICPanelController::scanUSBUpdaters(const QString &filter) const
{
    return scanHelper(QString("%1*.bfe").arg(filter));
}

QString ICPanelController::scanUpdaters(const QString &filter, int mode) const
{
    if(mode == 1)
        return scanUSBUpdaters(filter);
    return scanUserDir("updaters", QString("%1*.bfe").arg(filter));
}

void ICPanelController::startUpdate(const QString &updater, int mode)
{
    ICUpdateSystem us;
    if(mode == 0)
        us.SetPacksDir(ICAppSettings().UsbPath);
    else
        us.SetPacksDir(QString(ICAppSettings().UserPath) + "/updaters");
    host_->StopCommunicate();
    system("mkdir updatehost/");
    hostUpdateFinishedWatcher_.addPath("updatehost");
    connect(&hostUpdateFinishedWatcher_, SIGNAL(directoryChanged(QString)), this, SLOT(OnHostUpdateFinished(QString)));
    mainView_->hide();
#ifdef Q_WS_QWS
    int flags;
    flags = WDIOS_DISABLECARD;
    ioctl(wdFD, WDIOC_SETOPTIONS, &flags);
#endif
    us.StartUpdate(updater);
#ifdef Q_WS_QWS
    flags = WDIOS_ENABLECARD;
    ioctl(wdFD, WDIOC_SETOPTIONS, &flags);
#endif

}

QString ICPanelController::backupUpdater(const QString &updater)
{
    QDir dir(ICAppSettings::UserPath);
    if(!dir.exists("updaters"))
    {
        dir.mkdir("updaters");
    }
    dir.cd("updaters");
    QString bf = updater;
    if(dir.exists(bf))
    {
        QFile::remove(dir.absoluteFilePath(bf));
    }
    QDir usbDir(ICAppSettings::UsbPath);
    QFile::copy(usbDir.absoluteFilePath(bf), dir.absoluteFilePath(bf));
    return bf;
}

QString ICPanelController::scanUSBBackupPackages(const QString& filter) const
{
    return scanHelper(QString("%1*.tar").arg(filter));
}

QString ICPanelController::viewBackupPackageDetails(const QString &package) const
{
    QString tarPath = QDir(ICAppSettings::UsbPath).absoluteFilePath(package);
    QDir temp = QDir::temp();
    QString packageDirName = package;
    packageDirName.chop(4);
    if(!temp.exists(packageDirName))
    {
        ::system(QString("tar -xf %1 -C %2").arg(tarPath).arg(temp.path()).toUtf8());
    }
    temp.cd(packageDirName);
    QStringList molds = temp.entryList(QStringList()<<"*.act");
#ifdef Q_WS_QWS
    QByteArray ret = "[";
#else
    QString ret = "[";
#endif
    QString m;
    for(int i = 0; i != molds.size(); ++i)
    {
        m = molds.at(i);
        m.chop(4);
        ret.append(QString("\"%1\",").arg(m));
    }
    if(molds.size() != 0)
        ret.chop(1);
    ret.append("]");
#ifdef Q_WS_QWS
    return QString::fromUtf8(ret);
#else
    return ret;
#endif
}

void ICPanelController::OnHostUpdateFinished(QString)
{
    qDebug("finised");
    disconnect(&hostUpdateFinishedWatcher_, SIGNAL(directoryChanged(QString)), this, SLOT(OnHostUpdateFinished(QString)));
#ifdef QT5
#else
    mainView_->repaint();
#endif
    mainView_->show();
    qApp->processEvents();
    host_->StartCommunicate();
    hostUpdateFinishedWatcher_.removePath("updatehost");
    system("rm -r updatehost");
}

void ICPanelController::setWatchDogEnabled(bool en)
{

#ifdef Q_WS_QWS
    int flags;
    if(en)
    {
        flags = WDIOS_ENABLECARD;
        ioctl(wdFD, WDIOC_SETTIMEOUT, &checkTime);
    }
    else
    {
        flags = WDIOS_DISABLECARD;
    }
    ioctl(wdFD, WDIOC_SETOPTIONS, &flags);
#endif

}

QString ICPanelController::getPictures() const
{
    QDir usb(ICAppSettings::UsbPath);
    if(!usb.exists("HCUpdate_pic")) return "[]";
    usb.cd("HCUpdate_pic");
    QStringList updaters = usb.entryList(QStringList()<<"*.png");
    QString ret = "[";
    for(int i = 0; i != updaters.size(); ++i)
    {
        ret.append(QString("\"%1\",").arg(updaters.at(i)));
    }
    if(updaters.size() != 0)
        ret.chop(1);
    ret.append("]");
    return ret;
}

QString ICPanelController::getPicturesPath(const QString& picName) const
{
    QDir usb(ICAppSettings::UsbPath);
    if(!usb.exists("HCUpdate_pic")) return "";
    usb.cd("HCUpdate_pic");
    return usb.absoluteFilePath(picName);
}

void ICPanelController::copyPicture(const QString &picName, const QString& to) const
{
    QDir usb(ICAppSettings::UsbPath);
    if(!usb.exists("HCUpdate_pic")) return;
    usb.cd("HCUpdate_pic");
    ICAppSettings settings;
    QString uiMain = settings.UIMainName();
    QDir appDir = QDir::current();
    appDir.cd(uiMain);
    appDir.cd("images");
    ::system(QString("cp %1 %2 -f").arg(usb.absoluteFilePath(picName))
             .arg(appDir.absoluteFilePath(to)).toLatin1());
    ::system("sync");
}


QString ICPanelController::scanUserDir(const QString &path, const QString &filter) const
{
    QDir dir(ICAppSettings::UserPath);
    if(!dir.exists(path))
        return "[]";
    dir.cd(path);
    QStringList toSearch = dir.entryList(QStringList()<<filter);
    QString ret = "[";
    for(int i = 0; i != toSearch.size(); ++i)
    {
        ret.append(QString("\"%1\",").arg(toSearch.at(i)));
    }
    if(toSearch.size() != 0)
        ret.chop(1);
    ret.append("]");
    return ret;
}

QString ICPanelController::backupHMIBackup(const QString& backupName, const QString& sqlData) const
{
    QDir dir(ICAppSettings::UserPath);
    if(!dir.exists("hmibps"))
    {
        dir.mkdir("hmibps");
    }
    dir.cd("hmibps");
    QString utf8BackupName = backupName;
    QString bf = utf8BackupName + ".hmi.hcdb";
    if(dir.exists(bf.toUtf8()))
    {
        QFile::remove(dir.absoluteFilePath(bf.toUtf8()));
    }
    dir.mkdir(utf8BackupName.toUtf8());
    dir.cd(utf8BackupName.toUtf8());
    QFile sql(dir.absoluteFilePath("hmi.sql"));
    if(sql.open(QFile::WriteOnly))
    {
        sql.write(sqlData.toUtf8());
        sql.close();
    }
    QFile::copy("usr/customsettings.ini", dir.absoluteFilePath("customsettings.ini"));
    QFile::copy("sysconfig/PanelRobot.ini", dir.absoluteFilePath("PanelRobot.ini"));
    dir.cdUp();
    ::system(QString("cd %1 && tar -zcvf - %2 | openssl des3 -salt -k szhcSZHCGaussCheng | dd of=%2.hmi.hcdb")
             .arg(dir.absolutePath()).arg(utf8BackupName).toUtf8());

    ICUtility::DeleteDirectory(dir.absoluteFilePath(utf8BackupName.toUtf8()));
    return utf8BackupName + ".hmi.hcdb";
}

QString ICPanelController::restoreHMIBackup(const QString &backupName, int mode)
{
    QString dirPath = (mode == 0 ? QString(ICAppSettings::UserPath) + "/hmibps" : ICAppSettings::UsbPath);
    QDir dir(dirPath);
    if(!dir.exists(backupName.toUtf8())) return "";
    ::system(QString("cd %2 && dd if=%1 | openssl des3 -d -k szhcSZHCGaussCheng | tar zxf -").arg(backupName).arg(dir.absolutePath()).toUtf8());
    QString backupDirName = backupName;
    backupDirName.chop(9);
    QDir backupDir(dir.absoluteFilePath(backupDirName.toUtf8()));
    QFile sqlData(backupDir.absoluteFilePath("hmi.sql"));
    sqlData.open(QFile::ReadOnly);
    QString ret = QString::fromUtf8(sqlData.readAll());
    sqlData.close();
    QFile::remove("usr/customsettings.ini");
    QFile::remove("sysconfig/PanelRobot.ini");
    QFile::copy(backupDir.absoluteFilePath("customsettings.ini"), "usr/customsettings.ini");
    QFile::copy(backupDir.absoluteFilePath("PanelRobot.ini"), "sysconfig/PanelRobot.ini");
    ::system(QString("rm -r %1").arg(backupDir.absolutePath()).toUtf8());
    ::system("sync");
    return ret;
}

QString ICPanelController::backupMRBackup(const QString &backupName) const
{
    QDir dir(ICAppSettings::UserPath);
    if(!dir.exists("mrbps"))
    {
        dir.mkdir("mrbps");
    }
    dir.cd("mrbps");
    QString bf = backupName + ".mr.hcdb";
    if(dir.exists(bf.toUtf8()))
    {
        QFile::remove(dir.absoluteFilePath(bf.toUtf8()));
    }
    dir.mkdir(backupName.toUtf8());
    dir.cd(backupName.toUtf8());
    QFile::copy("RobotDatabase", dir.absoluteFilePath("RobotDatabase"));
    dir.cdUp();
    ::system(QString("cd %1 && tar -zcvf - %2 | openssl des3 -salt -k szhcSZHCGaussCheng | dd of=%2.mr.hcdb")
             .arg(dir.absolutePath()).arg(backupName).toUtf8());
    ICUtility::DeleteDirectory(dir.absoluteFilePath(backupName.toUtf8()));
    return backupName + ".mr.hcdb";

}

void ICPanelController::restoreMRBackup(const QString &backupName, int mode)
{
    QString dirPath = (mode == 0 ? QString(ICAppSettings::UserPath) + "/mrbps" : ICAppSettings::UsbPath);
    QDir dir(dirPath);
    if(!dir.exists(backupName.toUtf8())) return;
    ::system(QString("cd %2 && dd if=%1 | openssl des3 -d -k szhcSZHCGaussCheng | tar zxf -").arg(backupName).arg(dir.absolutePath()).toUtf8());
    QString backupDirName = backupName;
    backupDirName.chop(8);
    QDir backupDir(dir.absoluteFilePath(backupDirName.toUtf8()));
    QFile::remove("RobotDatabase");
    QFile::copy(backupDir.absoluteFilePath("RobotDatabase"), "RobotDatabase");
    ::system(QString("rm -rf %1").arg(backupDir.absolutePath()).toUtf8());

}


QString ICPanelController::makeGhost(const QString &ghostName, const QString& hmiSqlData) const
{
    QDir dir(ICAppSettings::UserPath);
    if(!dir.exists("ghosts"))
    {
        dir.mkdir("ghosts");
    }
    dir.cd("ghosts");
    QString bf = ghostName + ".ghost.hcdb";
    if(dir.exists(bf.toUtf8()))
    {
        QFile::remove(dir.absoluteFilePath(bf.toUtf8()));
    }
    QFile sql("hmi.sql");
    if(sql.open(QFile::WriteOnly))
    {
        sql.write(hmiSqlData.toUtf8());
        sql.close();
    }
    ::system(QString("tar -zcvf - %1 | openssl des3 -salt -k szhcSZHCGaussCheng | dd of=%2")
             .arg(QDir::current().absolutePath())
             .arg(dir.absoluteFilePath(ghostName + ".ghost.hcdb")).toUtf8());
    return ghostName + ".ghost.hcdb";
}

QString ICPanelController::restoreGhost(const QString& backupName, int mode)
{
    QString dirPath = (mode == 0 ? QString(ICAppSettings::UserPath) + "/ghosts" : ICAppSettings::UsbPath);
    QDir dir(dirPath);
    if(!dir.exists(backupName.toUtf8())) return "";
    ::system(QString("cd %2 && dd if=%1 | openssl des3 -d -k szhcSZHCGaussCheng | tar zxf - -C /")
             .arg(backupName)
             .arg(dir.absolutePath()).toUtf8());
    QFile sql("hmi.sql");
    QString ret;
    if(sql.open(QFile::ReadOnly))
    {
        ret = QString::fromUtf8(sql.readAll());
        sql.close();
    }
    return ret;
}

QString ICPanelController::scanHMIBackups(int mode) const
{
    if(mode == 1)
        return scanHelper(HMIBackupPattern());
    return scanUserDir("hmibps", HMIBackupPattern());
}

QString ICPanelController::scanMachineBackups(int mode) const
{
    if(mode == 1)
        return scanHelper(MachineBackupPattern());
    return scanUserDir("mrbps", MachineBackupPattern());

}

QString ICPanelController::scanGhostBackups(int mode) const
{
    if(mode == 1)
        return scanHelper(GhostPattern());
    return scanUserDir("ghosts", GhostPattern());
}

int exportBackupHelper(const QString& backupName, const QString& path)
{
    QDir dir(ICAppSettings::UserPath);
    if(!dir.cd(path)) return -1;
    if(!dir.exists(backupName.toUtf8())) return -1;
    if(!ICUtility::IsUsbAttached()) return -2;
    //    qDebug()<<dir.absoluteFilePath(backupName.toUtf8())<<QDir(ICAppSettings::UsbPath).absoluteFilePath(backupName)<<QDir(ICAppSettings::UsbPath).absoluteFilePath(backupName.toUtf8());
    if(QFile::copy(dir.absoluteFilePath(backupName.toUtf8()), QDir(ICAppSettings::UsbPath).absoluteFilePath(backupName.toUtf8())))
    {
#ifdef  Q_WS_QWS
        ::sync();
#endif
        return 0;
    }
    return -3;
}

int ICPanelController::exportHMIBackup(const QString &backupName) const
{
    return exportBackupHelper(backupName, "hmibps");
}

int ICPanelController::exportMachineBackup(const QString &backupName) const
{
    return exportBackupHelper(backupName, "mrbps");
}

int ICPanelController::exportGhost(const QString &backupName) const
{
    return exportBackupHelper(backupName, "ghosts");
}

int ICPanelController::exportUpdater(const QString &updaterName) const
{
    return exportBackupHelper(updaterName, "updaters");
}

void deleteBackupHelper(const QString& subPath, const QString &backupName, int mode)
{
    QString dirPath = (mode == 0 ? QString(ICAppSettings::UserPath) + "/" + subPath : ICAppSettings::UsbPath);
    QDir dir(dirPath);
    if(!dir.exists(backupName.toUtf8())) return;
    QFile::remove(dir.absoluteFilePath(backupName.toUtf8()));
}

void ICPanelController::deleteHIMBackup(const QString &backupName, int mode)
{
    deleteBackupHelper("hmibps", backupName, mode);
}

void ICPanelController::deleteMRBackup(const QString &backupName, int mode)
{
    deleteBackupHelper("mrbps", backupName, mode);
}

void ICPanelController::deleteGhost(const QString &backupName, int mode)
{
    deleteBackupHelper("ghosts", backupName, mode);
}

void ICPanelController::deleteUpdater(const QString &updater, int mode)
{
    deleteBackupHelper("updaters", updater, mode);
}

int ICPanelController::registerUseTime(const QString &fc, const QString &mC, const QString &rcCode)
{
    int ret = ICRegister::Register(fc, mC, rcCode);
    if(ret < 0) return ret;
    ICRegister::Instance()->SetUseTime(ret);
    return ret;
}

QString ICPanelController::generateMachineCode() const
{
    return ICRegister::GenerateMachineCode();
}

int ICPanelController::restUseTime() const
{
    return ICRegister::Instance()->LeftUseTime();
}

bool ICPanelController::isTryTimeOver() const
{
    return ICRegister::Instance()->IsTryTimeOver();
}

void ICPanelController::setRestUseTime(int hour)
{
    ICRegister::Instance()->SetUseTime(hour);
}

#ifndef ICPANELCONTROLLER_H
#define ICPANELCONTROLLER_H

#include <QObject>
#include <QSplashScreen>
#include <QSettings>
#include <QDir>

#include <QProgressBar>
#include <QLabel>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QApplication>
#include <QScriptValue>
#include <QScriptEngine>
#include <QFileSystemWatcher>
#include <QTranslator>
#include <QDebug>

#include "iclog.h"
#include "qtquick1applicationviewer.h"
#include "icmoldbase.h"
#include "icmachineconfig.h"
#include "icvirtualkeyboard.h"
#include "icvirtualhost.h"

class ICSplashScreen : public QSplashScreen
{
    Q_OBJECT
public:
    explicit ICSplashScreen(const QPixmap & pixmap = QPixmap(),
                            const QString& swVersion = QString(),
                            const QString& hwVersion = QString(),
                            const QString& customInfo = QString(),
                            const QString& shipDate = QString(),
                            Qt::WindowFlags f = 0);
    void SetRange(int minum, int maxum) { progressBar_->setRange(minum, maxum);}

protected:
    void mousePressEvent(QMouseEvent* e) {e->ignore();}
    void mouseDoubleClickEvent(QMouseEvent * event ){event->ignore();}

signals:

public slots:
    void SetProgreeBarValue(int value) { progressBar_->setValue(value);}

private slots:
    void OnMessageChanged(const QString &message);
private:
    QProgressBar *progressBar_;
    QLabel* swVersionLabel_;
    QLabel* swVersion_;
    QLabel* hwVersionLabel_;
    QLabel* hwVersion_;
    QLabel* clientLabel_;
    QLabel* client_;
    QLabel* dateLabel_;
    QLabel* date_;
    QWidget* versionContainer_;

};



#ifdef Q_WS_QWS
#include <QWSScreenSaver>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/watchdog.h>

class ScreenFunctionObject: public QObject
{
    Q_OBJECT
public:
    void ScreenSave() { emit ScreenSaved();}
    void ScreenRestore() { emit ScreenRestored();}

Q_SIGNALS:
    void ScreenSaved();
    void ScreenRestored();
};

class ICDefaultScreenSaver:public QWSScreenSaver
{
public:
    ~ICDefaultScreenSaver()
    {
        if(screenFunctionObject_ != NULL)
        {
            delete screenFunctionObject_;
        }
    }

    void restore()
    {
        qDebug("SimpleScreenSaver::restore");
        QWSServer::instance()->refresh();
        //        ICPeripherals::ICBacklightOn();
        if(screenFunctionObject_ != NULL)
        {
            screenFunctionObject_->ScreenRestore();
        }
    }

    bool save(int level)
    {
        Q_UNUSED(level)
        qDebug("SimpleScreenSaver::save");
        //        ICPeripherals::ICBacklightOff();
        //        ICPeripherals::ICShowScreenSaver();
        if(screenFunctionObject_ != NULL)
        {
            screenFunctionObject_->ScreenSave();
        }
        return true;
    }

    void SetScreenFunction(ScreenFunctionObject* o) {screenFunctionObject_ = o;}

private:
    ScreenFunctionObject* screenFunctionObject_;
};
#endif

class ICPanelController : public QObject
{
    Q_OBJECT
public:
    explicit ICPanelController(QSplashScreen* splash, ICLog* logger = NULL, QObject *parent = 0);
    virtual ~ICPanelController();

    Q_INVOKABLE QString usbDirs() const;
    Q_INVOKABLE QString localUIDirs() const;
    Q_INVOKABLE void setToRunningUIPath(const QString& dirname);

    Q_INVOKABLE void posKeyEvent(int key, const QString& text)
    {
        QKeyEvent * e = new QKeyEvent( QEvent::KeyPress, key, Qt::NoModifier, text);
        qApp->postEvent(qApp->focusWidget(), e);
    }

    Q_INVOKABLE bool setCurrentTranslator(const QString& name);

    Q_INVOKABLE QString scanUSBBackupPackages(const QString& filter) const;
    Q_INVOKABLE QString viewBackupPackageDetails(const QString& package) const;

    Q_INVOKABLE void runHardwareTest()
    {
        setWatchDogEnabled(false);
        ::system("chmod +x /usr/bin/run_boardtest.sh && run_boardtest.sh");
        setWatchDogEnabled(true);

    }

    Q_INVOKABLE void setWatchDogEnabled(bool en);

    Q_INVOKABLE QString scanUSBUpdaters(const QString& filter) const;
    Q_INVOKABLE QString scanUpdaters(const QString& filter, int mode = 0) const;
    Q_INVOKABLE void startUpdate(const QString& updater, int mode = 0);
    Q_INVOKABLE QString backupUpdater(const QString& updater);

    Q_INVOKABLE QString getPictures() const;
    Q_INVOKABLE QString getPicturesPath(const QString& picName) const;
    Q_INVOKABLE void copyPicture(const QString &picName, const QString& to) const;
    Q_INVOKABLE QString scanUserDir(const QString& path, const QString& filter) const;
    Q_INVOKABLE QString scanMachineBackups(int mode) const;
    Q_INVOKABLE QString scanHMIBackups(int mode) const;
    Q_INVOKABLE QString scanGhostBackups(int mode) const;
    Q_INVOKABLE QString backupHMIBackup(const QString& backupName, const QString& sqlData) const;
    Q_INVOKABLE QString backupMRBackup(const QString& backupName) const;
    Q_INVOKABLE QString makeGhost(const QString& ghostName, const QString& hmiSqlData) const;
    Q_INVOKABLE int exportHMIBackup(const QString& backupName) const;
    Q_INVOKABLE int exportMachineBackup(const QString& backupName) const;
    Q_INVOKABLE int exportGhost(const QString& backupName) const;
    Q_INVOKABLE int exportUpdater(const QString& updaterName) const;
    Q_INVOKABLE QString restoreHMIBackup(const QString& backupName, int mode);
    Q_INVOKABLE void restoreMRBackup(const QString& backupName, int mode);
    Q_INVOKABLE QString restoreGhost(const QString& backupName, int mode);
    Q_INVOKABLE void deleteHIMBackup(const QString& backupName, int mode);
    Q_INVOKABLE void deleteMRBackup(const QString& backupName, int mode);
    Q_INVOKABLE void deleteGhost(const QString& backupName, int mode);
    Q_INVOKABLE void deleteUpdater(const QString& updater, int mode);
    Q_INVOKABLE void reboot() { ::system("reboot");}

    Q_INVOKABLE void processEvents()
    {
        qApp->processEvents();
    }

    Q_INVOKABLE int registerUseTime(const QString& fc, const QString& mC, const QString& rcCode);
    Q_INVOKABLE QString generateMachineCode() const;
    Q_INVOKABLE int restUseTime() const;
    Q_INVOKABLE void setRestUseTime(int hour);
    Q_INVOKABLE bool isTryTimeOver() const;

    Q_INVOKABLE QString factoryCode() const
    {
        return ICSuperSettings().FactoryCode();
    }

    Q_INVOKABLE void setFactoryCode(const QString& fc)
    {
        ICSuperSettings().SetFactoryCode(fc);
    }

    Q_INVOKABLE QString getCustomSettings(const QString& key, const QVariant& defval, const QString& group = QString::fromLatin1("custom"))
    {
        QString ret;
        customSettings_.beginGroup(group);
        ret = customSettings_.value(key, defval).toString();
        customSettings_.endGroup();
        return ret;
    }

    Q_INVOKABLE void setCustomSettings(const QString& key,
                                       const QVariant& val,
                                       const QString& group = QString::fromLatin1("custom"),
                                       bool isSync = true)
    {
        customSettings_.beginGroup(group);
        customSettings_.setValue(key, val);
        customSettings_.endGroup();
        if(isSync)
            customSettings_.sync();
    }

    Q_INVOKABLE QString hostVersion() const { return host_->HostVersion();}
    Q_INVOKABLE QString panelControllerVersion() const { return SW_VER;}
    Q_INVOKABLE QString controllerVersion() const {
        return panelControllerVersion() + "_" + hostVersion();
    }

    Q_INVOKABLE void setKeyTone(bool status)
    {
#ifndef Q_WS_WIN32
        int beepFD = open("/dev/szhc_beep", O_WRONLY);
        if(beepFD > 0)
        {
            ioctl(beepFD, 0, status ? 1 : 0);
            close(beepFD);
        }
#endif
    }

    Q_INVOKABLE void setBrightness(int brightness)
    {
        if(brightness > 0 && brightness <9)
            ::system(QString("BackLight.sh  %1").arg(brightness).toLatin1());
    }

    Q_INVOKABLE void closeBacklight()
    {
        system("BackLight.sh 0");
    }

    Q_INVOKABLE void setDatetime(const QString& datetime)
    {
        QDateTime dateTime = QDateTime::fromString(datetime, "yyyy/M/d h:m:s");
        if(dateTime.isValid())
        {
            ::system(QString("date -s %1 && hwclock -w").arg(dateTime.toString("yyyy.MM.dd-hh:mm:ss")).toLatin1());
        }
    }

    Q_INVOKABLE void setScreenSaverTime(int min)
    {
#ifdef Q_WS_QWS
        QWSServer::setScreenSaverInterval(min * 60000);
#endif
    }

    //    Q_INVOKABLE bool isInputOn(int index, int board) const
    //    {
    //        //        return rand() % 2;
    //        quint32 iStatus = host_->IStatus(board);
    //        return iStatus & (1 << index);
    //    }
    //    Q_INVOKABLE bool isOutputOn(int index, int board) const
    //    {
    //        //        return rand() % 2;
    //        quint32 oStatus = ICRobotVirtualhost::OStatus(board);
    //        return oStatus & (1 << index);
    //    }
    //    Q_INVOKABLE void sendKeyCommandToHost(int key);
    Q_INVOKABLE quint32 getConfigValue(const QString& addr) const;
    Q_INVOKABLE QString getConfigValueText(const QString& addr) const;
    Q_INVOKABLE double getRealConfigValue(const QString& addr) const
    {
        return getConfigValueText(addr).toDouble();
    }
    Q_INVOKABLE int statusValue(const QString& addr) const;
    Q_INVOKABLE QString statusValueText(const QString& addr) const;

    Q_INVOKABLE int configDecimal(const QString& addr) const
    {
        QStringList item = addr.split("_", QString::SkipEmptyParts);
        return (item.size() == 6) ? item.at(4).toInt() : 0;
    }
    Q_INVOKABLE void setConfigValue(const QString& addr, const QString& v);
    Q_INVOKABLE void syncConfigs();

    Q_INVOKABLE QString currentRecordName() const
    {
        return mold_->CurrentMoldInfo().name;
    }

    Q_INVOKABLE QString records() const;

    Q_INVOKABLE bool loadRecord(const QString& name)
    {
        bool ret =  mold_->LoadMold(ICMoldInfo(name));
        if(ret)
            emit moldChanged();
        return ret;
    }
    Q_INVOKABLE bool deleteRecord(const QString& name)
    {
        return mold_->DeleteRecord(name);
    }

    Q_INVOKABLE QString copyRecord(const QString& name, const QString& source)
    {
        return mold_->CopyRecord(name, source).toJSON();
    }

    Q_INVOKABLE QString configRange(const QString& addr) const
    {
        ICRange rg = ICConfigRangeGetter(addr);
        return QString("{\"min\":%1,\"max\":%2, \"decimal\":%3}")
                .arg(rg.min).arg(rg.max).arg(rg.decimal);
    }

    void InitMainView();

    QWidget* MainView()
    {
#ifdef QT5
        QWidget *container = QWidget::createWindowContainer(mainView_);
        return container;
#else
        return mainView_;
#endif
    }

    ICRange ICConfigRangeGetter(const QString& addrName) const;
    quint32 AddrStrValueToInt(ICAddrWrapperCPTR addr, const QString& value) const;

    QString GetAppID() const { return appID_;}
    void SetAppID(const QString& id) { appID_ = id;}

signals:
    void screenSave();
    void screenRestore();
    void LoadMessage(const QString&);
    void moldChanged();
    void needToInitHost();
    void tryTimeOver();

public slots:
private slots:
    void OnHostUpdateFinished(QString);
    void OnWatchDogTimeOut();
protected:
    QScopedPointer<ICMoldBase> mold_;
    QScopedPointer<ICMachineConfig> machineConfigs_;
    ICVirtualHostPtr host_;
    mutable QScriptValue getConfigRange_;
    QScriptEngine engine_;
    ICAddrWrapperValuePairList moldFncModifyCache_;
    ICAddrWrapperValuePairList machineConfigModifyCache_;
    QTranslator translator_;

private:
    virtual bool LoadTranslator_(const QString& name) = 0;
    QString HMIBackupPattern() const { return QString("*.hmi.%1.hcdb").arg(GetAppID());}
    QString MachineBackupPattern() const { return QString("*.mr.%1.hcdb").arg(GetAppID());}
    QString GhostPattern() const { return QString("*.ghost.%1.hcdb").arg(GetAppID());}
private:
    ICLog* logger_;
    QSettings customSettings_;
    QtQuick1ApplicationViewer *mainView_;
    ICVirtualKeyboard virtualKeyboard;
    QFileSystemWatcher hostUpdateFinishedWatcher_;
    QString appID_;
#ifdef Q_WS_QWS
    QTimer watchDogTimer_;
    ICDefaultScreenSaver *screenSaver_;
    static int wdFD;
    static int checkTime;
    static int dummy;
#endif

};

#endif // ICPANELCONTROLLER_H

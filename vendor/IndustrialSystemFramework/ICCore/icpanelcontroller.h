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


signals:
    void screenSave();
    void screenRestore();
    void LoadMessage(const QString&);
    void moldChanged();
    void needToInitHost();
//    void focusChanged(QWidget *old, QWidget* now);

public slots:

protected:
    QScopedPointer<ICMoldBase> mold_;
    QScopedPointer<ICMachineConfig> machineConfigs_;
    ICVirtualHostPtr host_;
    mutable QScriptValue getConfigRange_;
    QScriptEngine engine_;
    ICAddrWrapperValuePairList moldFncModifyCache_;
    ICAddrWrapperValuePairList machineConfigModifyCache_;

private:
    ICLog* logger_;
    QSettings customSettings_;
    QtQuick1ApplicationViewer *mainView_;
    ICVirtualKeyboard virtualKeyboard;
#ifdef Q_WS_QWS
    static int wdFD;
    static int checkTime;
    static int dummy;
#endif

};

#endif // ICPANELCONTROLLER_H

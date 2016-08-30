#ifndef ICPANELCONTROLLER_H
#define ICPANELCONTROLLER_H

#include <QObject>
#include <QSplashScreen>
#include <QSettings>
#include <QDir>

#include <QProgressBar>
#include <QLabel>
#include <QMouseEvent>

#include "iclog.h"
#include "qtquick1applicationviewer.h"

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

signals:
    void screenSave();
    void screenRestore();
    void LoadMessage(const QString&);

public slots:

private:
    ICLog* logger_;
    QSettings customSettings_;
    QtQuick1ApplicationViewer *mainView_;
#ifdef Q_WS_QWS
    static int wdFD;
    static int checkTime;
    static int dummy;
#endif

};

#endif // ICPANELCONTROLLER_H

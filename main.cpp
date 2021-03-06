#include <QApplication>
#include <QDir>
#include <QDebug>
#include <QIcon>
#include <QFile>
#include <QDeclarativeComponent>
#include "iclog.h"
#include "icappsettings.h"
#include "icpanelimmcontroller.h"
#include "icaxis.h"
#include "ictemperaturecurve.h"
#include "icinjectcurve.h"

ICLog iclog("RobotPanel.debuglog", 1024 * 1024);

#ifdef QT5
void appMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    iclog.MessageOutput(type, msg.toUtf8());
}
#else
void appMessageOutput(QtMsgType type, const char *msg)
{
    iclog.MessageOutput(type, msg);
}
#endif

int main(int argc, char *argv[])
{
//    iclog.SetMaxSpace(10*1024);
    iclog.Log("App Run");
#ifdef QT5
    qInstallMessageHandler(appMessageOutput);
#else
    qInstallMsgHandler(appMessageOutput);
#endif
    qmlRegisterType<ICAxis>("Extentuis", 1, 0, "ICAxis");
    qmlRegisterType<ICTemperatureCurve>("Extentuis", 1, 0, "ICTemperatureCurve");
    qmlRegisterType<ICInjectCurve>("Extentuis", 1, 0, "ICInjectCurve");
    QApplication app(argc, argv);
    app.setOrganizationName("SZHC");
    app.setApplicationName("IMMPanel");
    app.setWindowIcon(QPixmap(":/resources/logo_icon.png"));

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
    appDir.cd("images");

    qDebug()<<appDir.exists("startup_page.png");
    QPixmap splashPixmap(appDir.filePath("startup_page.png"));
    QString sw = SW_VER;
    appDir.cdUp();
    if(appDir.exists("settingpages/maintainPage.qml"))
    {
        QFile f(appDir.absoluteFilePath("settingpages/maintainPage.qml"));
        if(f.open(QFile::ReadOnly))
        {
            QString content  = f.readAll();
            f.close();
            QStringList lines = content.split("\n");
            for(int i = 0; i < lines.size(); ++i)
            {
                if(lines.at(i).contains("UI Version:"))
                {
                    QString l = lines.at(i);
                    int beginIndex = -1;
                    for(int j = 0; j < l.size(); ++j)
                    {
                        if(l.at(j) == '+')
                        {
                            if(beginIndex >= 0)
                            {
                                QString ver = l.mid(beginIndex + 1, j - beginIndex - 1);
                                sw = ver.replace("\"","").trimmed() + "_" + sw;
                            }
                            else
                                beginIndex = j;
                        }
                    }
                }
            }
        }
    }
    ICSplashScreen *splash= new ICSplashScreen(splashPixmap, sw);
    splash->SetRange(0, 7);
    splash->show();
    ICPanelIMMController controller(splash, &iclog);
    controller.Init();
#ifndef QT5
    splash->finish(controller.MainView());
#endif
    delete splash;

    return app.exec();
}

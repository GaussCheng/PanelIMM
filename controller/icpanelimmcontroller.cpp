#include "icpanelimmcontroller.h"

#include <QSqlDatabase>
#include <QMessageBox>
#include <QDebug>

#include "icappsettings.h"

ICPanelIMMController::ICPanelIMMController(QSplashScreen* splash, ICLog* logger, QObject *parent) :
    ICPanelController(splash, logger, parent)
{
}

void ICPanelIMMController::Init()
{
    ICAppSettings();
    InitDatabase_();
    emit LoadMessage("Database inited.");
//    InitMold_();
//    emit LoadMessage("Record inited.");
//    InitMachineConfig_();
//    emit LoadMessage("Machine configs inited.");

    //    host_->SetCommunicateDebug(true);
//#ifdef COMM_DEBUG
//    host_->SetCommunicateDebug(true);
//    //    OnNeedToInitHost();
//#endif
    //    InitMainView();
//    qApp->installTranslator(&translator);
//    qApp->installTranslator(&panelRoboTranslator_);
    LoadTranslator_(ICAppSettings().TranslatorName());

//    ICRobotMold::CurrentMold()->LoadMold(ICAppSettings().CurrentMoldConfig(), true);

    emit LoadMessage("Record reload.");

    //    InitUI();
    //    emit LoadMessage("Ui inited.");
    //        LoadTranslator_("HAMOUI_zh_CN.qm");
}

void ICPanelIMMController::InitDatabase_()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("RobotDatabase");
    if(!db.isValid())
    {
        qCritical("Open Database fail!!");
        QMessageBox::critical(NULL, QT_TR_NOOP("Error"), QT_TR_NOOP("Database is error!!"));
    }
    if(!db.open())
    {
        qCritical("Open Database fail!!");
        QMessageBox::critical(NULL, QT_TR_NOOP("Error"), QT_TR_NOOP("Open Database fail!!"));
    }
}

bool ICPanelIMMController::LoadTranslator_(const QString &name)
{
    QDir qml(ICAppSettings::QMLPath);
#ifdef Q_WS_QWS
    qml.cdUp();
#endif
    qml.cd(ICAppSettings().UIMainName());
    if(!qml.exists("translations"))
    {
        InitMainView();
        return false;
    }
    qml.cd("translations");
    if(!qml.exists(name))
    {
        InitMainView();
        return false;
    }
//    bool ret = translator.load(qml.filePath(name));
//    QString language = getCustomSettings("Language", "CN");
//    if(language == "CN")
//        panelRoboTranslator_.load(":/PanelRobot_zh_CN.qm");
//    else
//        panelRoboTranslator_.load(":/PanelRobot_en_US.qm");
    InitMainView();
    return true;
}

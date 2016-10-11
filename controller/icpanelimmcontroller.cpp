#include "icpanelimmcontroller.h"

#include <QSqlDatabase>
#include <QMessageBox>
#include <qmath.h>


#include "icdalhelper.h"
#include "icappsettings.h"
#include "icimmmold.h"
#include "parser.h"
#include "icinjectionmachinehost.h"
#include <QDebug>

ICPanelIMMController::ICPanelIMMController(QSplashScreen* splash, ICLog* logger, QObject *parent) :
    ICPanelController(splash, logger, parent)
{
    mold_.reset(new ICIMMMold());
    machineConfigs_.reset(new ICMachineConfig());
    host_ = ICVirtualHostManager::GetVirtualHost<ICInjectionMachineHost>(1);
    ICAppSettings settings;
    QString uiMain = settings.UIMainName();

    QString scriptFileName(QString("%1/configs/ConfigDefines.js").arg(uiMain));
    QFile scriptFile(scriptFileName);
    scriptFile.open(QIODevice::ReadOnly);
    QString scriptContent = scriptFile.readAll();
    scriptFile.close();
    scriptContent = scriptContent.remove(0, sizeof(".pragma library"));
    engine_.evaluate(scriptContent, scriptFileName);
    //    qDebug()<<"PanelrobotController Init:"<<engine_.hasUncaughtException();
    getConfigRange_ = engine_.evaluate("getConfigRange");
}

void ICPanelIMMController::Init()
{
    ICAppSettings();
    InitDatabase_();
    emit LoadMessage("Database inited.");
    InitMold_();
    emit LoadMessage("Record inited.");
    InitMachineConfig_();
    emit LoadMessage("Machine configs inited.");

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

void ICPanelIMMController::InitMold_()
{
    ICAppSettings as;
    mold_->LoadMold(as.CurrentMoldConfig());
}

void ICPanelIMMController::InitMachineConfig_()
{
    ICSuperSettings as;
    machineConfigs_->LoadMachineConfig(as.CurrentSystemConfig());
    //    OnNeedToInitHost();
}

void ICPanelIMMController::OnNeedToInitHost()
{

//    ICRobotVirtualhost::SendMoldCountersDef(host_, mold->CountersToHost());
//    ICRobotVirtualhost::SendMold(host_, mold->ProgramToDataBuffer(ICRobotMold::kMainProg));

    QVector<QPair<int, quint32> > toHost = mold_->BareMachineConfigs().toVector();
    toHost += machineConfigs_->BareMachineConfigs().toVector();
    host_->InitConfigs(toHost);
//    ICRobotVirtualhost::InitMachineConfig(host_,machineConfig->BareMachineConfigs());
    emit needToInitHost();
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

QString ICPanelIMMController::newRecord(const QString &name, const QString &defaultFncValue)
{
    ICMoldInfo mi;
    mi.name = name;
    QJson::Parser p;
    bool ok;
    QVariantMap dv = p.parse(defaultFncValue.toLatin1(), &ok).toMap();
    if(ok)
    {
        ICParametersCache pc;
        QVariantMap::ConstIterator i = dv.constBegin();
        while(i != dv.constEnd())
        {
            ICAddrWrapperCPTR cptr = ICAddrWrapper::AddrStringToAddr(i.key());
            pc.UpdateConfigValue(cptr, static_cast<quint32>(i.value().toDouble() * qPow(10, cptr->Decimal())));
            ++i;
        }
        mi.values = pc.ToPairList();
    }
    return mold_->NewRecord(mi).toJSON();
}

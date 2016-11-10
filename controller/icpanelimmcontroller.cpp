#include "icpanelimmcontroller.h"

#include <QSqlDatabase>
#include <QMessageBox>
#include <qmath.h>


#include "icdalhelper.h"
#include "icappsettings.h"
#include "icimmmold.h"
#include "parser.h"
#include "icinjectionmachinehost.h"
#include "ictemperaturesampling.h"
#include <QDebug>

ICPanelIMMController::ICPanelIMMController(QSplashScreen* splash, ICLog* logger, QObject *parent) :
    ICPanelController(splash, logger, parent)
{
    mold_.reset(new ICIMMMold());
    machineConfigs_.reset(new ICMachineConfig());
    host_ = ICVirtualHostManager::GetVirtualHost<ICInjectionMachineHost>(1);
    host_->SetCommunicateDebug(false);
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

    fEInput_.SetNLRange(-500, -100);
    fEInput_.SetNMRange(-150, -50);
    fEInput_.SetNSRange(-100, 0);
    fEInput_.SetZORange(-50, 5);
    fEInput_.SetPSRange(0, 10);
    fEInput_.SetPMRange(5, 15);
    fEInput_.SetPLRange(10, 20);
    fDEInput_.SetNLRange(-3, -1.5);
    fDEInput_.SetNMRange(-2, -0.5);
    fDEInput_.SetNSRange(-1.5, 1);
    fDEInput_.SetZORange(-0.5, 1.5);
    fDEInput_.SetPSRange(0, 2);
    fDEInput_.SetPMRange(1.5, 2.5);
    fDEInput_.SetPLRange(2, 3);
    fOutput_.SetNLRange(0, 0);
    fOutput_.SetNMRange(0, 0.5);
    fOutput_.SetNSRange(0, 1);
    fOutput_.SetZORange(1, 3);
    fOutput_.SetPSRange(3, 5);
    fOutput_.SetPMRange(4, 7);
    fOutput_.SetPLRange(5, 10);
    fuzzyController_.SetErrorFuzzification(&fEInput_);
    fuzzyController_.SetDErrorFuzzification(&fDEInput_);
    fuzzyController_.SetOutputFuzzification(&fOutput_);
    pidEnAddrs_ <<&s_rw_25_1_0_481
               <<&s_rw_26_1_0_481
              <<&s_rw_27_1_0_481
             <<&s_rw_28_1_0_481
            <<&s_rw_29_1_0_481
           <<&s_rw_30_1_0_481;
    tempSettingAddrs_ <<&m_rw_16_16_0_462
                     <<&m_rw_0_16_0_463
                    <<&m_rw_16_16_0_463
                   <<&m_rw_0_16_0_464
                  <<&m_rw_16_16_0_464
                 <<&m_rw_0_16_0_465;
    tempHoldSettingAddrs_<<&m_rw_16_16_0_466
                        <<&m_rw_0_16_0_467
                       <<&m_rw_16_16_0_467
                      <<&m_rw_0_16_0_468
                     <<&m_rw_16_16_0_468
                    <<&m_rw_0_16_0_469;
    lowSettingAddrs_ <<&m_rw_16_16_0_474
                    <<&m_rw_0_16_0_475
                   <<&m_rw_16_16_0_475
                  <<&m_rw_0_16_0_476
                 <<&m_rw_16_16_0_476
                <<&m_rw_0_16_0_477;
    speedSettingAddrs_ <<&s_rw_16_16_0_490
                      <<&s_rw_0_16_0_491
                     <<&s_rw_16_16_0_491
                    <<&s_rw_0_16_0_492
                   <<&s_rw_16_16_0_492
                  <<&s_rw_0_16_0_493;
    pAddrs_ <<&s_rw_16_16_0_478
           <<&s_rw_0_16_0_479
          <<&s_rw_16_16_0_479
         <<&s_rw_0_16_0_480
        <<&s_rw_16_16_0_480
       <<&s_rw_0_16_0_481;
    iAddrs_ <<&s_rw_16_16_0_482
           <<&s_rw_0_16_0_483
          <<&s_rw_16_16_0_483
         <<&s_rw_0_16_0_484
        <<&s_rw_16_16_0_484
       <<&s_rw_0_16_0_485;
    dAddrs_ <<&s_rw_16_16_0_486
           <<&s_rw_0_16_0_487
          <<&s_rw_16_16_0_487
         <<&s_rw_0_16_0_488
        <<&s_rw_16_16_0_488
       <<&s_rw_0_16_0_489;
    //    seg1Proportion_ = 1;
    //    memset(seg2To7Proportions_, 1, sizeof(double) * 6);
    for(int i = 0; i != 7; ++i)
    {
        speedFactors_[i] = 1;
        itermFactors_[i] = 1;
    }
    ICTemperatureSampling::Init();
    QTimer::singleShot(machineConfigs_->MachineConfig(&s_rw_16_8_0_481) * 1000, this, SLOT(Seg2To7FuzzyPID()));
    QTimer::singleShot(mold_->MoldFnc(&m_rw_0_10_1_498) / 10.0, this, SLOT(Seg1FuzzyPID()));
//    ICAppSettings::SetStartupTime(QTime::currentTime());
    //    temperatureTimerID_ = ICTimerPool::Instance()->Start(1000, this, SLOT(TemperatureSampling()));
    connect(&tempTimer_,
            SIGNAL(timeout()),
            SLOT(TemperatureSampling()));
    tempTimer_.start(1000);

    connect(host_.data(), SIGNAL(cycleFlagChanged(bool)), SLOT(OnCycleFlagChanged(bool)));

    host_->SetCommunicateInterval(25);
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
    OnNeedToInitHost();


    //    host_->SetCommunicateDebug(true);
//#ifdef COMM_DEBUG
//    host_->SetCommunicateDebug(true);
//    //    OnNeedToInitHost();
//#endif
    //    InitMainView();
    qApp->installTranslator(&translator_);
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
    bool ret = translator_.load(qml.filePath(name));
//    QString language = getCustomSettings("Language", "CN");
//    if(language == "CN")
//        panelRoboTranslator_.load(":/PanelRobot_zh_CN.qm");
//    else
//        panelRoboTranslator_.load(":/PanelRobot_en_US.qm");
    InitMainView();
    return ret;
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

static ICAddrWrapperList tempAddrs =
        ICAddrWrapperList()<<&c_ro_0_16_1_1570<<&c_ro_16_16_1_1570<<&c_ro_0_16_1_1571
                          <<&c_ro_16_16_1_1571<<&c_ro_0_16_1_1572<<&c_ro_16_16_1_1572
                         <<&c_ro_0_16_1_1573<<&c_ro_16_16_1_1573;

void ICPanelIMMController::TemperatureSampling()
{
    //    int tmpAddr;
    for(int i = 0; i != ICTemperatureSampling::SEG_NUM; ++i)
    {
        //        tmpAddr = ICAddr_Read_NozzleActualTemp + i;
        if(host_->HostStatusValue(tempAddrs.at(i)) != TEMPERATURENULL)
        {
            ICTemperatureSampling::AddSample(i, host_->HostStatusValue(tempAddrs.at(i)) / 10.0 );
        }
    }
    ICTemperatureSampling::TimeSample(1);
}

void ICPanelIMMController::Seg2To7FuzzyPID()
{
#ifdef TEST_TIME_DEBUG
    /*TIME_TEST*/
    QTime time;
    time.start();
#endif

    int cycleTime = machineConfigs_->MachineConfig(&s_rw_16_8_0_481);
    //    int cycleTime = 8;
    if(cycleTime < 8)
    {
        cycleTime = 8;
    }
    if(!ICInjectionMachineHost::IsHostHeating(host_->HostStatusValue(&c_ro_15_1_0_1537)))
    {
        QTimer::singleShot( cycleTime * 1000, this, SLOT(Seg2To7FuzzyPID()));
        return;
    }
    int tmpSize = pidEnAddrs_.size();
    pidEnVars_.clear();
    tempSettingVars_.clear();
    lowSettingVars_.clear();
    speedSettingVars_.clear();
    int heatMode = mold_->MoldFnc(&m_rw_24_4_0_498);
    if(heatMode == 1 || heatMode == 4)
    {
        for(int i = 0; i != tmpSize; ++i)
        {
            pidEnVars_.append(machineConfigs_->MachineConfig(pidEnAddrs_.at(i)));
            tempSettingVars_.append(mold_->MoldFnc(tempSettingAddrs_.at(i)));
            lowSettingVars_.append(mold_->MoldFnc(lowSettingAddrs_.at(i)));
            speedSettingVars_.append(machineConfigs_->MachineConfig(speedSettingAddrs_.at(i)));
        }
    }
    else
    {
        for(int i = 0; i != tmpSize; ++i)
        {
            pidEnVars_.append(machineConfigs_->MachineConfig(pidEnAddrs_.at(i)));
            tempSettingVars_.append(mold_->MoldFnc(tempHoldSettingAddrs_.at(i)));
            lowSettingVars_.append(mold_->MoldFnc(lowSettingAddrs_.at(i)));
            speedSettingVars_.append(machineConfigs_->MachineConfig(speedSettingAddrs_.at(i)));
        }
    }

    double range = cycleTime / 60.0;
    double rangeM2 = range + range;
    double rangeM3 = range + rangeM2;
    double rangeM4 = rangeM2 + rangeM2;
    double rangeM5 = rangeM2 + rangeM3;
    double rangeM6 = rangeM3 + rangeM3;
    double rangeM7 = rangeM3 + rangeM4;
    //    double rangeM8 = rangeM4 + rangeM4;
    fOutput_.SetNMRange(0, rangeM2);
    fOutput_.SetNSRange(range, rangeM3);
    fOutput_.SetZORange(rangeM2, rangeM4);
    fOutput_.SetPSRange(rangeM3, rangeM5);
    fOutput_.SetPMRange(rangeM4, rangeM6);
    fOutput_.SetPLRange(rangeM5, rangeM7);
    uint temp;
    double lastErr;
    double dErr;
    double ddErr;
    double dErrLimit = 0;
    for(int i = 0; i != pidEnVars_.size(); ++i)
    {
        if(pidEnVars_.at(i) == 1 && tempSettingVars_.at(i) != TEMPERATURENULL)
        {
            lastErr = ICTemperatureSampling::LastSample(i + 1) - tempSettingVars_.at(i);
            dErr = ICTemperatureSampling::DError(i + 1, cycleTime);
            ddErr = ICTemperatureSampling::DDError(i + 1, cycleTime);
            qDebug()<<"DErr"<<dErr;
            qDebug()<<"DDErr"<<ddErr;
            //            if(lastErr < -1 && dErr <= 0 && ddErr >= dErr)  // used policy
            dErrLimit = qAbs(lastErr) / 20;
            if(lastErr < -1 && (dErr <= dErrLimit && ddErr >= dErr))
            {
                //                speedFactor = cycleTime * qAbs(lastErr) / qAbs(dErr);
                speedFactors_[i + 1] += 0.1;
                if((ICTemperatureSampling::LastSample(i + 1) >= (tempSettingVars_.at(i) * 0.8))/* &&
                                                        lastErr <= -15*/)
                {
                    itermFactors_[i + 1] += qAbs(lastErr) / 20.0;
                }

            }
            else
            {
                if((speedFactors_[i + 1] > 1) || (dErr >= 3 && lastErr >= -30))
                {
                    speedFactors_[i + 1] -= 0.1;
                }
                else if(speedFactors_[i + 1] < 1 && dErr < 3)
                {
                    speedFactors_[i + 1] += 0.1;
                }
                if(lastErr >= 2)
                {
                    itermFactors_[i + 1] -= qAbs(lastErr) / 10;
                }
                else if(itermFactors_[i + 1] > 1 || (dErr >= 3 && lastErr >= -15))
                {
                    itermFactors_[i + 1] -= qAbs(lastErr) / 30.0;
                }
                else if(itermFactors_[i + 1] < 1 && dErr < 3)
                {
                    itermFactors_[i + 1] += qAbs(lastErr) / 30.0;
                }
            }
            if(speedFactors_[i + 1] < 0)
            {
                speedFactors_[i + 1] = 0;
            }
            if(itermFactors_[i + 1] < 0)
            {
                itermFactors_[i + 1] = 0;
            }
            qDebug()<<"Speed Factor"<<speedFactors_[i + 1];
            qDebug()<<"Iterm Factor"<<itermFactors_[i + 1];
            qDebug()<<"LastErr:"<<lastErr;
            fuzzyController_.SetFuzzyRules(&pRules_);
            //            temp = speedFactor + (fuzzyController_.CalOutput(lastErr, dErr) * 500 * piFactor);
            if(qAbs(lastErr) <= 5)
            {
                temp = qCeil(fuzzyController_.CalOutput(lastErr, dErr) * 2000 * speedFactors_[i + 1]);
            }
            else
            {
                temp = qCeil(fuzzyController_.CalOutput(lastErr, dErr) * 20 * speedFactors_[i + 1]) * speedSettingVars_.at(i);
            }
            qDebug()<<"P"<<i + 1<<":"<<temp;
            //            uint baseV = ICConfigsCache::OriginConfigValue(pAddrs_.at(i));
            //            ICAddrWrapper::UpdateBaseAddrValue(pAddrs_.at(i), temp, &baseV);
            ICInjectionMachineHost::AddWriteConfigCommunicationFrame(host_,
                                                                     pAddrs_.at(i)->BaseAddr(),
                                                                     machineConfigs_->MachineConfig(pAddrs_.at(i), temp));
            fuzzyController_.SetFuzzyRules(&iRules_);
            //            temp = fuzzyController_.CalOutput(lastErr, dErr) * 1000 / piFactor;
            temp = qCeil(fuzzyController_.CalOutput(lastErr, dErr) * 3 * itermFactors_[i + 1]);
            //            baseV = ICConfigsCache::OriginConfigValue(iAddrs_.at(i));
            //            ICAddrWrapper::UpdateBaseAddrValue(iAddrs_.at(i), temp, &baseV);
            ICInjectionMachineHost::AddWriteConfigCommunicationFrame(host_,
                                                                     iAddrs_.at(i)->BaseAddr(),
                                                                     machineConfigs_->MachineConfig(iAddrs_.at(i),temp));
            qDebug()<<"I"<<i + 1<<":"<<temp;
            fuzzyController_.SetFuzzyRules(&dRules_);
            temp = fuzzyController_.CalOutput(lastErr, dErr) * 50000;
            //            baseV = ICConfigsCache::OriginConfigValue(dAddrs_.at(i));
            //            ICAddrWrapper::UpdateBaseAddrValue(dAddrs_.at(i), temp, &baseV);
            ICInjectionMachineHost::AddWriteConfigCommunicationFrame(host_,
                                                                     dAddrs_.at(i)->BaseAddr(),
                                                                     machineConfigs_->MachineConfig(dAddrs_.at(i), temp));
            qDebug()<<"D"<<i + 1<<":"<<temp;

        }
    }
#ifdef TEST_TIME_DEBUG
    /*TIME_TEST*/
    if(time.elapsed() >= TEST_TIME_LEVEL)
    {
        qDebug()<<"Seg2To7FuzzyPID time test"<<time.restart()<<"ms";
    }
#endif
    QTimer::singleShot( cycleTime * 1000, this, SLOT(Seg2To7FuzzyPID()));
}

void ICPanelIMMController::Seg1FuzzyPID()
{
#ifdef TEST_TIME_DEBUG
    /*TIME_TEST*/
    QTime time;
    time.start();
#endif
    double cycleTime = mold_->MoldFnc(&m_rw_0_10_1_498) / 10.0;
    //   double  cycleTime = 2;
    if(cycleTime < 2)
    {
        cycleTime = 2;
    }
    if(!ICInjectionMachineHost::IsHostHeating(host_->HostStatusValue(&c_ro_15_1_0_1537)))
    {
        QTimer::singleShot(cycleTime * 1000, this, SLOT(Seg1FuzzyPID()));
        return;
    }
    double range = cycleTime / 60.0;
    double rangeM2 = range + range;
    double rangeM3 = range + rangeM2;
    double rangeM4 = rangeM2 + rangeM2;
    double rangeM5 = rangeM2 + rangeM3;
    double rangeM6 = rangeM3 + rangeM3;
    double rangeM7 = rangeM3 + rangeM4;
    fOutput_.SetNMRange(0, rangeM2);
    fOutput_.SetNSRange(range, rangeM3);
    fOutput_.SetZORange(rangeM2, rangeM4);
    fOutput_.SetPSRange(rangeM3, rangeM5);
    fOutput_.SetPMRange(rangeM4, rangeM6);
    fOutput_.SetPLRange(rangeM5, rangeM7);
    bool isEn = machineConfigs_->MachineConfig(&s_rw_24_1_0_481);
    int heatMode = mold_->MoldFnc(&m_rw_24_4_0_498);
    int settingVar = (heatMode == 1 || heatMode == 4)? mold_->MoldFnc(&m_rw_0_16_0_462)
                                                     : mold_->MoldFnc(&m_rw_0_16_0_466);
    //    bool isEn = false;
    //    int settingVar = 0;
    if(isEn && settingVar != TEMPERATURENULL )
    {
        double lastErr = ICTemperatureSampling::LastSample(0) - settingVar;
        double dErr = ICTemperatureSampling::DError(0, qRound(cycleTime));
        double ddErr = ICTemperatureSampling::DDError(0, qRound(cycleTime));
        uint temp;
        qDebug()<<"DErr"<<dErr;
        qDebug()<<"DDErr"<<ddErr;
        double dErrLimit = 0;
        dErrLimit = qAbs(lastErr) / 20;
        if(lastErr < -1 && dErr <= dErrLimit && ddErr >= dErr)  // used policy
            //        if(lastErr < -1 && dErr <= 0 && ddErr >= 0)
        {
            //                speedFactor = cycleTime * qAbs(lastErr) / qAbs(dErr);
            speedFactors_[0] += 0.1;
            if((ICTemperatureSampling::LastSample(0) >= (settingVar * 0.8))/* &&
                                                    lastErr <= -15*/)
            {
                itermFactors_[0] += qAbs(lastErr) / 20.0;
            }

        }
        else
        {
            if((speedFactors_[0] > 1) || (dErr >= 3 && lastErr >= -30))
            {
                speedFactors_[0] -= 0.1;
            }
            else if(speedFactors_[0] < 1 && dErr < 3)
            {
                speedFactors_[0] += 0.1;
            }
            if(lastErr >= 2)
            {
                itermFactors_[0] -= qAbs(lastErr) / 10;
            }
            else if(itermFactors_[0] > 1 || (dErr >= 3 && lastErr >= -15))
            {
                itermFactors_[0] -= qAbs(lastErr) / 30.0;
            }
            else if(itermFactors_[0] < 1 && dErr < 3)
            {
                itermFactors_[0] += qAbs(lastErr) / 30.0;
            }
        }
        if(speedFactors_[0] < 0)
        {
            speedFactors_[0] = 0;
        }
        if(itermFactors_[0] < 0)
        {
            itermFactors_[0] = 0;
        }
        qDebug()<<"Seg1 Speed Factor"<<speedFactors_[0];
        fuzzyController_.SetFuzzyRules(&pRules_);
        //        temp = speedFactor + (fuzzyController_.CalOutput(lastErr, dErr) * 600 * piFactor);
        if(qAbs(lastErr) <= 5)
        {
            temp = fuzzyController_.CalOutput(lastErr, dErr) * 2000 * speedFactors_[0];
        }
        else
        {
            temp = fuzzyController_.CalOutput(lastErr, dErr) * 20 * speedFactors_[0] * machineConfigs_->MachineConfig(&s_rw_0_16_0_490);
        }
        qDebug()<<"Seg1 P:"<<temp;
        //        uint baseV = ICConfigsCache::OriginConfigValue(&s_rw_0_16_478);
        //        ICAddrWrapper::UpdateBaseAddrValue(&s_rw_0_16_478, temp, &baseV);
        if(temp > 65535) temp = 65535;
        ICInjectionMachineHost::AddWriteConfigCommunicationFrame(host_,
                                                                 s_rw_0_16_0_478.BaseAddr(),
                                                                 machineConfigs_->MachineConfig(&s_rw_0_16_0_478, temp));
        fuzzyController_.SetFuzzyRules(&iRules_);
        //        temp = fuzzyController_.CalOutput(lastErr, dErr) * (1000 / piFactor);
        temp = fuzzyController_.CalOutput(lastErr, dErr) * 3 * itermFactors_[0];
        //        baseV = ICConfigsCache::OriginConfigValue(&s_rw_0_16_482);
        //        ICAddrWrapper::UpdateBaseAddrValue(&s_rw_0_16_482, temp, &baseV);
        if(temp > 65535) temp = 65535;
        ICInjectionMachineHost::AddWriteConfigCommunicationFrame(host_,
                                                                 s_rw_0_16_0_482.BaseAddr(),
                                                                 machineConfigs_->MachineConfig(&s_rw_0_16_0_482, temp));
        qDebug()<<"Seg1 I:"<<temp;
        fuzzyController_.SetFuzzyRules(&dRules_);
        temp = fuzzyController_.CalOutput(lastErr, dErr) * 50000;
        //        baseV = ICConfigsCache::OriginConfigValue(&s_rw_0_16_486);
        //        ICAddrWrapper::UpdateBaseAddrValue(&s_rw_0_16_486, temp, &baseV);
        if(temp > 65535) temp = 65535;
        ICInjectionMachineHost::AddWriteConfigCommunicationFrame(host_,
                                                                 s_rw_0_16_0_486.BaseAddr(),
                                                                 machineConfigs_->MachineConfig(&s_rw_0_16_0_486, temp));
        qDebug()<<"Seg1 D:"<<temp;
    }
    QTimer::singleShot(cycleTime * 1000, this, SLOT(Seg1FuzzyPID()));
#ifdef TEST_TIME_DEBUG
    /*TIME_TEST*/
    if(time.elapsed() >= TEST_TIME_LEVEL)
    {
        qDebug()<<"Seg1FuzzyPID time test"<<time.restart()<<"ms";
    }
#endif
}

QString ICPanelIMMController::alarms() const
{
    QBitArray als = host_->Alarms();
    if(alarms_ != als)
    {
        alarmsBitStr_.clear();
        alarms_ = als;
        for(int i = 0; i < als.size(); ++i)
        {
            alarmsBitStr_.append(als.at(i) ? '1':'0');
        }
    }
    return alarmsBitStr_;

}

void ICPanelIMMController::sendKeyCommand(int key)
{
    ICInjectionMachineHost::AddActionCommunicationFrame(host_, key);
}


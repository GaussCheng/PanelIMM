#ifndef ICPANELIMMCONTROLLER_H
#define ICPANELIMMCONTROLLER_H
#include "icpanelcontroller.h"
#include "icconfigsaddr.h"
#include "icfuzzycontroller.h"
#include "ictriangularfuzzification.h"
#include "ictemperatureproportionrules.h"
#include "ictemperatureintegralrules.h"
#include "ictemperaturedifferentialrules.h"

class ICPanelIMMController : public ICPanelController
{
    Q_OBJECT
public:
    explicit ICPanelIMMController(QSplashScreen* splash, ICLog* logger = NULL, QObject *parent = 0);
    void Init();

    Q_INVOKABLE QString newRecord(const QString& name, const QString& defaultFncValue);

    Q_INVOKABLE quint32 iStatus(int boardID) const  { return host_->HostStatusValue(&c_ro_0_32_0_1538);}
    Q_INVOKABLE quint32 oStatus(int boardID) const { return host_->HostStatusValue(&c_ro_0_32_0_1539);}

signals:

public slots:
    void OnNeedToInitHost();
    void TemperatureSampling();
    void Seg2To7FuzzyPID();
    void Seg1FuzzyPID();

private:
    void InitMold_();
    void InitMachineConfig_();
    void InitDatabase_();
    bool LoadTranslator_(const QString& name);

private:
    ICFuzzyController fuzzyController_;
    ICTriangularFuzzification fEInput_;
    ICTriangularFuzzification fDEInput_;
    ICTriangularFuzzification fOutput_;
    ICTemperatureProportionRules pRules_;
    ICTemperatureIntegralRules iRules_;
    ICTemperatureDifferentialRules dRules_;
    QList<const ICAddrWrapper*> pidEnAddrs_;
    QList<uint> pidEnVars_;
    QList<const ICAddrWrapper*> pAddrs_;
    QList<const ICAddrWrapper*> iAddrs_;
    QList<const ICAddrWrapper*> dAddrs_;
    QList<const ICAddrWrapper*> tempSettingAddrs_;
    QList<const ICAddrWrapper*> tempHoldSettingAddrs_;
    QList<uint> tempSettingVars_;
    QList<const ICAddrWrapper*> lowSettingAddrs_;
    QList<uint> lowSettingVars_;
    QList<const ICAddrWrapper*> speedSettingAddrs_;
    QList<uint> speedSettingVars_;
    double speedFactors_[7];
    double itermFactors_[7];
    QTimer tempTimer_;

};

#endif // ICPANELIMMCONTROLLER_H

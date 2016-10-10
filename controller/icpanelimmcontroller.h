#ifndef ICPANELIMMCONTROLLER_H
#define ICPANELIMMCONTROLLER_H
#include "icpanelcontroller.h"
#include "icconfigsaddr.h"

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

private:
    void InitMold_();
    void InitMachineConfig_();
    void InitDatabase_();
    bool LoadTranslator_(const QString& name);

};

#endif // ICPANELIMMCONTROLLER_H

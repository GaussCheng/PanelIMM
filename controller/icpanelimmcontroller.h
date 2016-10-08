#ifndef ICPANELIMMCONTROLLER_H
#define ICPANELIMMCONTROLLER_H
#include "icpanelcontroller.h"

class ICPanelIMMController : public ICPanelController
{
    Q_OBJECT
public:
    explicit ICPanelIMMController(QSplashScreen* splash, ICLog* logger = NULL, QObject *parent = 0);
    void Init();

    Q_INVOKABLE QString newRecord(const QString& name, const QString& defaultFncValue);



signals:

public slots:

private:
    void InitMold_();
    void InitDatabase_();
    bool LoadTranslator_(const QString& name);

};

#endif // ICPANELIMMCONTROLLER_H

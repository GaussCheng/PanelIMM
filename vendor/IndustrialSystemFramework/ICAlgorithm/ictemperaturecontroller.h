#ifndef ICTEMPERATURECONTROLLER_H
#define ICTEMPERATURECONTROLLER_H
#include "icfuzzycontroller.h"
#include "ictriangularfuzzification.h"
#include "ictemperaturedifferentialrules.h"
#include "ictemperatureintegralrules.h"
#include "ictemperatureproportionrules.h"
#include "iccyclearray.h"

#include <QObject>
#include <QTimer>

typedef void (*GetTempSetting) ();
typedef double (*GetCurrentTemp) ();


class ICTemperatureController:public QObject
{
    Q_OBJECT
public:
    ICTemperatureController();
    int CycleTime() const { return cycleTime_;}
    void SetCycleTime(int cycleTime)
    {
        cycleTime_ = cycleTime;
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
    }
    void Start();
    void StartSample(int time);
    void Pause();

    void BindGetTempSetting(GetTempSetting ts) { gts_ = ts;}
    void BindGetCurrentTemp(GetCurrentTemp cs) { gcs_ = cs;}

    void AddSample(double sample);/* {tempSamplesTable_[seg].Add(sample);}*/
    void TimeSample(double interval);


signals:
    void PIDCalced(int p, int i, int d);

private slots:
    void Calc_();
    void Sample_();
private:
    ICFuzzyController fuzzyController_;
    ICTriangularFuzzification fEInput_;
    ICTriangularFuzzification fDEInput_;
    ICTriangularFuzzification fOutput_;
    ICTemperatureProportionRules pRules_;
    ICTemperatureIntegralRules iRules_;
    ICTemperatureDifferentialRules dRules_;
    int cycleTime_;
    int state_;
    const static int SAMPLES_COUNT = 7200;
    ICCycleArray<double, SAMPLES_COUNT> tempSamplesTable_;
    double tempRawDatas_[SAMPLES_COUNT];
    QVarLengthArray<double, SAMPLES_COUNT> timeData_;
    double timeRawData_[SAMPLES_COUNT];
    QTimer sampleTimer_;
    GetTempSetting gts_;
    GetCurrentTemp gcs_;
    int exceptionValueCount_;
};

#endif // ICTEMPERATURECONTROLLER_H

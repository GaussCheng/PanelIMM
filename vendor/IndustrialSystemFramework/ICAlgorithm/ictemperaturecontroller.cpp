#include "ictemperaturecontroller.h"

ICTemperatureController::ICTemperatureController()
{
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

//    cycleTime_ = 20000;
    gcs_ = NULL;
    gts_ = NULL;
    exceptionValueCount_ = 0;
    connect(&sampleTimer_, SIGNAL(timeout()), this, SLOT(Sample_()));
    SetCycleTime(20000);
    state_ = 0;
}

void ICTemperatureController::Start()
{
    state_ = 2;
    QTimer::singleShot(cycleTime_, this, SLOT(Calc_()));
}

void ICTemperatureController::Calc_()
{
    if(state_ != 2)
    {
        QTimer::singleShot(cycleTime_, this, SLOT(Calc_()));
        return;
    }
}

void ICTemperatureController::Sample_()
{
    if(gcs_ == NULL) return;
    AddSample(gcs_());
    TimeSample(1);
}

void ICTemperatureController::StartSample(int time)
{
    sampleTimer_.start(time);
}

void ICTemperatureController::AddSample(double sample)
{
    double toAdd = tempSamplesTable_.At(tempSamplesTable_.Size() - 1);
    double derr = qAbs(sample - toAdd);
    if(derr < 2)
    {
        toAdd = sample;
        exceptionValueCount_= 0;
    }
    else
    {
        ++exceptionValueCount_;
    }
    if(exceptionValueCount_ > 3)
    {
        toAdd = sample;
        exceptionValueCount_ = 0;
    }
    tempSamplesTable_.Add(toAdd);
}

void ICTemperatureController::TimeSample(double interval)
{
    if(timeData_.isEmpty())
    {
        timeData_.append(0);
        return;
    }
    if(timeData_.size() == SAMPLES_COUNT)
    {
        for(int i = 0; i != SAMPLES_COUNT; ++i)
        {
            timeData_[i]++;
        }
    }
    else
    {
        timeData_.append(timeData_[timeData_.size() - 1] + interval);
    }
}

#include "ictemperaturesampling.h"

QVarLengthArray<ICCycleArray<double, ICTemperatureSampling::SAMPLES_COUNT>,
ICTemperatureSampling::SEG_NUM> ICTemperatureSampling::tempSamplesTable_(ICTemperatureSampling::SEG_NUM);
QVarLengthArray<double, ICTemperatureSampling::SAMPLES_COUNT> ICTemperatureSampling::timeData_(ICTemperatureSampling::SAMPLES_COUNT);
double ICTemperatureSampling::tempRawDatas_[ICTemperatureSampling::SEG_NUM][ICTemperatureSampling::SAMPLES_COUNT];
double ICTemperatureSampling::timeRawData_[ICTemperatureSampling::SAMPLES_COUNT];
ICTemperatureSampling::ICTemperatureSampling()
{
}


double* ICTemperatureSampling::SampleRawData(int seg, int beg, int size, int interval)
{
    double *rD = SampleRawData(seg, beg, size);
    if(interval <= 1)
    {
        return rD;
    }
    for(int i = 0; i < size; i += interval)
    {
        tempRawDatas_[seg][i] = rD[i];
    }
    return tempRawDatas_[seg];
}

double* ICTemperatureSampling::TimeSampleRawData(int beg, int size, int interval)
{
    double *rD = TimeSampleRawData(beg, size);
    if(interval <= 1)
    {
        return rD;
    }
    for(int i = 0; i < size; i += interval)
    {
        timeRawData_[i] = rD[i];
    }
    return timeRawData_;
}

double ICTemperatureSampling::DDError(int seg, uint delay)
{
    uint size = tempSamplesTable_.at(seg).Size();
    uint ddelay = delay << 1;
    if(size == 0)
    {
        return 0;
    }
    else if(size < delay)
    {
        return DError(seg, delay);
    }
    uint lastsample = size - delay;
    if( size < ddelay)
    {
        return GetSample(seg, lastsample) - GetSample(seg, 0);
    }
    return GetSample(seg, lastsample) - GetSample(seg, size - ddelay);

}

static int exceptionValueCount[ICTemperatureSampling::SEG_NUM] = {0};

void ICTemperatureSampling::AddSample(int seg, double sample)
{
    double toAdd = tempSamplesTable_[seg].At(tempSamplesTable_[seg].Size() - 1);
    double derr = qAbs(sample - toAdd);
//    qDebug()<<sample;
    if(derr < 2)
    {
        toAdd = sample;
        exceptionValueCount[seg] = 0;
    }
    else
    {
        ++exceptionValueCount[seg];
    }
    if(exceptionValueCount[seg] > 3)
    {
        toAdd = sample;
        exceptionValueCount[seg] = 0;
    }
    tempSamplesTable_[seg].Add(toAdd);
}

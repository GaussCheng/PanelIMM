#ifndef ICTEMPERATURESAMPLING_H
#define ICTEMPERATURESAMPLING_H

#include <cstring>
#include "iccyclearray.h"
#include <QDebug>

class ICTemperatureSampling
{
public:
    ICTemperatureSampling();
    static int SampleCount(int seg) { return tempSamplesTable_.at(seg).Size();}
    static int TimeSampleCount() { return timeData_.size();}
    static void AddSample(int seg, double sample);/* {tempSamplesTable_[seg].Add(sample);}*/
    static double GetSample(int seg, int index) { return tempSamplesTable_.at(seg).At(index);}
    static double* SampleRawData(int seg, int beg, int size);
    static double* SampleRawData(int seg, int beg, int size, int interval);
    static void TimeSample(double interval);
    static double GetTimeSample(int index) { return timeData_.at(index);}
    static double* TimeSampleRawData(int beg, int size);
    static double* TimeSampleRawData(int beg, int size, int interval);
    static void Init();
    static void ClearTemperatureSample(int seg) { tempSamplesTable_[seg].Clear();}
    static double LastSample(int seg);
    static double DError(int seg, uint delay);
    static double DDError(int seg, uint delay);
    const static int SAMPLES_COUNT = 7200;
    const static int SEG_NUM = 8;

private:
    static QVarLengthArray<ICCycleArray<double, SAMPLES_COUNT> , SEG_NUM> tempSamplesTable_;
    static double tempRawDatas_[SEG_NUM][SAMPLES_COUNT];
    static QVarLengthArray<double, SAMPLES_COUNT> timeData_;
    static double timeRawData_[SAMPLES_COUNT];
};

inline void ICTemperatureSampling::TimeSample(double interval)
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

inline void ICTemperatureSampling::Init()
{
    for ( int i = 0; i < SAMPLES_COUNT; i++ )
    {
        timeData_[i] = i;
    }
    for(int i = 0; i != SEG_NUM; ++i)
    {
        for(int j = 0; j != SAMPLES_COUNT; ++j)
        {
            tempSamplesTable_[i].Add(0);
            tempRawDatas_[i][j] = 0;
        }
    }
}

inline double* ICTemperatureSampling::TimeSampleRawData(int beg, int size)
{
    Q_UNUSED(size)
    return timeData_.data() + beg;
}

inline double* ICTemperatureSampling::SampleRawData(int seg, int beg, int size)
{
//    int differ = beg + size - tempSamplesTable_.at(seg).Size();
//    if(differ > 0)
//    {
//        sampleTemp_.clear();
//        double temp[differ];
//        memset(temp, 0, sizeof(temp));
//        sampleTemp_.append(temp, differ);
//        sampleTemp_.append(tempSamplesTable_[seg].RawData(beg, size), tempSamplesTable_.at(seg).Size());
//        return sampleTemp_.data();
//    }
    return tempSamplesTable_[seg].RawData(beg, size);
}

inline double ICTemperatureSampling::DError(int seg, uint delay)
{
    uint size = tempSamplesTable_.at(seg).Size();
    if(size == 0)
    {
        return 0;
    }
    else if(size < delay)
    {
        return GetSample(seg, size - 1) - GetSample(seg, 0);
    }
    else
    {
        return GetSample(seg, size - 1) - GetSample(seg, size - delay);
    }
}


inline double ICTemperatureSampling::LastSample(int seg)
{
    int size = tempSamplesTable_.at(seg).Size();
    if(size == 0)
    {
        return 0;
    }
    else
    {
        return GetSample(seg, size - 1);
    }
}

#endif // ICTEMPERATURESAMPLING_H

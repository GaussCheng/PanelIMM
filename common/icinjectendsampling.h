#ifndef ICINJECTENDSAMPLING_H
#define ICINJECTENDSAMPLING_H

#include "iccyclearray.h"

class ICInjectEndSampling
{
public:
    ICInjectEndSampling();

    static int SampleCount() { return tempSamplesTable_.Size();}
    static int TimeSampleCount() { return SAMPLES_COUNT;}
    static double* SampleRawData(int beg, int size);
    static double* TimeSampleRawData(int beg, int size);
    static void AddSample(double sample) {tempSamplesTable_.Add(sample);}
    static void Init();
    const static int SAMPLES_COUNT = 100;

private:
    static ICCycleArray<double, SAMPLES_COUNT> tempSamplesTable_;
    static double timeRawData_[SAMPLES_COUNT];
};

inline double* ICInjectEndSampling::TimeSampleRawData(int beg, int size)
{
    Q_UNUSED(size)
    return timeRawData_ + beg;
}

inline double* ICInjectEndSampling::SampleRawData(int beg, int size)
{
    return tempSamplesTable_.RawData(beg, size);
}

inline void ICInjectEndSampling::Init()
{
    for ( int i = 0; i < SAMPLES_COUNT; i++ )
    {
        timeRawData_[i] = i + 1;
        tempSamplesTable_.Add(0);
    }
}

#endif // ICINJECTENDSAMPLING_H

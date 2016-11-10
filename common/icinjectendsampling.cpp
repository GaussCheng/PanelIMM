#include "icinjectendsampling.h"

ICCycleArray<double, ICInjectEndSampling::SAMPLES_COUNT> ICInjectEndSampling::tempSamplesTable_;
double ICInjectEndSampling::timeRawData_[ICInjectEndSampling::SAMPLES_COUNT];
ICInjectEndSampling::ICInjectEndSampling()
{
}

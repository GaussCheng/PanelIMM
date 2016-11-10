#include "icinjectcurve.h"
#include "iccommoncurve.h"
#include "qwt_curve_fitter.h"
#include "icinjectendsampling.h"


ICInjectCurve::ICInjectCurve(QGraphicsItem *parent) :
    ICAxis(parent),
    count_(0),
    countSpace_(0),
    minInjEnd_(0),
    maxInjEnd_(0),
    injSpace_(0)
{
    curve_ = new ICCommonCurve("");
    curve_->attach(plot_);
    curve_->SetLineWidth(2);
    curve_->setCurveFitter(new QwtWeedingCurveFitter());
}

void ICInjectCurve::setCount(int count)
{
    count_ = count;
    plot_->SetXAxisScale(ICInjectEndSampling::SAMPLES_COUNT - count + 1, ICInjectEndSampling::SAMPLES_COUNT, countSpace_);
}

void ICInjectCurve::setCountSpace(int countSpace)
{
    countSpace_ = countSpace;
    plot_->SetXAxisScale(ICInjectEndSampling::SAMPLES_COUNT - count_ + 1, ICInjectEndSampling::SAMPLES_COUNT, countSpace_);

}

void ICInjectCurve::setMinInjEnd(double minInjEnd)
{
    minInjEnd_ = minInjEnd;
    plot_->SetYAxisScale(minInjEnd_, maxInjEnd_, injSpace_);
}

void ICInjectCurve::setMaxInjEnd(double maxInjEnd)
{
    maxInjEnd_ = maxInjEnd;
    plot_->SetYAxisScale(minInjEnd_, maxInjEnd_, injSpace_);
}

void ICInjectCurve::setInjSpace(double injSpace)
{
    injSpace_ = injSpace;
    plot_->SetYAxisScale(minInjEnd_, maxInjEnd_, injSpace_);

}

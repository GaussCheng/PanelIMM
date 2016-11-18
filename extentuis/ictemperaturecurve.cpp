#include "ictemperaturecurve.h"
#include "iccommoncurve.h"
#include <QTimerEvent>
#include "ictemperaturesampling.h"
//#include "qwt_plot_canvas.h"
//#include "qwt_plot_layout.h"
//#include "qwt_scale_widget.h"
#include "qwt_legend.h"
#include "qwt_curve_fitter.h"


ICTemperatureCurve::ICTemperatureCurve(QGraphicsItem *parent):
    curveColors_(CURVES_COUNT),
    curves_(CURVES_COUNT),
    segEns_(CURVES_COUNT),
    timeInterval_(1000),
    tAxisVal_(5),
    ICAxis(parent)
{
    curveColors_[0] = Qt::yellow;
    curveColors_[1] = Qt::green;
    curveColors_[2] = QColor(0xFC, 0xAF, 0x17);
    curveColors_[3] = QColor(0x33, 0xA3, 0xDC);
    curveColors_[4] = Qt::cyan;
    curveColors_[5] = Qt::magenta;
    curveColors_[6] = QColor(0XFF, 0xC2, 0x0E);
    curveColors_[7] = Qt::red;
    for(int i = 0; i != CURVES_COUNT; ++i)
    {
        segEns_.setBit(i, true);
        curves_[i] = new ICCommonCurve("Seg" + QString::number(i));
        curves_[i]->SetColor(curveColors_[i]);
        curves_[i]->attach(plot_);
        curves_[i]->SetLineWidth(2);
        curves_[i]->setCurveFitter(new QwtWeedingCurveFitter());
    }
    QwtLegend *legend = new QwtLegend;
    legend->setDefaultItemMode( QwtLegendData::Checkable );//图例可被点击
    legend->setMaxColumns(2);
//    plot_->insertLegend( legend, QwtPlot::RightLegend );
    connect(legend, SIGNAL(checked(QVariant,bool,int)), SLOT(onLegendToggled(QVariant,bool,int)));
}

void ICTemperatureCurve::timerEvent(QTimerEvent *e)
{
    int sampleBegin;
    int tAxisVal = tAxisVal_ * 60;
    int sampleSize = tAxisVal;
    sampleBegin = ICTemperatureSampling::SampleCount(0) - tAxisVal;
    if(sampleBegin < 0)
    {
        sampleBegin = 0;
    }
    setXAxisScaleRange(ICTemperatureSampling::GetTimeSample(0),
                                     ICTemperatureSampling::GetTimeSample(0) + tAxisVal);
    for(int i = 0; i != CURVES_COUNT; ++i)
    {
        if(segEns_.at(i))
        {
            curves_[i]->setRawSamples((double*)(ICTemperatureSampling::TimeSampleRawData(0, sampleSize)),
                                      (double*)(ICTemperatureSampling::SampleRawData(i, sampleBegin, sampleSize)),
                                      sampleSize);
        }
    }
    plot_->replot();
    ICAxis::timerEvent(e);
}

void ICTemperatureCurve::showEvent(QShowEvent *e)
{
    if(xAxisTimeScaleEn())
    {
        timerID_ = startTimer(timeInterval_);
    }
    QGraphicsProxyWidget::showEvent(e);
}

void ICTemperatureCurve::hideEvent(QHideEvent *e)
{
    if(xAxisTimeScaleEn())
    {
        killTimer(timerID_);
    }
    QGraphicsProxyWidget::hideEvent(e);
}

void ICTemperatureCurve::setTimeRange(int range)
{
    setXAxisInterval(range * 60);
    setXAxisTimeRange(range * 60);
    tAxisVal_ = range;
//    setStartUpTime(startUpTime_.addSecs(-(range * 60)).toString("hh:mm:ss"));
    plot_->replot();
}

QString ICTemperatureCurve::curveVisible() const
{
    QString ret;
    for(int i = 0; i < segEns_.count(); ++i)
    {
        ret += segEns_.at(i) ? "1" : "0";
    }
    return ret;
}

void ICTemperatureCurve::setCurveVisible(const QString &bitStatus)
{
//    int c = qMin(currentTempSeg_, qMin(segEns_.count(), bitStatus.size()));
    for(int i = 0; i < CURVES_COUNT; ++i)
    {
        if(bitStatus.size() > i)
            segEns_.setBit(i, bitStatus.at(i) == '1');
        curves_[i]->setVisible(segEns_.at(i));
    }
}

void ICTemperatureCurve::setSeg(int seg)
{
    currentTempSeg_ = seg;
//    QwtLegend *l = qobject_cast<QwtLegend*>(plot_->legend());
//    for(int i = 0; i < seg; ++i)
//    {
//        l->legendWidget(plot_->itemToInfo(curves_[i]))->show();
//    }
//    for(int i = seg; i < CURVES_COUNT - 1; ++i)
//    {
//        l->legendWidget(plot_->itemToInfo(curves_[i]))->hide();
//    }
    setCurveVisible(curveVisible());
}


void ICTemperatureCurve::onLegendToggled(const QVariant &itemInfo, bool on, int index)
{
    plot_->infoToItem(itemInfo)->setVisible(!on);
}

#include "icaxis.h"
#include "ictimescaledraw.h"

ICAxis::ICAxis(QGraphicsItem *parent) :
    QGraphicsProxyWidget(parent)
{
    plot_ = new ICPlot();
    plot_->EnXGrid(false);
    setWidget(plot_);
}
ICAxis::~ICAxis(){}

void ICAxis::setXAxisTitle(const QString& title)
{
    QwtText text;
    text.setFont(titleFont());
    text.setText(title);
    plot_->SetXAxisTitle(text);
}

void ICAxis::setYAxisTitle(const QString& title)
{
    QwtText text;
    text.setFont(titleFont());
    text.setText(title);
    plot_->SetYAxisTitle(text);
}

void ICAxis::setCanvasBackground(const QColor &color)
{
    plot_->setCanvasBackground(color);
}

void ICAxis::setMajColor(const QColor &c)
{
    QPen p(c, 0, Qt::DotLine);
    plot_->setMajPen(p);
}

void ICAxis::setXAxisTimeScaleEn(bool en)
{
    if(en)
    {
        plot_->setAutoReplot( false );
        plot_->setAxisScale( QwtPlot::xBottom, 0, 60 );
        xScaleDraw_ = new ICTimeScaleDraw(startUpTime_);
        plot_->setAxisScaleDraw( QwtPlot::xBottom, xScaleDraw_);
        plot_->setAxisLabelRotation( QwtPlot::xBottom, -50.0 );
        plot_->setAxisLabelAlignment( QwtPlot::xBottom, Qt::AlignLeft | Qt::AlignBottom );
    }
    else
    {
        plot_->setAutoReplot(true);
    }
}

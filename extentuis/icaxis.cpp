#include "icaxis.h"
#include "ictimescaledraw.h"

ICAxis::ICAxis(QGraphicsItem *parent) :
    xScaleDraw_(NULL),
    QGraphicsProxyWidget(parent)
{
    plot_ = new ICPlot();
    xScaleMin_ = 0;
    xScaleMax_ = 60;
    plot_->EnXGrid(false);
    setWidget(plot_);
}
ICAxis::~ICAxis(){}

void ICAxis::setColor(const QColor &c)
{
    QPalette p;
    p.setBrush(QPalette::Normal, QPalette::Window, c);
    setPalette(p);
}

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

void ICAxis::setStartUpTime(const QString &time)
{

    QTime t = QTime::fromString(time, "hh:mm:ss");
    startUpTime_.setHMS(t.hour(), t.minute(), t.second());
    if(xAxisTimeScaleEn())
    {
        xScaleDraw_->setBaseTime(startUpTime_);
    }
}

void ICAxis::setXAxisTimeScaleEn(bool en)
{
    if(en)
    {
        xScaleDraw_ = new ICTimeScaleDraw(startUpTime_);
        plot_->setAutoReplot( false );
        plot_->setAxisScale( QwtPlot::xBottom, 0, 60 );
        plot_->setAxisScaleDraw( QwtPlot::xBottom, xScaleDraw_);
        plot_->setAxisLabelRotation( QwtPlot::xBottom, -30.0 );
        plot_->setAxisLabelAlignment( QwtPlot::xBottom, Qt::AlignLeft | Qt::AlignBottom );
    }
    else
    {
        plot_->setAutoReplot(true);
    }
}

void ICAxis::setXAxisTimeRange(int sec)
{
    xScaleDraw_ = new ICTimeScaleDraw(startUpTime_.addSecs(-sec));
    plot_->setAxisScaleDraw( QwtPlot::xBottom, xScaleDraw_);
    plot_->setAxisLabelRotation( QwtPlot::xBottom, -30.0 );
    plot_->setAxisLabelAlignment( QwtPlot::xBottom, Qt::AlignLeft | Qt::AlignBottom );
    plot_->replot();
}

void ICAxis::setAxisFont(const QFont &f)
{
    axisFont_ = f;
    plot_->SetXAxisFont(axisFont_);
    plot_->SetYAxisFont(axisFont_);
}



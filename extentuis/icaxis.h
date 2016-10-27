#ifndef ICAXIS_H
#define ICAXIS_H

#include <QGraphicsProxyWidget>
#include <QTime>
#include "icplot.h"

class ICTimeScaleDraw;

class ICAxis : public QGraphicsProxyWidget
{
    Q_OBJECT
    Q_PROPERTY(QFont titleFont READ titleFont WRITE setTitleFont)
    Q_PROPERTY(QFont axisFont READ axisFont WRITE setAxisFont)
    Q_PROPERTY(QColor color READ color WRITE setColor)
    Q_PROPERTY(QString xAxisTitle READ xAxisTitle WRITE setXAxisTitle)
    Q_PROPERTY(QString yAxisTitle READ yAxisTitle WRITE setYAxisTitle)
    Q_PROPERTY(QColor canvasBackground READ canvasBackground WRITE setCanvasBackground)
    Q_PROPERTY(QColor majColor READ majColor WRITE setMajColor)
    Q_PROPERTY(bool xAxisTimeScaleEn READ xAxisTimeScaleEn WRITE setXAxisTimeScaleEn)
    Q_PROPERTY(QString startUpTime READ startUpTime WRITE setStartUpTime)



public:
    explicit ICAxis(QGraphicsItem *parent = 0);
    ~ICAxis();

    Q_INVOKABLE void setYAxisScale(double min, double max, double step )
    {
        plot_->SetYAxisScale(min, max, step);
    }

//    Q_INVOKABLE void setXAxisScale(int min, int max, int step );

    QFont titleFont() const { return titleFont_;}
    void setTitleFont(const QFont& f) { titleFont_ = f;}
    QFont axisFont() const { return axisFont_;}
    void setAxisFont(const QFont& f);

    QString xAxisTitle() const { return plot_->XAxisTitle().text();}
    void setXAxisTitle(const QString& title);
    QString yAxisTitle() const { return plot_->YAxisTitle().text();}
    void setYAxisTitle(const QString& title);
    QColor canvasBackground() { return plot_->canvasBackground().color();}
    void setCanvasBackground(const QColor& color);
    QColor majColor() const { return plot_->majPen().color();}
    void setMajColor(const QColor& c);

    bool xAxisTimeScaleEn() const { return xScaleDraw_ != NULL;}
    void setXAxisTimeScaleEn(bool en);

    QString startUpTime() const { return startUpTime_.toString("hh:mm:ss");}
    void setStartUpTime(const QString& time);

    QColor color() const { return bgColor_;}
    void setColor(const QColor& c);

    void setXAxisScaleRange(int min, int max)
    {
        plot_->setAxisScale(QwtPlot::xBottom, min, max);
        plot_->replot();
    }

    void setXAxisInterval(int interval)
    {
        xScaleMax_ = xScaleMin_ + interval;
    }

signals:

public slots:
protected:
protected:
    ICPlot* plot_;
    QTime startUpTime_;
private:
    QFont titleFont_;
    QFont axisFont_;
    QColor bgColor_;
    int xScaleMin_;
    int xScaleMax_;
    ICTimeScaleDraw* xScaleDraw_;
};

#endif // ICAXIS_H

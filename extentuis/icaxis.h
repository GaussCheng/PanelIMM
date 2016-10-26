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
    Q_PROPERTY(QString xAxisTitle READ xAxisTitle WRITE setXAxisTitle)
    Q_PROPERTY(QString yAxisTitle READ yAxisTitle WRITE setYAxisTitle)
    Q_PROPERTY(QColor canvasBackground READ canvasBackground WRITE setCanvasBackground)
    Q_PROPERTY(QColor majColor READ majColor WRITE setMajColor)
    Q_PROPERTY(bool xAxisTimeScaleEn READ xAxisTimeScaleEn WRITE setXAxisTimeScaleEn)
    Q_PROPERTY(QString startUpTime READ startUpTime WRITE setStartUpTime)



public:
    explicit ICAxis(QGraphicsItem *parent = 0);
    ~ICAxis();

    QFont titleFont() const { return titleFont_;}
    void setTitleFont(const QFont& f) { titleFont_ = f;}

    QString xAxisTitle() const { return plot_->XAxisTitle().text();}
    void setXAxisTitle(const QString& title);
    QString yAxisTitle() const { return plot_->YAxisTitle().text();}
    void setYAxisTitle(const QString& title);
    QColor canvasBackground() { return plot_->canvasBackground().color();}
    void setCanvasBackground(const QColor& color);
    QColor majColor() const { return plot_->majPen().color();}
    void setMajColor(const QColor& c);

    bool xAxisTimeScaleEn() const { return xScaleDraw_ == NULL;}
    void setXAxisTimeScaleEn(bool en);

    QString startUpTime() const { return startUpTime_.toString("hh:mm:ss");}
    void setStartUpTime(const QString& time)
    {
        QTime t = QTime::fromString(time, "hh:mm:ss");
        startUpTime_.setHMS(t.hour(), t.minute(), t.second());
    }
signals:

public slots:

private:
    ICPlot* plot_;
    QFont titleFont_;
    int timeInterval_;          //<X轴时间间隔单位ms
    int xScaleMin_;
    int xScaleMax_;
    QTime startUpTime_;
    ICTimeScaleDraw* xScaleDraw_;
};

#endif // ICAXIS_H

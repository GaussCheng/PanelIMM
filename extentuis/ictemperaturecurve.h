#ifndef ICTEMPERATURECURVE_H
#define ICTEMPERATURECURVE_H
#include "icaxis.h"
#include <QBitArray>
#include <QShowEvent>
#include <QHideEvent>

class ICCommonCurve;
class ICTemperatureCurve : public ICAxis
{
    Q_OBJECT
    Q_PROPERTY(int timeRange READ timeRange WRITE setTimeRange)
    Q_PROPERTY(QString curveVisible READ curveVisible WRITE setCurveVisible)

public:
    ICTemperatureCurve(QGraphicsItem *parent = 0);
    Q_INVOKABLE QColor curveColor(int i) const { return curveColors_.at(i);}
    int timeRange() const { return tAxisVal_;}
    void setTimeRange(int range);
    QString curveVisible() const;
    void setCurveVisible(const QString& bitStatus);


protected:
    void showEvent(QShowEvent* e);
    void hideEvent(QHideEvent* e);
    void timerEvent(QTimerEvent *e);

private:
    QVector<QColor> curveColors_;
    QVector<ICCommonCurve*> curves_;
    QBitArray segEns_;
    int timerID_;
    int timeInterval_;
    int currentTempSeg_;
    int tAxisVal_;
    const static int CURVES_COUNT = 8;

};

#endif // ICTEMPERATURECURVE_H

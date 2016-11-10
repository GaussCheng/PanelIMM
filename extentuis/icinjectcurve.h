#ifndef ICINJECTCURVE_H
#define ICINJECTCURVE_H
#include "icaxis.h"

class ICCommonCurve;
class ICInjectCurve : public ICAxis
{
    Q_OBJECT
    Q_PROPERTY(int count READ count WRITE setCount)
    Q_PROPERTY(int countSpace READ countSpace WRITE setCountSpace)
    Q_PROPERTY(double minInjEnd READ minInjEnd WRITE setMinInjEnd)
    Q_PROPERTY(double maxInjEnd READ maxInjEnd WRITE setMaxInjEnd)
    Q_PROPERTY(double injSpace READ injSpace WRITE setInjSpace)
public:
    explicit ICInjectCurve(QGraphicsItem *parent = 0);

    int count() const { return count_;}
    void setCount(int count);
    int countSpace() const { return countSpace_;}
    void setCountSpace(int countSpace);
    double minInjEnd() const { return minInjEnd_;}
    void setMinInjEnd(double minInjEnd);
    double maxInjEnd() const { return maxInjEnd_;}
    void setMaxInjEnd(double maxInjEnd);
    double injSpace() const { return injSpace_;}
    void setInjSpace(double injSpace);

signals:

public slots:

private:
    int count_;
    int countSpace_;
    double minInjEnd_;
    double maxInjEnd_;
    double injSpace_;
    ICCommonCurve* curve_;

};

#endif // ICINJECTCURVE_H

#ifndef ICTIMESCALEDRAW_H
#define ICTIMESCALEDRAW_H

#include <QTime>
#include "qwt_scale_draw.h"
class ICTimeScaleDraw : public QwtScaleDraw
{
public:
    ICTimeScaleDraw( const QTime &base ):
        baseTime( base )
    {
    }
    virtual QwtText label( double v ) const
    {
        QTime upTime = baseTime.addSecs( ( int )v );
        return upTime.toString();
    }

    void setBaseTime(const QTime& t) {baseTime = t;}

private:
    QTime baseTime;
};

#endif // ICTIMESCALEDRAW_H

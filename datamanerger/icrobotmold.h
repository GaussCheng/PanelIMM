#ifndef ICROBOTMOLD_H
#define ICROBOTMOLD_H

#include <QtGlobal>
#include <QString>
#include <QSharedPointer>
#include <QVector>
#include <QMap>
#include "icconfigsaddr.h"
#include "icparameterscache.h"
#include "icmoldbase.h"



class ICRobotMold;

typedef QSharedPointer<ICRobotMold> ICRobotMoldPTR;

typedef  QList<QPair<QString, int> > ICCustomActionParseDefine;

class ICRobotMold:public ICMoldBase
{
public:

    ICRobotMold();
    static ICRobotMoldPTR CurrentMold()
    {
        return currentMold_;
    }
    static void SetCurrentMold(ICRobotMold* mold)
    {
        currentMold_ = ICRobotMoldPTR(mold);
    }


private:
//    ICActionProgram ParseActionProgram_(const QString& content);

private:
    static ICRobotMoldPTR currentMold_;
    QString moldName_;
    ICParametersCache fncCache_;
};

#endif // ICROBOTMOLD_H

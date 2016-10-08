#ifndef ICIMMMOLD_H
#define ICIMMMOLD_H

#include "icmoldbase.h"
#include "icparameterscache.h"

class ICIMMMold : public ICMoldBase
{
public:
    ICIMMMold();
    bool LoadMold(const ICMoldInfo &info);
private:
    ICParametersCache fncCache_;
};

#endif // ICIMMMOLD_H

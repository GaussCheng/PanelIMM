#ifndef ICIMMMOLD_H
#define ICIMMMOLD_H

#include "icmoldbase.h"
#include "icparameterscache.h"

class ICIMMMold : public ICMoldBase
{
public:
    ICIMMMold();
    bool LoadMold(const ICMoldInfo &info);
    RecordDataObject NewRecord(const ICMoldInfo& info);
};

#endif // ICIMMMOLD_H

#ifndef ICMOLDBASE_H
#define ICMOLDBASE_H

#include "icdalhelper.h"

class ICMoldInfo{
public:
    ICMoldInfo(const QString& mN):name(mN){}
    QString name;
    QList<QPair<int, quint32> > values;
};

class ICMoldBase
{
public:

    enum {
        kRecordErr_None,
        kRecordErr_Name_Is_Empty,
        kRecordErr_Name_Is_Exists,
    };
    ICMoldBase();
    virtual RecordDataObject NewRecord(const ICMoldInfo& info){};
    virtual RecordDataObject CopyRecord(const ICMoldInfo& old, const ICMoldInfo& now){};
    virtual bool DeleteRecord(const ICMoldInfo& info){};
    virtual ICRecordInfos RecordInfos() const
    {
        return ICDALHelper::RecordTableInfos();
    }
    virtual QVariant ExportMold(const ICMoldInfo& info){};
    virtual RecordDataObject ImportMold(const ICMoldInfo& info){};
    virtual bool LoadMold(const ICMoldInfo& info){};
    virtual bool SaveMold(){};
public:
};

#endif // ICMOLDBASE_H

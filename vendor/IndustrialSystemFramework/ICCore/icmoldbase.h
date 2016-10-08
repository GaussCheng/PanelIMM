#ifndef ICMOLDBASE_H
#define ICMOLDBASE_H

#include "icdalhelper.h"

class ICMoldInfo{
public:
    ICMoldInfo(){}
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
    virtual RecordDataObject NewRecord(const ICMoldInfo& info){}
    virtual RecordDataObject CopyRecord(const ICMoldInfo& now, const ICMoldInfo& old)
    {
        if(now.name.isEmpty()) return RecordDataObject(kRecordErr_Name_Is_Empty);
        if(ICDALHelper::IsExistsRecordTable(now.name))
        {
            return RecordDataObject(kRecordErr_Name_Is_Exists);
        }
        QString dt = ICDALHelper::CopyMold(now.name, old.name);
        return RecordDataObject(now.name, dt);
    }

    virtual bool DeleteRecord(const ICMoldInfo& info)
    {
        return ICDALHelper::DeleteMold(info.name);
    }

    ICMoldInfo CurrentMoldInfo() const { return current_;}
    virtual ICRecordInfos RecordInfos() const
    {
        return ICDALHelper::RecordTableInfos();
    }
    virtual QVariant ExportMold(const ICMoldInfo& info){ return QVariant();}
    virtual RecordDataObject ImportMold(const ICMoldInfo& info){ return RecordDataObject();}
    virtual bool LoadMold(const ICMoldInfo& info){ return false;}
    virtual bool SaveMold(){ return false;}
public:
protected:
    ICMoldInfo current_;
};

#endif // ICMOLDBASE_H

#ifndef ICMOLDBASE_H
#define ICMOLDBASE_H

#include "icdalhelper.h"
#include "icparameterscache.h"

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
    virtual ~ICMoldBase(){}
    virtual RecordDataObject NewRecord(const ICMoldInfo& info){ return RecordDataObject(info.name, QDateTime::currentDateTime().toString());}
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
    virtual QVariant ExportMold(const ICMoldInfo& info){ return QVariant(info.name);}
    virtual RecordDataObject ImportMold(const ICMoldInfo& info){ return RecordDataObject(info.name, QDateTime::currentDateTime().toString());}
    virtual bool LoadMold(const ICMoldInfo& info){Q_UNUSED(info); return false;}
    virtual bool SaveMold(){ return false;}

    quint32 MoldFnc(ICAddrWrapperCPTR addr)
    {
        return fncCache_.ConfigValue(addr);
    }

    QList<QPair<int, quint32> > SetMoldFncs(const ICAddrWrapperValuePairList values)
    {
        QList<QPair<int, quint32> >baseValues;
        ICAddrWrapperValuePair tmp;
        for(int i = 0; i != values.size(); ++i)
        {
            tmp = values.at(i);
            fncCache_.UpdateConfigValue(tmp.first, tmp.second);

            baseValues.append(qMakePair(tmp.first->BaseAddr(), fncCache_.OriginConfigValue(tmp.first)));
        }
        //    ICDALHelper::UpdateMachineConfigValues(baseValues, configName_);
        ICDALHelper::UpdateMoldFncValues(baseValues, current_.name);
        return baseValues;
    }

    QList<QPair<int, quint32> > BareMachineConfigs() const
    {
        return fncCache_.ToPairList();
    }
public:
protected:
    ICMoldInfo current_;
    ICParametersCache fncCache_;
};

#endif // ICMOLDBASE_H

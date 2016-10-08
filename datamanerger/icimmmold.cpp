#include "icimmmold.h"

ICIMMMold::ICIMMMold()
{
}

bool ICIMMMold::LoadMold(const ICMoldInfo &info)
{
    if(info.name == current_.name)
        return false;
    current_ = info;

    QVector<QPair<quint32, quint32> > fncs = ICDALHelper::GetAllMoldConfig(ICDALHelper::MoldFncTableName(current_.name));
    for(int i = 0; i != fncs.size(); ++i)
    {
        fncCache_.UpdateConfigValue(fncs.at(i).first, fncs.at(i).second);
    }
    return true;
}
RecordDataObject ICIMMMold::NewRecord(const ICMoldInfo& info)
{
    if(info.name.isEmpty()) return RecordDataObject(kRecordErr_Name_Is_Empty);
    if(ICDALHelper::IsExistsRecordTable(info.name))
    {
        RecordDataObject ret(kRecordErr_Name_Is_Exists);
        ret.setRecordName(info.name);
        return ret;
    }
    QList<QPair<int, quint32> > fncs = info.values;
    QString dt = ICDALHelper::NewMold(info.name, QStringList(), fncs,  QVector<QVariantList>(),  QVector<QVariantList>());
    return RecordDataObject(info.name, dt);
}


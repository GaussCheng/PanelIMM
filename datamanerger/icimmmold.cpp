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

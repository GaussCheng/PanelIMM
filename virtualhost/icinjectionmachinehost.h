#ifndef ICINJECTIONMACHINEHOST_H
#define ICINJECTIONMACHINEHOST_H

#include "icvirtualhost.h"
#include "hccommparagenericdef.h"
#include "hccommandformat.h"
#include "icaddrwrapper.h"
#include "icparameterscache.h"
#include <qmath.h>

#include "icinjectionmachineframetransceiverdatamapper.h"

class ICInjectionMachineHost : public ICVirtualHost
{
    Q_OBJECT
public:
    enum SpecialOutput{
        SpecialOutput_Motor             = 25,
        SpecialOutput_ForceLubricate    = 28
    };
    enum HeateState{
        HeateState_None,
        HeateState_Heate,
        HeateState_Holding,
        HeateState_AutoHolding,
        HeateState_AutoHeating
    };
    ICInjectionMachineHost(uint64_t hostId, QObject* parent = 0);
    ~ICInjectionMachineHost();

    virtual QByteArray HostStatus(const ICAddrWrapper* addr) const;
    virtual quint32 HostStatusValue(const ICAddrWrapper* addr) const
    {
        return statusValueMap_.ConfigValue(addr);
//        quint32 v =  statusValueMap_.value((addr->BaseAddr()));
//        return ICAddrWrapper::ExtractValueByAddr(addr, v);
    }

    virtual void StopCommunicate();
    virtual void StartCommunicate();

    void SendConfigs(const QList<QPair<int, quint32> >& addrVals)
    {
        QPair<int, quint32> tmp;
        for(int i = 0; i != addrVals.size(); ++i)
        {
            tmp = addrVals.at(i);
            ICVirtualHostPtr host = ICVirtualHostManager::GetVirtualHost<ICInjectionMachineHost>(1);
            AddWriteConfigCommunicationFrame(host, tmp.first, tmp.second);
            AddReadConfigCommunicationFrame_(host);
        }
    }
    //    static ICSTATUS CurrentStatus

    static HeateState GetHeateStateFromHostStatus(quint32 hostStatusValue)
    {
        return static_cast<HeateState>(hostStatusValue & 0x000000FF);
    }
    static bool IsHostHeating(quint32 hostStatusValue)
    {
        return (GetHeateStateFromHostStatus(hostStatusValue) == HeateState_Heate ||
                GetHeateStateFromHostStatus(hostStatusValue) == HeateState_Holding);
    }

    static bool IsHostSegHeating(int seg, quint32 hostStatusValue)
    {
        return hostStatusValue & (1 << seg);
    }

    static void AddWriteConfigCommunicationFrame(ICVirtualHostPtr hostPtr, uint addr, quint32 value);
//    static void AddWriteConfigCommunicationFrame(ICVirtualHostPtr hostPtr, const ICAddrWrapper* addr, quint32 value);
    static void AddActionCommunicationFrame(ICVirtualHostPtr hostPtr, int action);

    bool SetAddrValue(const ICAddrWrapper* addr, int value);
protected:
    void InitStatusFormatorMap_();
    void InitStatusMap_();
    bool InitConfigsImpl(const QVector<QPair<int, quint32> >& configList, int startAddr);
    bool IsInputOnImpl(int index) const;
    bool IsOutputOnImpl(int index) const;
    void CommunicateImpl();
    QBitArray AlarmsImpl() const { return alarmBits_;}

private:
    void InsertStatusToStatusMap_(int addr, quint32 value) { statusValueMap_.UpdateConfigValue(addr, value);}
//    void InsertStatusFormatorToFormatorMap_(ICAddr addr, HostStatusFormator formator) { statusFormatorMap_.insert(addr, formator);}
    static void AddReadConfigCommunicationFrame_(ICVirtualHostPtr hostPtr);
signals:
    void NeedToInit();
    void ReadyCommunicate();
    void CommunicateErrChecked();
private slots:
    void ResetCommunicate();

private:
    bool recvRet_;
    ICInjectionMachineTransceiverData* recvFrame_;
    ICFrameTransceiverDataMapper* frameTransceiverDataMapper_;
    QBitArray alarmBits_;
    static ICAddr beginAddrs_;
    static uint length_;
    static bool restartFlag_;
    ICParametersCache statusValueMap_;
//    QMap<ICAddr, HostStatusFormator> statusFormatorMap_;
    const static int kHostID = 1;
    int conjectionCommErrCount_;
};

/**
 * 获取主机中对应与参数addr地址的值
 *
 * @param addr    主机参数地址
 * @return 以字符串的形式返回值
 */
inline QByteArray ICInjectionMachineHost::HostStatus(const ICAddrWrapper *addr) const
{

    int v = statusValueMap_.ConfigValue(addr);
    return QByteArray::number(v / qPow(10, addr->Decimal()), 'f', addr->Decimal());
//    return statusFormatorMap_.value(static_cast<ICAddr>(addr), GeneralStatusFormator)(statusValueMap_.value(static_cast<ICAddr>(addr)));
}

inline void ICInjectionMachineHost::AddActionCommunicationFrame(ICVirtualHostPtr hostPtr, int action)
{
    ICInjectionMachineTransceiverData *data
            = new ICInjectionMachineTransceiverData(kHostID,
                                                    FunctionCode_WriteAddr,
                                                    ICAddr_Action,
                                                    1,
                                                    ICInjectionMachineTransceiverData::ICTransceiverDataBuffer()<<action);
//    hostPtr->AddCommunicationFrame(data);
    hostPtr->AddFastCommunicationFrame(data);
}

inline void ICInjectionMachineHost::AddWriteConfigCommunicationFrame(ICVirtualHostPtr hostPtr, uint addr, quint32 value)
{
    ICInjectionMachineTransceiverData *data
            = new ICInjectionMachineTransceiverData(kHostID,
                                                    FunctionCode_WriteAddr,
                                                    addr,
                                                    1,
                                                    ICInjectionMachineTransceiverData::ICTransceiverDataBuffer()<<value);
    hostPtr->AddCommunicationFrame(data);
    AddReadConfigCommunicationFrame_(hostPtr);
}

//inline void ICInjectionMachineHost::AddWriteConfigCommunicationFrame(ICVirtualHostPtr hostPtr, const ICAddrWrapper *addr, quint32 value)
//{
//    uint baseV = ICParametersCache::OriginConfigValue(addr);
//    ICAddrWrapper::UpdateBaseAddrValue(addr, value, &baseV);
//    ICConfigsCache::UpdateConfigValue(addr->BaseAddr(), baseV);
//    AddWriteConfigCommunicationFrame(hostPtr, addr->BaseAddr(), baseV);
//}

#endif // ICINJECTIONMACHINEHOST_H

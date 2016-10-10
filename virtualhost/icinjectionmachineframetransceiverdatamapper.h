#ifndef ICINJECTIONMACHINEFRAMETRANSCEIVERDATAMAPPER_H
#define ICINJECTIONMACHINEFRAMETRANSCEIVERDATAMAPPER_H

#include "ichctransceiverdata.h"
#include "hccommparagenericdef.h"
#include "hccommandformat.h"
#include "icoptimize.h"
#include "icobjectpool.h"
#include "icaddrwrapper.h"

#include <QDebug>

class ICInjectionMachineTransceiverData: public ICHCTransceiverData
{
public:
//    static int newCount_;
    typedef QVector<quint32> ICTransceiverDataBuffer;
    ICInjectionMachineTransceiverData(){}
    ICInjectionMachineTransceiverData(
                        uint8_t hostID,
                        FunctionCode fc,
                      uint addr,
                      uint8_t length,
                      const ICTransceiverDataBuffer& data = ICTransceiverDataBuffer())
        :ICHCTransceiverData(hostID, fc, addr, length, data){}

    virtual bool IsQuery() const { return GetFunctionCode() == FunctionCode_ReadAddr;}
    virtual bool IsError() const { return GetFunctionCode() == FunctionCode_Err;}
    virtual int MaxFrameLength() const { return FRAME_MAX_SIZE;}

//    ~ICInjectionMachineTransceiverData()
//    {
//        objectPool_.FreeData(this);
//        --newCount_;
//    }

    void* operator new(size_t size)
    {
        Q_UNUSED(size)
//        ++newCount_;
        return objectPool_.MallocData();
    }

    void operator delete(void* p)
    {
        objectPool_.FreeData(p);
//        --newCount_;
    }

private:
    static ICObjectPool<ICInjectionMachineTransceiverData> objectPool_;
};


class ICInjectionMachineFrameTransceiverDataMapper : public ICHCFrameTransceiverDataMapper
{
public:
    ICInjectionMachineFrameTransceiverDataMapper();
    bool IsFunctionCodeValid(int fc) const;
    bool IsFunctionAddrValid(int addr, int fc) const;
    int GetAddrFromBuffer(const uint8_t* buffer) const;
    size_t GetBufferDataLength(const uint8_t* buffer) const;
    size_t FrameMinSize() const { return FRAME_MIN_SIZE;}
    virtual int NeedToRecvLength(const ICTransceiverData* sentData) const;

private:
    ICInjectionMachineTransceiverData::ICTransceiverDataBuffer dataButter_;
};

inline bool ICInjectionMachineFrameTransceiverDataMapper::IsFunctionCodeValid(int fc) const
{
    return (fc > FunctionCode_BeginSection) && (fc < FunctionCode_NIL);
}

inline bool ICInjectionMachineFrameTransceiverDataMapper::IsFunctionAddrValid(int addr, int fc) const
{
    switch(fc)
    {
    case FunctionCode_ReadAddr:
        return (addr > ICAddr_BeginSection) && (addr < ICAddr_NIL);
    case FunctionCode_WriteAddr:
        return (addr > ICAddr_BeginSection) && (addr < ICAddr_Write_Section_End);
    case FunctionCode_Err:
        return addr == ICAddr_ErrAddr;
    default:
        return false;
    }
}

inline int ICInjectionMachineFrameTransceiverDataMapper::GetAddrFromBuffer(const uint8_t *buffer) const
{
    return static_cast<ICAddr>((buffer[2] << 8) | buffer[3]);
}

inline size_t ICInjectionMachineFrameTransceiverDataMapper::GetBufferDataLength(const uint8_t *buffer) const
{
    return buffer[FRAME_LENGTH_POS] << 2;
}

#endif // ICINJECTIONMACHINEFRAMETRANSCEIVERDATAMAPPER_H

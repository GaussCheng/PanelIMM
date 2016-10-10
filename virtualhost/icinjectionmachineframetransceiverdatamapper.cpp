#include "icinjectionmachineframetransceiverdatamapper.h"
#include "icutility.h"

ICObjectPool<ICInjectionMachineTransceiverData> ICInjectionMachineTransceiverData::objectPool_;
//int ICInjectionMachineTransceiverData::newCount_ = 0;
ICInjectionMachineFrameTransceiverDataMapper::ICInjectionMachineFrameTransceiverDataMapper()
{
}

int ICInjectionMachineFrameTransceiverDataMapper::NeedToRecvLength(const ICTransceiverData *sentData) const
{
    const ICHCTransceiverData *hcdata = static_cast<const ICHCTransceiverData*>(sentData);
    if(hcdata == NULL)
    {
        return FrameMinSize();
    }
//    if(hcdata->IsQuery())
//    {
        return FRAME_HEAD_SIZE + (hcdata->GetLength() << 2) + FRAME_CRC_LENGTH;
//    }
//    else
//    {
//        return FRAME_HEAD_SIZE + hcdata->g
//    }
}

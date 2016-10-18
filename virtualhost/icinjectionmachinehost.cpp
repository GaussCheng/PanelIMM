#include "icinjectionmachinehost.h"
#if defined UART_COMM
#include "icserialtransceiver.h"
#elif defined TCP_COMM
#include "ictcptransceiver.h"
#endif
#include <qmath.h>

//#include "iccomplierconfig.h"
#include "icparameterscache.h"
#include "icconfigsaddr.h"
#ifdef TEST_TIME_DEBUG
#include <QTime>
#include <QDebug>
#endif

#if defined UART_COMM
const static int ReadLength = (ICAddr_Read_Section_End - ICAddr_Read_Status0) >> 1;
#elif defined TCP_COMM
const static int ReadLength = (ICAddr_Read_Section_End - ICAddr_Read_Status) >> 1;
#endif

ICAddr ICInjectionMachineHost::beginAddrs_;
uint ICInjectionMachineHost::length_;
bool ICInjectionMachineHost::restartFlag_;
ICInjectionMachineHost::ICInjectionMachineHost(uint64_t hostId, QObject *parent)
    :ICVirtualHost(hostId, parent),
      alarmBits_(256),
      conjectionCommErrCount_(0)
{
    recvFrame_ = new ICInjectionMachineTransceiverData();
    recvFrame_->SetHostID(1);
    frameTransceiverDataMapper_ = new ICInjectionMachineFrameTransceiverDataMapper();
    InitStatusMap_();
    InitStatusFormatorMap_();
#if defined UART_COMM
    ICSerialTransceiver::Instance()->StartCommunicate();
    ICSerialTransceiver::Instance()->SetFrameTransceiverDataMapper(frameTransceiverDataMapper_);
    SetTransceiver(ICSerialTransceiver::Instance());
#elif defined TCP_COMM
    ICTcpTransceiver* t = new ICTcpTransceiver();
    t->SetFrameTransceiverDataMapper(frameTransceiverDataMapper_);
    SetTransceiver(t);
#endif

    beginAddrs_ = ICAddr_Read_Status0;
    length_ = ReadLength;
    restartFlag_ = false;
    //    Transceiver()->SetBlock(true);
    //    Transceiver()->SetBlockTime(5);
}

ICInjectionMachineHost::~ICInjectionMachineHost()
{
#ifdef TCP_COMM
    delete Transceiver();
#endif
    delete recvFrame_;
    delete frameTransceiverDataMapper_;
    while(!queue_.IsEmpty())
    {
        qDebug("release queue");
        queue_.DeQueue();
    }
    qDebug("Delete host");
    statusValueMap_.ClearConfigsAddrValueCache();
//    statusFormatorMap_.clear();
//    qDebug()<<"newCount:"<<ICInjectionMachineTransceiverData::newCount_;
}

void ICInjectionMachineHost::InitStatusFormatorMap_()
{
//    InsertStatusFormatorToFormatorMap_(ICAddr_Read_MoldTeledipGauge, OneDecimalStatusFormator);
//    InsertStatusFormatorToFormatorMap_(ICAddr_Read_InjectTeledipGauge, OneDecimalStatusFormator);
//    InsertStatusFormatorToFormatorMap_(ICAddr_Read_NozzleTeledipGauge, OneDecimalStatusFormator);
//    InsertStatusFormatorToFormatorMap_(ICAddr_Read_EjectTeledipGauge, OneDecimalStatusFormator);
//    InsertStatusFormatorToFormatorMap_(ICAddr_Read_FrontMoldCycle, OneDecimalStatusFormator);
//    InsertStatusFormatorToFormatorMap_(ICAddr_Read_TotalTime, OneDecimalStatusFormator);
//    InsertStatusFormatorToFormatorMap_(ICAddr_Read_WholeTime, OneDecimalStatusFormator);
//    InsertStatusFormatorToFormatorMap_(ICAddr_Read_AutoRunTime, OneDecimalStatusFormator);

//    InsertStatusFormatorToFormatorMap_(ICAddr_Read_NozzleActualTemp, MinusOneDecimalStatusFormator);
//    InsertStatusFormatorToFormatorMap_(ICAddr_Read_NozzleSeg1ActualTemp, MinusOneDecimalStatusFormator);
//    InsertStatusFormatorToFormatorMap_(ICAddr_Read_NozzleSeg2ActualTemp, MinusOneDecimalStatusFormator);
//    InsertStatusFormatorToFormatorMap_(ICAddr_Read_NozzleSeg3ActualTemp, MinusOneDecimalStatusFormator);
//    InsertStatusFormatorToFormatorMap_(ICAddr_Read_NozzleSeg4ActualTemp, MinusOneDecimalStatusFormator);
//    InsertStatusFormatorToFormatorMap_(ICAddr_Read_NozzleSeg5ActualTemp, MinusOneDecimalStatusFormator);
//    InsertStatusFormatorToFormatorMap_(ICAddr_Read_NozzleSeg6ActualTemp, MinusOneDecimalStatusFormator);
//    InsertStatusFormatorToFormatorMap_(ICAddr_Read_OilActualTemp, MinusOneDecimalStatusFormator);
    //    InsertStatusFormatorToFormatorMap_(ICAddr_Read_Action_MoldClose_Time, OneDecimalStatusFormator);
    //    InsertStatusFormatorToFormatorMap_(ICAddr_Read_Action_MoldOpen_Time, OneDecimalStatusFormator);
    //    InsertStatusFormatorToFormatorMap_(ICAddr_Read_Action_Inject_Time, OneDecimalStatusFormator);
    //    InsertStatusFormatorToFormatorMap_(ICAddr_Read_Action_Charge_Time, OneDecimalStatusFormator);
}

void ICInjectionMachineHost::InitStatusMap_()
{
    for(ICAddr addr = ICAddr_Read_Status0; addr != ICAddr_Read_Section_End; addr = static_cast<ICAddr>(addr + 1))
    {
        InsertStatusToStatusMap_(addr, 0);
    }
}

/**
 * 获取输入点的状态的实现函数
 *
 * @param index    输入点的位置
 */
bool ICInjectionMachineHost::IsInputOnImpl(int index) const
{
    if(index < 32)
    {
        quint32 temp = 1 << index;
//        qDebug()<<HostStatusValue(&c_ro_0_32_1538) << temp;
        return HostStatusValue(&c_ro_0_32_0_1538) & temp;
    }
//    else if(index < 64)
//    {
//        quint32 temp = 1 << (index - 32);
//        return HostStatusValue(&c_ro_0_32_1539) & temp;
//    }
    return false;
}

/**
 * 获取输出点的状态的实现函数
 *
 * @param index    输出点的位置
 */
bool ICInjectionMachineHost::IsOutputOnImpl(int index) const
{
    if(index < 32)
    {
        quint32 temp = 1 << index;
        return HostStatusValue(&c_ro_0_32_0_1539) & temp;
    }
    else if(index < 64)
    {
        quint32 temp = 1 << (index - 32);
        return HostStatusValue(&c_ro_0_32_0_1540) & temp;
    }
    return false;
}

//static QTime tt;

static ICAddrWrapperList alarmAddrs = ICAddrWrapperList()<<&c_ro_0_32_0_1547<<&c_ro_0_32_0_1548
                                                           <<&c_ro_0_32_0_1549<<&c_ro_0_32_0_1550
                                                             <<&c_ro_0_32_0_1551<<&c_ro_0_32_0_1552
                                                               <<&c_ro_0_32_0_1553<<&c_ro_0_32_0_1554;
#define IMM_INTERNET  0

void ICInjectionMachineHost::CommunicateImpl()
{
#if(IMM_INTERNET)
        InsertStatusToStatusMap_(1541,  rand() % 2500);
        InsertStatusToStatusMap_(1542,   rand() % 2000);
        InsertStatusToStatusMap_(1543,  rand() % 1);
        InsertStatusToStatusMap_(1544,  rand() % 1000);
        InsertStatusToStatusMap_(1555, rand() % 110);
        InsertStatusToStatusMap_(1556, rand() % 110);
        InsertStatusToStatusMap_(1557, rand() % 110);
    int i = 0;
    for(int addr = recvFrame_->GetAddr(); i < recvFrame_->Data().size(); ++addr)
    {
        InsertStatusToStatusMap_(static_cast<ICAddr>(addr), recvFrame_->Data().at(i++));
    }
    for(i = 1;i<1024;i++)
    {
        ICConfigsCache::UpdateConfigValue(i,ICConfigsCache::ConfigBaseValue(i));
    }
    return;
#endif
//InsertStatusToStatusMap_(1543,  rand() % 2500);
#ifdef TEST_TIME_DEBUG
    /*TIME_TEST*/
    QTime time;
    time.start();
#endif
#ifdef Q_WS_X11
    //    InsertStatusToStatusMap_(ICAddr_Read_Action, rand() % 100);
    //    for(int i = 0; i != 8; ++i)
    //    {
    //        InsertStatusToStatusMap_((ICAddr)(ICAddr_Read_NozzleActualTemp + i), 100 + (rand() % 10));
    //    }
    //    InsertStatusToStatusMap_(ICAddr_Read_NozzleActualTemp, 170);
    //    InsertStatusToStatusMap_(ICAddr_Read_OilActualTemp, 4);
    //        InsertStatusToStatusMap_(ICAddr_Read_InjectTeledipGauge, rand() % 1000);
//    InsertStatusToStatusMap_(1541,  rand() % 2500);
//    InsertStatusToStatusMap_(1542,   rand() % 2000);
//    InsertStatusToStatusMap_(1543,  rand() % 1);
//    InsertStatusToStatusMap_(1544,  rand() % 1000);
//    InsertStatusToStatusMap_(1555, rand() % 110);
//    InsertStatusToStatusMap_(1556, rand() % 110);
//    InsertStatusToStatusMap_(1557, rand() % 110);
//    InsertStatusToStatusMap_(ICAddr_Read_InjectTeledipGauge,  2000);
//    InsertStatusToStatusMap_(ICAddr_Read_EjectTeledipGauge,  1000);
//    InsertStatusToStatusMap_(ICAddr_Read_MoldTeledipGauge,  3000);
//    InsertStatusToStatusMap_(ICAddr_Read_NozzleSeg1ActualTemp, rand() % 200);
//    InsertStatusToStatusMap_(ICAddr_Read_CurrentPress, 100 << 16);
    //    InsertStatusToStatusMap_(ICAddr_Read_OutPutY0, 0xFFFFFFFF);
    //    InsertStatusToStatusMap_(ICAddr_Read_OutPutY1, 240);
#endif
//    qDebug()<<"Comm Time:"<<tt.restart();
    recvRet_ = Transceiver()->Read(recvFrame_, queue_.Head());
//#if defined TCP_COMM
    if(recvRet_ == false && !recvFrame_->IsError())
    {
//        IncreaseCommunicateErrCount();
        ++conjectionCommErrCount_;
        if(conjectionCommErrCount_ > 50)
        {
            alarmBits_.setBit(ALARM_COMMUNICATION_ANOMALY, 1);
            //            queue_.Clear();
        }
        if(conjectionCommErrCount_ < 2)
        {
            return;
        }
    }
//#endif
    if(unlikely(IsCommunicateDebug()))
    {
        emit ReadyCommunicate();
    }
    if(likely(recvRet_ && !recvFrame_->IsError()))
//    if(1)
    {
        if(likely(recvFrame_->IsQuery()))
//        if(0)
        {
            int i = 0;
            for(int addr = recvFrame_->GetAddr(); i < recvFrame_->Data().size(); ++addr)
            {
                InsertStatusToStatusMap_(static_cast<ICAddr>(addr), recvFrame_->Data().at(i++));
            }
            //            if((recvFrame_->GetAddr() >= ICAddr_Read_Alarm0) &&
            //               (recvFrame_->GetAddr() < ICAddr_Read_CurrentPress))
            //            {
            quint32 alarmBlock;
            alarmBits_.fill(false);
            int rl;
            //                if(recvFrame_->GetAddr() + recvFrame_->GetLength() < ICAddr_Read_CurrentPress)
            //                {
            //                    rl = recvFrame_->GetAddr() + recvFrame_->GetLength();
            //                }
            //                else
            //                {
            rl = alarmAddrs.size();
            //                }
            for(int i = 0, j = 0; i != rl ; ++i)
            {
                alarmBlock = HostStatusValue(alarmAddrs.at(i));
                //                    alarmBits_.fill(false, j, j + 32);
                for(int n = 0; alarmBlock; alarmBlock >>= 1)
                {
                    if(alarmBlock & 1)
                    {
                        alarmBits_.setBit(n + j);
                    }
                    ++n;
                }
                j += 32;
            }
            //            }
        }
        queue_.DeQueue();
        conjectionCommErrCount_ = 0;
    }
    else
    {
        if(IsCommunicateDebug())
        {
            qDebug()<<"Read:"<<Transceiver()->LastReadFrame();
            qDebug()<<"Write:"<<Transceiver()->LastWriteFrame();
            emit CommunicateErrChecked();
        }
        IncreaseCommunicateErrCount();
        ++conjectionCommErrCount_;
        if(conjectionCommErrCount_ > 50)
        {
            alarmBits_.setBit(ALARM_COMMUNICATION_ANOMALY, 1);
            //            queue_.Clear();
        }
    }
    if(queue_.IsEmpty())
    {
//#if defined UART_COMM
        ICInjectionMachineTransceiverData *readData
                = new ICInjectionMachineTransceiverData(kHostID,
                                                        FunctionCode_ReadAddr,
                                                        beginAddrs_,
                                                        length_);
        int readLeangth = ReadLength;
        AddCommunicationFrame(readData);
        //        if(length_ == ReadLength)
        //        {
        //            beginAddrs_ = ICAddr_Read_Status;
        //            length_ = ReadLength;
        //            return;
        //        }
        if(unlikely(restartFlag_))
        {
            beginAddrs_ = ICAddr_Read_Status0;
            length_ = readLeangth;
            restartFlag_  = false;
            statusValueMap_.SetLocalStatus(ICParametersCache::kIsReadAllStatus, false);
        }
        else
        {
            int tmp = beginAddrs_ + readLeangth;
            if( tmp < ICAddr_Read_Section_End)
            {
                beginAddrs_ = static_cast<ICAddr>(tmp);
            }
            int tmpLength = ICAddr_Read_Section_End - tmp;
            if(tmpLength <= readLeangth)
            {
                length_ = tmpLength;
                restartFlag_ = true;
                statusValueMap_.SetLocalStatus(ICParametersCache::kIsReadAllStatus, true);
            }
            else
            {
                length_ = readLeangth;
            }
        }
//#elif defined TCP_COMM
//        ICInjectionMachineTransceiverData *readData
//                = new ICInjectionMachineTransceiverData(kHostID,
//                                                        FunctionCode_ReadAddr,
//                                                        ICAddr_Read_Status,
//                                                        ReadLength);
//        AddCommunicationFrame(readData);
//#endif
    }
    Transceiver()->Write(queue_.Head());
    //    qDebug()<<testTime.restart();
#ifdef TEST_TIME_DEBUG
    /*TIME_TEST*/
    if(time.elapsed() >= TEST_TIME_LEVEL)
    {
        qDebug()<<"InjectionMachine Host communicate time test"<<time.restart()<<"ms";
    }
#endif
}

static bool PairLess(const QPair<int, quint32>& l, const QPair<int, quint32>& r)
{
    return l.first < r.first;
}

bool ICInjectionMachineHost::InitConfigsImpl(const QVector<QPair<int, quint32> > &configList, int startAddr)
{
//    ICInjectionMachineTransceiverData *tdata = new ICInjectionMachineTransceiverData();
//     tdata->SetFunctionCode(81);
//     tdata->SetHostID(1);
//     tdata->SetLength(1);
//     tdata->SetAddr(25);
//     QVector<quint32> db;
//      db<<2;
//             tdata->SetData(db);
//             AddCommunicationFrame(tdata);
    if(startAddr < 2)
    {
        return false;
    }
    QVector<QPair<int, quint32> > configs = configList;
    qSort(configs.begin(), configs.end(), PairLess);
    int st = configs.size();
    for(int i = 0; i != configs.size(); ++i)
    {
        if(configs.at(i).first >= (startAddr))
        {
            st = i;
            break;
        }
    }
    configs = configs.mid(st);
    if(configs.size() + startAddr > ICAddr_Write_Section_End)
    {
        return false;
    }
    if(configs.isEmpty())
    {
        return false;
    }
    QMap<int, int> startIndexToSize;
    int sa = configs.at(0).first;
    st = 1;
    int addr;
    for(int i = 1; i != configs.size(); ++i)
    {
        if(st == 1)
        {
            addr = sa;
        }
        if(configs.at(i).first - sa > 1)
        {
            startIndexToSize.insert(addr, st);
            st = 1;
            sa = configs.at(i).first;
            startIndexToSize.insert(sa, st);
            addr = sa;
            continue;
        }
        ++sa;
        ++st;
    }
    startIndexToSize.insert(addr, st);
    QMap<int, int>::iterator p = startIndexToSize.begin();
    QVector<quint32> tempDataBuffer;
    QVector<QPair<int, quint32> > midConfigs;
    ICInjectionMachineTransceiverData *data;
    while(p != startIndexToSize.end())
    {
        //        int size = configs.size();
        int size = p.value();
        const int length = 16;
        const int shift = 4;
        int splitCount = qCeil(size / static_cast<qreal>(length));
        for(int i = 0; i != splitCount; ++i)
        {
            data = new ICInjectionMachineTransceiverData();
            data->SetHostID(kHostID);
            data->SetFunctionCode(FunctionCode_WriteAddr);
            data->SetAddr(static_cast<ICAddr>(p.key() + (i << shift)) /* *64 */);
            if( i == splitCount - 1)
            {
                data->SetLength(size - (i << shift));
            }
            else
            {
                data->SetLength(length);
            }
            midConfigs = configs.mid(i << shift, data->GetLength());
            tempDataBuffer.clear();
            for(int j = 0; j != midConfigs.size(); ++j)
            {
                tempDataBuffer.append(midConfigs.at(j).second);
            }
            data->SetData(tempDataBuffer);
            AddCommunicationFrame(data);
        }
        configs = configs.mid(size);
        ++p;
    }

    uint initEnd = 0;
    ICAddrWrapper::UpdateBaseAddrValue(&s_rw_3_1_0_25, 1, &initEnd);
    data = new ICInjectionMachineTransceiverData(kHostID,
                                                 FunctionCode_WriteAddr,
                                                 s_rw_3_1_0_25.BaseAddr(),
                                                 1,
                                                 ICInjectionMachineTransceiverData::ICTransceiverDataBuffer()<<initEnd);
    AddCommunicationFrame(data);

    return true;
}

void ICInjectionMachineHost::ResetCommunicate()
{
    this->blockSignals(false);
}

bool ICInjectionMachineHost::SetAddrValue(const ICAddrWrapper *addr, int value)
{
    statusValueMap_.UpdateConfigValue(addr, value);
    return true;
//    if(!statusValueMap_.contains(addr->BaseAddr()))
//    {
//        return false;
//    }
//    uint originV = statusValueMap_.value(addr->BaseAddr());
//    ICAddrWrapper::UpdateBaseAddrValue(addr, value, &originV);
//    InsertStatusToStatusMap_(addr->BaseAddr(), originV);
//    return true;
}

void ICInjectionMachineHost::AddReadConfigCommunicationFrame_(ICVirtualHostPtr hostPtr)
{
//#if defined UART_COMM
    ICInjectionMachineTransceiverData *readData
            = new ICInjectionMachineTransceiverData(kHostID,
                                                    FunctionCode_ReadAddr,
                                                    beginAddrs_,
                                                    length_);
    int readLeangth = ReadLength;
    hostPtr->AddCommunicationFrame(readData);
    if(unlikely(restartFlag_))
    {
        beginAddrs_ = ICAddr_Read_Status0;
        length_ = readLeangth;
        restartFlag_  = false;
    }
    else
    {
        int tmp = beginAddrs_ + readLeangth;
        if( tmp < ICAddr_Read_Section_End)
        {
            beginAddrs_ = static_cast<ICAddr>(tmp);
        }
        int tmpLength = ICAddr_Read_Section_End - tmp;
        if(tmpLength <= readLeangth)
        {
            length_ = tmpLength;
            restartFlag_ = true;
        }
        else
        {
            length_ = readLeangth;
        }
    }
//#elif defined TCP_COMM
//    ICInjectionMachineTransceiverData *readData
//            = new ICInjectionMachineTransceiverData(kHostID,
//                                                    FunctionCode_ReadAddr,
//                                                    ICAddr_Read_Status,
//                                                    ReadLength);
//    hostPtr->AddCommunicationFrame(readData);
//#endif
}

void ICInjectionMachineHost::StopCommunicate()
{
//#if defined UART_COMM
//    ICSerialTransceiver::Instance()->StopCommunicate();
//#elif defined TCP_COMM
    this->Transceiver()->StopCommunicate();
//#endif
    ICVirtualHost::StopCommunicate();
}

void ICInjectionMachineHost::StartCommunicate()
{
//#if defined UART_COMM
//    ICSerialTransceiver::Instance()->StartCommunicate();
//#elif defined TCP_COMM
    this->Transceiver()->StartCommunicate();
//#endif
    ICVirtualHost::StartCommunicate();
}

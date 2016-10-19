.pragma library
Qt.include("IODefines.js")
Qt.include("AxisDefine.js")

var ALARM_IO_OFF_SIGNAL_START = 0;   //<名字：IO输入等待OFF时间内未检测到信号
var ALARM_IO_ON_SIGNAL_START = 1;    //<名字：IO输入等待ON时间内未检测到信号
var ALARM_SINGLE_OFF_START = 2;//<名字：单头阀IO输入检测ON时间内未检测到信号
var ALARM_SINGLE_ON_START = 3;//<名字：单头阀IO输入检测ON时间内未检测到信号
var ALARM_DOUBLE_OFF_START = 4;  //<名字：双头阀IO输入检测时间内未检测到信号
var ALARM_DOUBLE_ON_START = 5;//<名字：双头阀IO输入检测时间内未检测到信号
var NORMAL_TYPE = 9;

var m0Name = axisInfos[0].name;
var m1Name = axisInfos[1].name;
var m2Name = axisInfos[2].name;
var m3Name = axisInfos[3].name;
var m4Name = axisInfos[4].name;
var m5Name = axisInfos[5].name;


var alarmInfo = {
    1:qsTr("ALARM_MACHINE_ADJUST"), //<名字：机械调整中
    2:qsTr("ALARM_MOTOR_RUNING"), //<名字：马达启动中
    3:qsTr("ALARM_AUTO_PURGING"), //<名字：自动清料中
    4:qsTr("ALARM_IO_TURNING"), //<名字：IO转向中
    5:qsTr("ALARM_IO_SIMULATING"), //<名字：IO模拟中
    6:qsTr("ALARM_NEXTMOLDSTOP"), //<名字：下一模停机
    7:qsTr("ALARM_KEEP_WARM_STATE"), //<名字：保温状态中
    8:qsTr("ALARM_PLEASE_OPEN_SAVEDOOR"), //<名字：请开安全门
    9:qsTr("ALARM_PLEASE_CLOSE_SAVEDOOR"), //<名字：请关安全门
    10:qsTr("ALARM_PLEASE_PRESS_AUTO_RUN"), //<名字：请按运行键
    11:qsTr("ALARM_COMMUNICATION_ANOMALY"), //<名字：通讯异常
    12:qsTr("ALARM_CORE1_IN_NOT_USE"), //<名字：抽芯A入未使用
    13:qsTr("ALARM_CORE2_IN_NOT_USE"), //<名字：抽芯B入未使用
    14:qsTr("ALARM_CORE3_IN_NOT_USE"), //<名字：抽芯C入未使用
    15:qsTr("ALARM_CORE4_IN_NOT_USE"), //<名字：抽芯D入未使用
    16:qsTr("ALARM_CORE1_OUT_NOT_USE"), //<名字：抽芯A出未使用
    17:qsTr("ALARM_CORE2_OUT_NOT_USE"), //<名字：抽芯B出未使用
    18:qsTr("ALARM_CORE3_OUT_NOT_USE"), //<名字：抽芯C出未使用
    19:qsTr("ALARM_CORE4_OUT_NOT_USE"), //<名字：抽芯D出未使用
    20:qsTr("ALARM_EJECT_NOT_CHOOSE"), //<名字：顶针未使用
    21:qsTr("ALARM_AIR_EJECT_M_NOT_USE"), //<名字：动模吹气未使用
    22:qsTr("ALARM_AIR_EJECT_F_NOT_USE"), //<名字：静模吹气未使用
    23:qsTr("ALARM_PLEASE_HEATER"), //<名字：请加热
    24:qsTr("ALARM_MOLD_PLACE_ERR"), //<名字：动模位置器故障
    25:qsTr("ALARM_INJECT_PLACE_ERR"), //<名字：射出位置器故障
    26:qsTr("ALARM_NOZZLE_PLACE_ERR"), //<名字：射座位置器故障
    27:qsTr("ALARM_EJECT_PLACE_ERR"), //<名字：顶针位置器故障
    28:qsTr("ALARM_MOTOR_NOTRUN"), //<名字：马达未启动
    29:qsTr("ALARM_EJECT_RET_NOT_ARRIVAL"), //<名字：顶退未到位
    30:qsTr("ALARM_MOLD_OPEN_NOT_IN_PLACE"), //<名字：开模未到位
    31:qsTr("ALARM_WAIT_NEXT_SEMIAUTORUN"), //<名字：请开安全门，等待下一次半自动启动
    32:qsTr("ALARM_AUTO_PURGE_DONE"), //<名字：自动清料完成
    33:qsTr("ALARM_INJECTIONSHIELD_OPEN"), //<名字：射出防护罩
    34:qsTr("ALARM_TEMPERATURE_CONVERT_FALSE"), //<名字：温度采集失败
    35:qsTr("ALARM_MOLD_HIGHPRESS_ERR"), //<名字：高压锁模位置错误
    36:qsTr("ALARM_FRONTDOOR_OPEN"), //<名字：前安全门开
    37:qsTr("ALARM_MOTORSTARTPROTECTTIMEUP"), //<名字：马达启动保护时间到
    38:qsTr("ALARM_NOZZLEADV_PROTECT_TIME"), //<名字：座进保护时间到
    39:qsTr("ALARM_SYSTEM_PRESS_SET_ERR"), //<名字：系统压最大值设置错误
    40:qsTr("ALARM_SYSTEM_SPEED_SET_ERR"), //<名字：流量最大值设置错误
    41:qsTr("ALARM_SYSTEM_BACKPRESS_SET_ERR"), //<名字：背压最大值设置错误
    42:qsTr("ALARM_TELEDIPGAUGE_ERR"), //<名字：电子尺长度设置错误
    43:qsTr("ALARM_OILCANJOURNEY_AD_VALUE_ERR"), //<名字：油缸最大、最小AD值设置错误
    44:qsTr("ALARM_MOLD_THIN_LIMIT"), //<名字：达到调模进极限
    45:qsTr("ALARM_MOLD_THICK_LIMIT"), //<名字：达到调模退极限
    46:qsTr("ALARM_MOLD_THICKNESS_DONE"), //<名字：自动调模完成
    47:qsTr("ALARM_SCREW_PROTECT"), //<名字：镙杆保护
    48:qsTr("ALARM_NOT_REACH_NORMAL_TEMPRATURE"), //<名字：料温未到正常温度
    49:qsTr("ALARM_EMERGENCY_STOP"), //<名字：紧急停止
    50:qsTr("ALARM_TAKEOUT_NOPRODUCT"),
    51:qsTr("ALARM_SAVE_RELAY_ERR"),
    52:qsTr("ALARM_PLEASE_RESET"),
    53:qsTr("ALARM_STORING_PRESS"),
    54:qsTr("ALARM_SPECIALCOREALLOW"),
    55:qsTr("ALARM_POORPRODUCT_SERIES"),
    56:qsTr("ALARM_NOZZLE_NOTLOCATE"),
    57:qsTr("ALARM_AUTO_ADJUST_PLACE"),
    58:qsTr("ALARM_IO_OUT_ERR"),
    59:qsTr("ALARM_MOLD_ADJUST_LIMIT"),
    60:qsTr("ALARM_TAKEOUT_WARM"), //
    61:qsTr("ALARM_ELECTRIC_EYE_PROTECT"), //<名字：电眼保护时间到
    62:qsTr("ALARM_ELECTRIC_EYE_SHUTOUT"), //<名字：电眼遮住时间过长
    63:qsTr("ALARM_MOLDCLOSE_POS_ERR"), //<名字：关模位置参数设定错误
    64:qsTr("ALARM_MOLDCLOSE_P_ERR"), //<名字：关模压力参数设定错误
    65:qsTr("ALARM_MOLDCLOSE_S_ERR"), //<名字：关模流量参数设定错误
    66:qsTr("ALARM_MOLDOPEN_POS_ERR"), //<名字：开模位置参数设定错误
    67:qsTr("ALARM_MOLDOPEN_P_ERR"), //<名字：开模压力参数设定错误
    68:qsTr("ALARM_MOLDOPEN_S_ERR"), //<名字：开模流量参数设定错误
    69:qsTr("ALARM_INJECT_POS_ERR"), //<名字：射出位置参数设定错误
    70:qsTr("ALARM_INJECT_P_ERR"), //<名字：射出压力参数设定错误
    71:qsTr("ALARM_INJECT_S_ERR"), //<名字：射出流量参数设定错误
    72:qsTr("ALARM_NOZZLE_POS_ERR"), //<名字：座台位置参数设定错误
    73:qsTr("ALARM_NOZZLE_P_ERR"), //<名字：座台压力参数设定错误
    74:qsTr("ALARM_NOZZLE_S_ERR"), //<名字：座台流量参数设定错误
    75:qsTr("ALARM_CHARGE_POS_ERR"), //<名字：加料位置参数设定错误
    76:qsTr("ALARM_CHARGE_P_ERR"), //<名字：加料压力参数设定错误
    77:qsTr("ALARM_CHARGE_S_ERR"), //<名字：加料流量参数设定错误
    78:qsTr("ALARM_EJECT_POS_ERR"), //<名字：顶针位置参数设定错误
    79:qsTr("ALARM_EJECT_P_ERR"), //<名字：顶针压力参数设定错误
    80:qsTr("ALARM_EJECT_S_ERR"), //<名字：顶针流量参数设定错误
    81:qsTr("ALARM_CORE_POS_ERR"), //<名字：抽芯位置参数设定错误
    82:qsTr("ALARM_CORE_P_ERR"), //<名字：抽芯压力参数设定错误
    83:qsTr("ALARM_CORE_S_ERR"), //<名字：抽芯流量参数设定错误
    84:qsTr("ALARM_AIR_POS_ERR"), //<名字：吹风位置参数设定错误
    85:qsTr("ALARM_AIR_S_ERR"), //<名字：吹风流量参数设定错误
    86:qsTr("ALARM_ADJUST_ERR"), //<名字：调模参数设定错误
    87:qsTr("ALARM_TEMPERATURE_ERR"), //<名字：温度参数设定错误
    88:qsTr("ALARM_LOW_PRODUCT_ERR"), //<名字：低压保护时间参数设定错误
    89:qsTr("ALARM_RESERVE0_ERR"), //<名字：预留
    90:qsTr("ALARM_NOT_ALOW_AUTO_ERR"), //<名字：顶针停留模式不允许全自动
    91:qsTr("ALARM_PRODUCT_TIPS"), //<名字：生产提示

    95:qsTr("ALARM_SYSTEM_NOT_INIT"),

    // 报警1等级，闪灯，发声，不切马达，触发报警计时器计时
    96:qsTr("ALARM_MOLD_OPEN_OVERTIME"), //<名字：开模超时
    97:qsTr("ALARM_ONE_BOX_MOLD_NUMBER"), //<名字：装箱模数到
    98:qsTr("ALARM_INJECT_ANOMALY"), //<名字：射胶异常
    99:qsTr("ALARM_PRODUCT_MAXIMUM"), //<名字：达到生产总数
    100:qsTr("ALARM_GOODPRODUCT_NUMBER"), //<名字：达到良品总数
    101:qsTr("ALARM_POORPRODUCT_MAXIMUM"), //<名字：达到劣品总数
    102:qsTr("ALARM_CHARGE_ANOMALY"), //<名字：加料异常
    103:qsTr("ALARM_LOWPRESS_PROTECT"), //<名字：低压保护中
    104:qsTr("ALARM_CYCLE_OVERLONG"), //<名字：周期过长
    105:qsTr("ALARM_BACKDOOR_OPEN"), //<名字：后安全门开
    106:qsTr("ALARM_PLASTIC_TEMPRATURE_HIGH"), //<名字：料温过高
    107:qsTr("ALARM_OILLEACHNET_DIRTY"), //<名字：滤油网脏
    108:qsTr("ALARM_LUBRICATE_OIL_LOW"), //<名字：润滑油位低
    109:qsTr("ALARM_LUBRICATE1_PRESS_NOT_ARRIVA"), //<名字：润滑压力未到
    110:qsTr("ALARM_LUBRICATE2_PRESS_NOT_ARRIVA"), //
    111:qsTr("ALARM_LUBRICATE_ANOMALY"), //<名字：润滑异常
    112:qsTr("ALARM_OIL_TEMPRATURE_60"), //<名字：油温达到60度
    113:qsTr("ALARM_OIL_TEMPRATURE_70"), //<名字：油温达到70度
    114:qsTr("ALARM_THERMOCOUPLE_INJECT_CUT_OFF"), //<名字：喷嘴热电偶断线
    115:qsTr("ALARM_THERMOCOUPLE_SEG1_CUT_OFF"), //<名字：第一段热电偶断线
    116:qsTr("ALARM_THERMOCOUPLE_SEG2_CUT_OFF"), //<名字：第二段热电偶断线
    117:qsTr("ALARM_THERMOCOUPLE_SEG3_CUT_OFF"), //<名字：第三段热电偶断线
    118:qsTr("ALARM_THERMOCOUPLE_SEG4_CUT_OFF"), //<名字：第四段热电偶断线
    119:qsTr("ALARM_THERMOCOUPLE_SEG5_CUT_OFF"), //<名字：第五段热电偶断线
    120:qsTr("ALARM_THERMOCOUPLE_SEG6_CUT_OFF"), //<名字：第六段热电偶断线
    121:qsTr("ALARM_THERMOCOUPLE_OIL_CUT_OFF"), //<名字：油温热电偶断线
    122:qsTr("ALARM_MOLD_STILL_HIGHPRESS_LOCKUP"), //<名字：模具仍被高压锁住
    123:qsTr("ALARM_OIL_TEMPRATURE_HIGH"), //<名字：油温过高
    124:qsTr("ALARM_MOTOR_OVERLOAD"), //<名字：马达过载
    125:qsTr("ALARM_PLASTIC_TEMPRATURE_LOW"), //<名字：料温过低
    126:qsTr("ALARM_SERVO_ERR"), //<名字：伺服驱动器故障
    127:qsTr("ALARM_VIOLATION_SAFE_ERR"), //<名字：违反安全操作

    // 报警2等级，闪灯，发声，切马达
    160:qsTr("ALARM_TIME_OUT"), //<名字：报警计时到
}

var alarmDetails = {
    "1":"1",
    "2":"2",
    "3":"3",
    "4":"4",
    "5":"5",
    "6":"6",
}

function analysisAlarmNum(errNum){
    return {
        "type":(errNum < 2048 ? NORMAL_TYPE: (errNum >> 8) & 0x7),
        "board":(errNum >> 5) & 0x7,
        "point":(errNum & 0x1F)
    };
}

function isWaitONAlarmType(errNum){
    if(errNum >= 2048)
    {
        return ((errNum >> 8) & 0x7) == ALARM_IO_ON_SIGNAL_START;
    }
    return false;
}

function getAlarmDescr(errNum){
    if(alarmInfo.hasOwnProperty(errNum.toString())){
        return alarmInfo[errNum.toString()];
    }else if(customAlarmInfo.hasOwnProperty(errNum.toString())){
        return customAlarmInfo[errNum.toString()];
    }else{
        var alarm = analysisAlarmNum(errNum);
        if(alarm.type === ALARM_IO_ON_SIGNAL_START){
            return qsTr("Wait Input:") + getXDefineFromHWPoint(alarm.point, alarm.board).xDefine.descr + qsTr("ON over time")
        }else if(alarm.type === ALARM_IO_OFF_SIGNAL_START){
            return qsTr("Wait Input:") + getXDefineFromHWPoint(alarm.point, alarm.board).xDefine.descr + qsTr("OFF over time")
        }else if(alarm.type === ALARM_SINGLE_ON_START){
            return qsTr("Wait Single Input:") + getValveItemFromValveID(alarm.point).descr + qsTr("ON over time")
        }else if(alarm.type === ALARM_SINGLE_OFF_START){
            return qsTr("Wait Single Input:") + getValveItemFromValveID(alarm.point).descr + qsTr("OFF over time")
        }
        else if(alarm.type === ALARM_DOUBLE_ON_START){
            return qsTr("Wait Double Input:") + getValveItemFromValveID(alarm.point).descr + qsTr("ON over time")
        }else if(alarm.type === ALARM_DOUBLE_OFF_START){
            return qsTr("Wait Double Input:") + getValveItemFromValveID(alarm.point).descr + qsTr("OFF over time")
        }
    }

    return "";
}

var customAlarmInfo = {
    "5000":qsTr("5000"),
    "5001":qsTr("5001"),
    "5002":qsTr("5002"),
    "5003":qsTr("5003"),
    "5004":qsTr("5004"),
    "5005":qsTr("5005"),
    "5006":qsTr("5006"),
    "5007":qsTr("5007"),
    "5008":qsTr("5008"),
    "5009":qsTr("5009"),
    "5010":qsTr("5010"),
    "5011":qsTr("5011"),
    "5012":qsTr("5012"),
    "5013":qsTr("5013"),
    "5014":qsTr("5014"),
    "5015":qsTr("5015"),
    "5016":qsTr("5016"),
    "5017":qsTr("5017"),
    "5018":qsTr("5018"),
    "5019":qsTr("5019"),
    "5020":qsTr("5020"),
}

function getCustomAlarmDescr(errNum){
    if(customAlarmInfo.hasOwnProperty(errNum.toString())){
        return customAlarmInfo[errNum.toString()];
    }
    return qsTr("Unknow Err");
}

function getAlarmDetail(errNum){
    if(errNum == 9){
        return qsTr("1.Connector loose\n2.Wire is off\n3.Pannel is broken\n4.Host is broken")
    }

    return qsTr("None");
}

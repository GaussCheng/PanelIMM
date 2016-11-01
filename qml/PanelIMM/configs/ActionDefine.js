.pragma library
Qt.include("../../utils/HashTable.js")

var aHelper = 0;
var ACTION_NULL = aHelper++; //< 无动作
var ACTION_MANUAL = aHelper++; //< 手动模式
var ACTION_SEMI_AUTO = aHelper++; //< 半自动模式
var ACTION_AUTO = aHelper++; //< 全自动模式
var ACTION_HEAT = aHelper++; // 加热
var ACTION_MOTOR_RUN = aHelper++; // 马达
var ACTION_AUTO_RUN = aHelper++; // 全自动运行
var ACTION_MANUAL_LUBRICATE = aHelper++; // 手动润滑
var ACTION_MOLD_CLOSE = aHelper++; //< 关模动作
var ACTION_NOZZLE_ADV = aHelper++; //< 座进动作
var ACTION_NOZZLE_RET = aHelper++; //< 座退动作
var ACTION_INJECT_IN = aHelper++; //< 射进动作
var ACTION_INJECT_BACK = aHelper++; //< 射退动作
var ACTION_CHARGE = aHelper++; //< 加料动作
var ACTION_AUTO_PURGE = aHelper++; //< 清料动作
var ACTION_CORE1_IN = aHelper++; //< 抽芯A入动作
var ACTION_CORE1_OUT = aHelper++; //< 抽芯A出动作
var ACTION_CORE2_IN = aHelper++; //< 抽芯B入动作
var ACTION_CORE2_OUT = aHelper++; //< 抽芯B出动作
var ACTION_CORE3_IN = aHelper++; //< 抽芯C入动作
var ACTION_CORE3_OUT = aHelper++; //< 抽芯C出动作
var ACTION_CORE4_IN = aHelper++; //< 抽芯D入动作
var ACTION_CORE4_OUT = aHelper++; //< 抽芯D出动作
var ACTION_MOLD_OPEN = aHelper++; //< 开模动作
var ACTION_EJECT_ADV = aHelper++; //< 顶进动作
var ACTION_EJECT_RET = aHelper++; //< 顶退动作
var ACTION_MOLD_THICKNESS = aHelper++; //< 调模使用
var ACTION_MOLD_THIN = aHelper++; //< 调模进
var ACTION_MOLD_THICK = aHelper++; //< 调模退
var ACTION_AUTO_MOLD_ADJ = aHelper++; //< 自动调模
var ACTION_AIR_EJECT_MOV = aHelper++; //< 公模吹气
var ACTION_AIR_EJECT_STN = aHelper++; //< 母模吹气
var ACTION_PRODUCTCLEAR = aHelper++; //< 计数清零
var ACTION_BADPRODUCTCLEAR = aHelper++; //< 劣品清零
var ACTION_MOLDCLEAR = aHelper++; //< 模数归零
var ACTION_CONFIRMATION_ALARM = aHelper++; //< 警报确认

var keyToAction = (function(){
    var ret = {};
    for(var i = 0; i < aHelper; ++i){
        ret[0x01000030 + i] = i;
    }
    return ret;
}());

var getActionFromKey = function(key){
    if(keyToAction.hasOwnProperty(key)){
        return keyToAction[key];
    }
    return ACTION_NULL;
}

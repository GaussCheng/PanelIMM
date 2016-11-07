import QtQuick 1.1

ICCheckBox{
    property string configAddr: ""
    property string configValue: ""
    onConfigValueChanged: {
        var cS = isTristate ? 2 : 1;
        isChecked = parseInt(configValue) === cS;
        checkState = parseInt(configValue);
    }
    onCheckStateChanged: {
        configValue = checkState;
    }

//    onIsCheckedChanged: {
//        configValue = isChecked ? "1" : "0";
//    }
}

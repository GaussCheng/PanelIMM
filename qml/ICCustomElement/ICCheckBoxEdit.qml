import QtQuick 1.1

ICCheckBox{
    property string configAddr: ""
    property string configValue: ""
    onConfigValueChanged: {
        isChecked = parseInt(configValue) === 2;
        checkState = parseInt(configValue);
    }
    onCheckStateChanged: {
        configValue = checkState;
    }

//    onIsCheckedChanged: {
//        configValue = isChecked ? "1" : "0";
//    }
}

import QtQuick 1.1
import "../styles/style.js" as Style

ICEditableItemBase {
    id:instance
    property alias text: lineEdit.text
    property string configValue: ""

    property string configAddr: ""
    property alias horizontalAlignment: lineEdit.horizontalAlignment
    property bool softkeyboardEn: false
    property alias font: lineEdit.font
    tip: "00:00-->23:59"

    QtObject{
        id:pData
        property int currentPos: 0
    }

    onConfigValueChanged: {
        var d = 4 - configValue.length;
        var endV = "";
        for(var i = 0; i < d; ++i){
            endV += "0"
        }
        endV += configValue;
        if(endV !== lineEdit.text){
            lineEdit.text = endV.slice(0,2) + ":" + endV.slice(2,4);
        }
    }

    onConfigAddrChanged: {
//        var rg = JSON.parse(panelController.configRange(configAddr));
//        min = rg.min;
//        max = rg.max;
//        decimal = rg.decimal;
    }

    width: 100
    height: 24
    border.color: Style.itemStyles.ICTimeLineEdit.border.color
    border.width: Style.itemStyles.ICTimeLineEdit.border.width

    state: {
        if(!enabled) return "disabled";
        if(activeFocus) return "focused";
        return "";
    }

    states: [
        State {
            name: "disabled"
            PropertyChanges { target: instance; color:Style.itemStyles.ICTimeLineEdit.disabled.bgColor;}
            PropertyChanges { target: lineEdit; color:Style.itemStyles.ICTimeLineEdit.disabled.fontColor;}

        },
        State{
            name: "focused"
            PropertyChanges { target: instance; color:Style.itemStyles.ICTimeLineEdit.focused.bgColor;}
            PropertyChanges { target: lineEdit; color:Style.itemStyles.ICTimeLineEdit.focused.fontColor;}
        }

    ]

    function isEmpty(){
        return text.length == 0;
    }

    function getValue(){
        return parseFloat(lineEdit.text);
    }

    Text {
        property bool selectAll: false
        property bool modified: false
        property string regExp: '^(([0-1]\d)|(2[0-4])):[0-5]\d$'
        id: lineEdit
        x:4
        width: parent.width
        anchors.verticalCenter: parent.verticalCenter
    }

    onActiveFocusChanged: {
        if(activeFocus){
            lineEdit.selectAll = true;
        }
        else if(lineEdit.modified)
            editFinished();

    }
    onEditFinished: {
        if(isNumberOnly){
//            var v = parseFloat(lineEdit.text);
//            if(v < min) v = min;
//            if(v > max) v = max;
//            lineEdit.text = parseFloat(v).toFixed(decimal);
        }
        lineEdit.modified = false;
    }

    Keys.onPressed: {

    }
}

import QtQuick 1.1
import "../styles/style.js" as Style

ICEditableItemBase{
    id:instance
    property alias text: lineEdit.text
    property alias configValue: lineEdit.text
    property string configAddr: ""
    property alias unit: unit.text
    property alias horizontalAlignment: lineEdit.horizontalAlignment
    property bool isNumberOnly: true
    property bool softkeyboardEn: false
    property double min : 0
    property double max: 4000000000
    property int decimal: 0
    property alias font: lineEdit.font
    tip: min.toFixed(decimal) + "-->" + max.toFixed(decimal)

    onConfigAddrChanged: {
        var rg = JSON.parse(panelController.configRange(configAddr));
        min = rg.min;
        max = rg.max;
        decimal = rg.decimal;
    }

    width: 100
    height: 24
    border.color: Style.itemStyles.ICLineEdit.border.color
    border.width: Style.itemStyles.ICLineEdit.border.width

    state: {
        if(!enabled) return "disabled";
        if(activeFocus) return "focused";
        return "";
    }

    states: [
        State {
            name: "disabled"
            PropertyChanges { target: instance; color:Style.itemStyles.ICLineEdit.disabled.bgColor;}
            PropertyChanges { target: lineEdit; color:Style.itemStyles.ICLineEdit.disabled.fontColor;}

        },
        State{
            name: "focused"
            PropertyChanges { target: instance; color:Style.itemStyles.ICLineEdit.focused.bgColor;}
            PropertyChanges { target: lineEdit; color:Style.itemStyles.ICLineEdit.focused.fontColor;}
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
        property string regExp: '^[+-]*\\d{0,9}(\\.\\d{0,' + decimal + '})?$'
        id: lineEdit
        x:Style.itemStyles.ICLineEdit.lrMargin
        width: parent.width - unit.width - Style.itemStyles.ICLineEdit.lrMargin * 3 // 4 * 3
        anchors.verticalCenter: parent.verticalCenter
    }
    Text {
        id: unit
        anchors.right: parent.right
        anchors.rightMargin: Style.itemStyles.ICLineEdit.lrMargin
        color: lineEdit.color
        y:lineEdit.y
        anchors.verticalCenter: parent.verticalCenter
    }

    onActiveFocusChanged: {
        if(activeFocus){
            lineEdit.selectAll = true;
            ma.showSoftKeyboard();
        }
        else if(lineEdit.modified)
            editFinished();

    }
    onEditFinished: {
        if(isNumberOnly){
            var v = parseFloat(lineEdit.text);
            if(v < min) v = min;
            if(v > max) v = max;
            lineEdit.text = parseFloat(v).toFixed(decimal);
        }
        lineEdit.modified = false;
    }

    MouseArea{
        anchors.fill: parent
        id:ma
        function onCommit(text){
//            console.log(text)
            lineEdit.text = text;
            editFinished();
            virtualKeyboard.commit.disconnect(ma.onCommit);
            virtualKeyboard.reject.disconnect(ma.onReject);
        }

        function onReject(){
            virtualKeyboard.commit.disconnect(ma.onCommit);
            virtualKeyboard.reject.disconnect(ma.onReject);
        }
        function showSoftKeyboard(){
            if(softkeyboardEn){
                var p = parent.mapToItem(null, lineEdit.x, lineEdit.y);
                if(configAddr.length != 0){
                    virtualKeyboard.openSoftPanel(p.x,
                                                  p.y,
                                                  lineEdit.width,
                                                  lineEdit.height,
                                                  isNumberOnly,
                                                  configAddr,
                                                  true);
                }else if(isNumberOnly){
                    virtualKeyboard.openSoftPanel(p.x, p.y, lineEdit.width, lineEdit.height, min, max, decimal);
                }else{
                    virtualKeyboard.openSoftPanel(p.x, p.y, lineEdit.width, lineEdit.height,isNumberOnly);
                }
                virtualKeyboard.commit.connect(ma.onCommit);
                virtualKeyboard.reject.connect(ma.onReject);
            }
        }

        onClicked: {
            parent.focus = true;
            ma.showSoftKeyboard();
        }
    }

    Keys.onPressed: {
        var t = lineEdit.text;
        if(event.key == Qt.Key_Backspace){
            if(t.length == 0) return;
            if(lineEdit.selectAll)
                t = "";
            else
                t = t.substring(0, t.length - 1);
        }else if(event.key == Qt.Key_Return){
            lineEdit.selectAll = true;

            editFinished();
            return;
        }else{
            if(lineEdit.selectAll)
                t = event.text;
            else
                t += event.text;
        }
        if(isNumberOnly){
            var re = new RegExp(lineEdit.regExp);
            if(!re.test(t)) return;
            var vt = parseFloat(t);
            if(vt > max) return;
        }
        lineEdit.text = t;
        lineEdit.selectAll = false;
        lineEdit.modified = true;
    }
}

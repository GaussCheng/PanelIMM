import QtQuick 1.1

ICEditableItemBase{
    id:instance
    property alias text: lineEdit.text
    property string bindConfig: ""
    property alias unit: unit.text
    property alias horizontalAlignment: lineEdit.horizontalAlignment
    property bool isNumberOnly: true
    property double min : 0
    property double max: 4000000000
    property int decimal: 0
    tip: min + "-->" + max

    width: 100
    height: 24
    border.color: "gray"
    border.width: 1

    signal editFinished();

    state: {
        if(!enabled) return "disabled";
        if(activeFocus) return "focused";
        return "";
    }

    states: [
        State {
            name: "disabled"
            PropertyChanges { target: instance; color:"gray";}
            PropertyChanges { target: lineEdit; color:"gainsboro";}

        },
        State{
            name: "focused"
            PropertyChanges { target: instance; color:"blue";}
            PropertyChanges { target: lineEdit; color:"white";}
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
        x:4
        width: parent.width - unit.width - 12 // 4 * 3
        anchors.verticalCenter: parent.verticalCenter
    }
    Text {
        id: unit
        anchors.right: parent.right
        anchors.rightMargin: 4
        color: lineEdit.color
        y:lineEdit.y
    }

    onActiveFocusChanged: {
        if(activeFocus)
            lineEdit.selectAll = true;
        else if(lineEdit.modified)
            editFinished();

    }
    onEditFinished: {
        lineEdit.text = parseFloat(lineEdit.text).toFixed(decimal);
    }

    MouseArea{
        anchors.fill: parent
        onClicked: {
            parent.focus = true;
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
            if(vt < min || vt > max) return;
        }
        lineEdit.text = t;
        lineEdit.selectAll = false;
        lineEdit.modified = true;
    }

//    Rectangle {
//        id:rectangle
//        border.color: "black"
//        border.width: 1
//        //        width: parent.width - unit.width
//        width: 80
//        height: parent.height
//        enabled: parent.enabled
//        TextInput{
//            enabled: parent.enabled
//            function onFocus(isActive){
//                if(isActive){
//                    var p = parent.mapToItem(null, input.x, input.y);
//                    if(bindConfig.length != 0){
//                        virtualKeyboard.openSoftPanel(p.x,
//                                                      p.y,
//                                                      input.width,
//                                                      input.height,
//                                                      isNumberOnly,
//                                                      bindConfig,
//                                                      true);
//                    }else if(isNumberOnly){
//                        virtualKeyboard.openSoftPanel(p.x, p.y, input.width, input.height, min, max, decimal);
//                    }else{
//                        virtualKeyboard.openSoftPanel(p.x, p.y, input.width, input.height,isNumberOnly);
//                    }
//                    rectangle.color = "green";
//                    virtualKeyboard.commit.disconnect(onCommit);
//                    virtualKeyboard.reject.disconnect(onReject);
//                    virtualKeyboard.commit.connect(onCommit);
//                    virtualKeyboard.reject.connect(onReject);
//                }else{
//                    rectangle.color = "white";
//                    virtualKeyboard.commit.disconnect(onCommit);
//                    virtualKeyboard.reject.disconnect(onReject);

//                }

//            }

//            function onCommit(text){
//                //                console.log(text)
//                input.text = text;
//                input.focus = false;
//                editFinished();
//            }

//            function onReject(){
//                input.focus = false;
//            }

//            id:input
//            color: "black"
//            //            width: parent.width
//            anchors.verticalCenter: parent.verticalCenter
//            anchors.rightMargin: 4
//            anchors.leftMargin: 4
//            anchors.right: {
//                if(alignMode == 1)
//                    return unit.left
//            }
//            anchors.left: {
//                if(alignMode == 0)
//                    return parent.left
//            }
//            onFocusChanged: onFocus(input.focus)
//        }
//        Text {
//            id: unit
//            anchors.left: parent.right
//            anchors.leftMargin: 2
//            anchors.verticalCenter: parent.verticalCenter
//            enabled: parent.enabled

//        }
//        MouseArea{
//            anchors.fill: parent
//            onClicked: {
//                input.focus = true;
//            }
//        }
//    }
}

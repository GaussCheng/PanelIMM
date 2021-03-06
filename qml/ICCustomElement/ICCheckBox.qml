import QtQuick 1.1
import "../styles/style.js" as Style

ICEditableItemBase {
    id:container
    property alias configName: text.text
    property alias text: text.text
    property bool isChecked: false
    property bool useCustomClickHandler: false
    property bool isEditable: true
    property int textPos: 0
    property alias font: text.font
    property alias textColor:text.color
    property bool isTristate: false
    property int checkState: 0

    signal clicked();

    function setChecked(isCheck){
        checkState = isCheck ? 2 : 0;
        container.isChecked = isCheck;
    }

    function setCheckState(state){
        container.checkState = state;
        isChecked = (checkState == 2);
    }

    function getChecked(){
        return checkState == 2;
    }

    width: text.width + box.width + 4
    height: 24
    color: Style.itemStyles.ICCheckBox.color
    Rectangle{
        id:box
        width: parent.height
        height: parent.height
        border.width: Style.itemStyles.ICCheckBox.box.border.width
        border.color: Style.itemStyles.ICCheckBox.box.border.color
        color: {
            if(parent.activeFocus) return Style.itemStyles.ICCheckBox.box.color.focused;
            return isChecked ? Style.itemStyles.ICCheckBox.box.color.checked :Style.itemStyles.ICCheckBox.box.color.normal
        }
//        focus: parent.activeFocus
        Image{
            id:checkedImage
            source: {
                if(isTristate){
                    if(checkState == 2)
                        return "images/checked.png";
                    else if(checkState == 1)
                        return "images/partiallyChecked.png";
                    return "";
                }else
                    return isChecked ? "images/checked.png" : "";
            }
            width:parent.width + 6 * Style.wRatio
            height:parent.height + 6 * Style.hRatio
            visible: checkState > 0
            y:-2
        }
    }
    Text {
        id: text
        text: "ICCheckBox"
        anchors.verticalCenter: parent.verticalCenter
        color: enabled ? "black" : "gray"
        x:box.x + box.width + 4
    }

    onTextPosChanged: {
        if(textPos == 0){
            box.x = 0
            text.x = box.x + box.width + 4
        }else if(textPos == 1){
            text.x = 0;
            box.x = text.x + text.width + 4
        }else if(textPos == 2){
            box.x = 0;
            text.anchors.horizontalCenter = container.horizontalCenter
        }
    }

    MouseArea{
        anchors.fill: parent

        onClicked: {
            parent.focus = true;
            if(useCustomClickHandler || !isEditable) return;
            if(isTristate){
                checkState = (checkState + 1) % 3;
                isChecked = (checkState == 2);
            }else{
                isChecked = !isChecked;
                checkState = isChecked ? 2 : 0;
            }
            parent.clicked();
            editFinished();
        }
    }
     Keys.onPressed: {
         if(event.key === Qt.Key_Return){
             isChecked = !isChecked;
             editFinished();
         }
     }
}

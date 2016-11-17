import QtQuick 1.1
import "../styles/style.js" as Style

ICEditableItemBase {
    id:container
    property variant items: []
    property int currentIndex: -1
    property int popupMode : 0
    property int itemHeight: 32
    property alias font: currentText.font
    property alias popupWidth: itemContainer.width
    property int popupHeight: 0

    property int innerZ: -1
    property int pHeight: parent.height
    property int rY: y

    function currentText(){
        return currentIndex < 0 ?  "" : items[currentIndex];
    }

    function text(index){
        if(index < 0 || index >= items.length) return "";
        return items[index];
    }

    width: 100
    height: 24

    border.width: Style.itemStyles.ICComboBox.border.width
    border.color: Style.itemStyles.ICComboBox.border.color

    state: {
        if(focus) return "focused";
        return enabled ? "" : "disabled"
    }

    states: [
        State {
            name: "disabled"
            PropertyChanges { target: container; color:Style.itemStyles.ICComboBox.color.disabled.bg;}
            PropertyChanges { target: currentText; color:Style.itemStyles.ICComboBox.color.disabled.fc;}

        },
        State{
            name: "focused"
            PropertyChanges { target: container; color:Style.itemStyles.ICComboBox.color.focused.bg;}
        }

    ]

    Text {
        id: currentText
        text:currentIndex < 0 ?  "" : items[currentIndex]
        anchors.verticalCenter : parent.verticalCenter
        x:4
        width: parent.width - dropDownBox.width
        elide: Text.ElideRight
    }
    Text {
        id:dropDownBox
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        text: "▼"
    }
    ListModel{
        id:itemModel
    }

    Text{
        id:widthHelper
        visible: false
    }

    Rectangle{
        id: itemContainer
//        width: parent.width
        border.width: parent.border.width
        border.color: parent.border.color
        ListView{
            id:view
            z:10
            y:1
            clip: true
            model: itemModel
            delegate: Text{
                height: itemHeight
                text: name
                verticalAlignment: Text.AlignVCenter
                x:4
                font: container.font
                MouseArea{
                    height: itemHeight
                    width: view.width
                    onClicked: {
                        if(view.currentIndex != index){
                            view.currentIndex = index;
                            currentIndex = index;
                            editFinished();
                        }
                        container.z = innerZ;
                        itemContainer.visible = false
                    }
                }
            }
            highlight: Rectangle {x:1;color: "lightsteelblue"; width: itemContainer.width - x;}
            highlightMoveDuration: 1
            width: parent.width
            height: parent.height - y
        }
        visible: false
        anchors.top: currentText.bottom
        onVisibleChanged: {
            if(visible){
                var realHeight = itemHeight * itemModel.count;
                height = popupHeight == 0 ? realHeight : Math.min(realHeight, popupHeight);
                var maxWidth = container.width - 10;
                var item;
                for(var i = 0; i < itemModel.count; ++i){
                    item = itemModel.get(i);
                    widthHelper.text = item.name;
                    if(widthHelper.width > maxWidth)
                        maxWidth = widthHelper.width;
                }
                width = maxWidth + 10;
            }
        }
        MouseArea{
            width: Style.mainWindow.rect.width
            height: Style.mainWindow.rect.height
            Component.onCompleted: {
                var p = mapFromItem(null, 0, 0);
                x = p.x;
                y = p.y;

            }
        }
    }

    onPopupModeChanged: {
        if(popupMode == 0){
            itemContainer.anchors.bottom = undefined;
            itemContainer.anchors.top = currentText.bottom;
        }else{
            itemContainer.anchors.top = undefined;
            itemContainer.anchors.bottom = currentText.top;
        }
    }


    onItemsChanged: {
        itemModel.clear();
        for(var i = 0; i < items.length; ++i){
            itemModel.append({"index": i, "name":items[i]})
        }
    }
    MouseArea{
        anchors.fill: parent
        onClicked: {
            if(itemModel.count > 0){
                innerZ = container.z;
                container.z = 1000;
                var uS = rY;
                var dS = pHeight - uS - container.height;
                console.log("cBox", uS, dS);
                popupMode = (uS > dS ? 1 : 0);
                popupHeight = (popupMode == 1 ? uS : dS);
                view.currentIndex = currentIndex;
                itemContainer.visible = true;
            }
            parent.focus = true;
        }
    }
}

import QtQuick 1.1
import "../../styles/style.js" as Style
import "../../ICCustomElement"

Rectangle {
    property alias text: label.text
    property alias boxVisible: box.visible
    property alias isChecked: box.isChecked
    border.width: Style.itemStyles.ICIMMTableViewHeaderItem.border.width
    border.color: Style.itemStyles.ICIMMTableViewHeaderItem.border.color
    height: container.height + 4
    width: container.width + 4
    Row{
        id:container
        spacing: 2
        x:2
        anchors.verticalCenter: parent.verticalCenter
        Text {
            id:label
            font.pixelSize: Style.itemStyles.defaultFont.pixelSize
            text: " "
            height: Style.itemStyles.defaultSize.height
            verticalAlignment: Text.AlignVCenter
        }
        ICCheckBox{
            id:box
            text: qsTr("Vis")
            visible: false
        }
    }
}

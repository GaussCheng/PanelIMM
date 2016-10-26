import QtQuick 1.1
import "../../ICCustomElement"
import "../../styles/style.js" as Style
Row {
    spacing: 2
    property alias text: labelText.text
    property bool isOn: false
    Rectangle{
        id:led
        width: Style.itemStyles.defaultFont.pixelSize
        height: width
        color: isOn ? "red" : "white"
    }
    Text{
        id:labelText
        font.pixelSize: Style.itemStyles.defaultFont.pixelSize
        anchors.verticalCenter: parent.verticalCenter
    }
}

import QtQuick 1.1
import "../../ICCustomElement"
import "../../styles/style.js" as Style

Row {
    property alias configName: label.text
    property alias bindStatus: status.bindStatus
    property alias text: status.text
    property alias font: status.font
    property alias color: status.color
    property alias unit: unitLabel.text
    spacing: 2
    width: 100 * Style.wRatio
    Text {
        id: label
        text: "text"
        font.pixelSize: status.font.pixelSize
        color: status.color
        height: status.height
        verticalAlignment: Text.AlignVCenter

    }
    ICStatusWidget{
        id:status
        font.pixelSize: Style.itemStyles.defaultFont.pixelSize
        text: " "
        height: Style.itemStyles.defaultSize.height
//        width: 50 * Style.wRatio
        width: parent.width - label.width - unitLabel.width
    }
    Text{
        id:unitLabel
        font.pixelSize: status.font.pixelSize
        color: status.color
        height: status.height
        verticalAlignment: Text.AlignVCenter
    }
}

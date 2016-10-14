import QtQuick 1.1

Item {
    property string bindStatus: ""
    property alias text: status.text
    property alias font: status.font
    width: 50
    height: 24
    Text {
        id: status
        width: parent.width
        height: parent.height
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignRight
    }
}

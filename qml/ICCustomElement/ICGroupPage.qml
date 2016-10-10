import QtQuick 1.1

Rectangle {
    property alias title: titleLabel.text
    property alias titleBG: titleLabel.color
    border.width: 1
    border.color: "white"
    color: "transparent"
    ICLabel{
        id:titleLabel
        color: "green"
        anchors.left: parent.left
        anchors.bottom: parent.top
    }
    y:titleLabel.height
}

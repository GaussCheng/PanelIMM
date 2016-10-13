import QtQuick 1.1
import "../styles/style.js" as Style

Rectangle {
    property alias title: titleLabel.text
    property alias titleBG: titleLabel.color
    property alias titleHeight: titleLabel.height
    border.width: Style.itemStyles.ICGroupPage.border.width
    border.color: Style.itemStyles.ICGroupPage.border.color
    color: Style.itemStyles.ICGroupPage.color
    ICLabel{
        id:titleLabel
        color: Style.itemStyles.ICGroupPage.titleLabel.color
        anchors.left: parent.left
        anchors.bottom: parent.top
        height: 16
    }
    y:titleLabel.height
}

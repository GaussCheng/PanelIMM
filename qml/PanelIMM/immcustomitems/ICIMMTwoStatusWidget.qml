import QtQuick 1.1
import "../../styles/style.js" as Style
import "../../ICCustomElement"

Image {
    property bool isOn: false
    property string onImg: ""
    property string offImg: ""
    property string bindStatus: ""
    property alias text: status.text
    property alias font: status.font
    property alias color: status.color
    Text {
        id: status
        width: parent.width
        height: parent.height
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }
    source: isOn ? onImg : offImg
}

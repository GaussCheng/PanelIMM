import QtQuick 1.1

Item {
    id:instance
    property alias configName: configName.text
    property alias configAddr: edit.configAddr
    property alias unit: edit.unit
    property alias configValue: edit.text
    property alias alignMode: edit.horizontalAlignment
    property alias configNameWidth: configName.width
    property alias inputWidth: edit.width
    property alias isNumberOnly: edit.isNumberOnly
    property alias min: edit.min
    property alias max: edit.max
    property alias decimal: edit.decimal
    property alias font: edit.font

//    color: "transparent"

    signal editFinished();

    function getConfigValue(){
        return parseFloat(configValue);
    }

    height: 24
    width: container.width + container.spacing
    Row{
        id:container
        spacing: 2
        width: configName.width + edit.width
        height: parent.height
        Text {
            id: configName
//            anchors.verticalCenter: parent.verticalCenter
            verticalAlignment: Text.AlignVCenter
            height: parent.height
            font: edit.font
        }
        ICLineEdit{
            id: edit
            height: parent.height
            onEditFinished: instance.editFinished()
            focus: instance.focus
        }
    }

}

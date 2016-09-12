import QtQuick 1.1
import "../../ICCustomElement"
import "../style.js" as Style
ICButton {
    id:instance
    property bool isChecked: false
    radius: Style.detailMenuSection.menuItem.radius
    border.width: 0
    onButtonClicked: {
        isChecked = !isChecked;
    }
    bgColor: Style.detailMenuSection.menuItem.color

    function setChecked(checked){
        isChecked = checked;
    }

    states: [
        State {
            name: "pressed"; when: instance.pressed
            PropertyChanges {target: instance; border.width: 1; border.color: Style.detailMenuSection.menuItem.borderColor;bgColor: Style.detailMenuSection.menuItem.pressedColor;}
        },
        State {
            name: "checked"; when: instance.isChecked
            PropertyChanges {target: instance; border.width: 1; border.color: Style.detailMenuSection.menuItem.borderColor;bgColor: Style.detailMenuSection.menuItem.checkedColor;}
        }
    ]
}

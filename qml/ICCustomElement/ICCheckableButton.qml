import QtQuick 1.1

ICButton {
    id:instance
    property bool isChecked: false
    onButtonClicked: {
        isChecked = !isChecked;
    }

    function setChecked(checked){
        isChecked = checked;
    }
}

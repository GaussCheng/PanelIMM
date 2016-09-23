import QtQuick 1.1

Rectangle {
    id:instance
    property bool isEditable: true
    property variant navU: null
    property variant navD: null
    property variant navL: null
    property variant navR: null
    property string tip: ""
    function navHelper(which){
        if(which != null){
            which.focus = true;
            focused(instance);
        }
    }
    function screenPos(){
        return mapToItem(null, x, y);
    }

    signal focused(variant me)

    Keys.onUpPressed: navHelper(navU)
    Keys.onDownPressed: navHelper(navD)
    Keys.onLeftPressed: navHelper(navL)
    Keys.onRightPressed: navHelper(navR)

    //    KeyNavigation{
    //        id:kN
    //        priority: KeyNavigation.BeforeItem
    //    }
}

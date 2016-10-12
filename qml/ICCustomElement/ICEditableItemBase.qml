import QtQuick 1.1

Rectangle {
    id:instance
    property bool isEditable: true
    property variant navU: null
    property variant navD: null
    property variant navL: null
    property variant navR: null
    property string tip: ""
    function navHelper(which, next){
        if(which != null){
            if(!which.visible || !which.enabled){
                navHelper(which[next], next);
            }else{
                which.focus = true;
                focused(which);
            }
        }
    }
    function screenPos(){
        return mapToItem(null, 0, 0);
    }

    signal focused(variant me)

    onFocusChanged: {
        if(focus)
            focused(instance);
    }

    Keys.onUpPressed: navHelper(navU, "navU")
    Keys.onDownPressed: navHelper(navD, "navD")
    Keys.onLeftPressed: navHelper(navL, "navL")
    Keys.onRightPressed: navHelper(navR, "navR")

    //    KeyNavigation{
    //        id:kN
    //        priority: KeyNavigation.BeforeItem
    //    }
}

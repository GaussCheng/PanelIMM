import QtQuick 1.1
import "../../utils/utils.js" as Utils

Rectangle {
    id:instance
    property bool keyNavInited: false
    onVisibleChanged: {
        if(visible && ! keyNavInited){
            Utils.generatePageKeyNav(instance);
            keyNavInited = true;
        }

    }
}

import QtQuick 1.1
import "../../utils/utils.js" as Utils

Rectangle {
    id:instance
    property bool keyNavInited: false

    signal editorFocusChanged(variant now)
    onVisibleChanged: {
        if(visible && ! keyNavInited){
            var ret = Utils.generatePageKeyNav(instance);
            for(var i = 0, rlen = ret.length; i < rlen; ++i){
                for(var j = 0, cLen = ret[i].length; j < cLen; ++j){
                    ret.focused.connect(editorFocusChanged);
                }
            }

            keyNavInited = true;
        }

    }
}

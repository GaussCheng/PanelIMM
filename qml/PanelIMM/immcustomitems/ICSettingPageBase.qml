import QtQuick 1.1
import "../../utils/utils.js" as Utils

Rectangle {
    id:instance
    property bool keyNavInited: false

    signal editorFocusChanged(variant now)
//    function editorFocusChanged(now){
//        console.log("focus changed");
//    }

    onVisibleChanged: {
        if(visible && ! keyNavInited){
            var ret = Utils.generatePageKeyNav(instance);
            for(var i = 0, rlen = ret.length; i < rlen; ++i){
                for(var j = 0, cLen = ret[i].length; j < cLen; ++j){
                    ret[i][j].focused.connect(editorFocusChanged);
                }
            }

            keyNavInited = true;
        }
    }
}

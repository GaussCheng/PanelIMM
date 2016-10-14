import QtQuick 1.1
import "../../ICCustomElement"
import "../immcustomitems"
ICIMMFunctionPageBase {
    id:instance
    property variant detailsMenuItems: {
        "f6":qsTr("Aid Settings"),
    }
    function onF6Triggered(){
        return "";
    }
    ICSettingPageBase{
        id:moldPage1
        width: parent.width
        height: parent.height
        onEditorFocusChanged: {
            instance.editorFocusChanged(now);
        }
        ICSettingConfigsScope{

        }
    }
}

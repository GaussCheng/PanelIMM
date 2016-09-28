import QtQuick 1.1
import "../../ICCustomElement"
import "../immcustomitems"
ICIMMFunctionPageBase {
    id:instance
    property variant detailsMenuItems: {
        "f6":qsTr("Temp"),
                "f7":qsTr("Tune Mold"),
    }
    function onF6Triggered(){
        console.log("open Temp")
    }

    function onF7Triggered(){
        console.log("Open Tune MOld");
    }

    ICSettingPageBase{
        id:workReadyPage1
        onEditorFocusChanged: {
            instance.editorFocusChanged(now);
        }

        Row{
            ICLineEdit{
                min: 10
                max: 100
                decimal: 0

            }
            ICLineEdit{
                min: 10
                max: 1000
                decimal: 1
            }
            ICLineEdit{
                min: 10
                max: 10000000
                decimal: 2
            }
        }
    }
    Component.onCompleted: {
        addPage(workReadyPage1)
        setCurrentIndex(0)
    }
}

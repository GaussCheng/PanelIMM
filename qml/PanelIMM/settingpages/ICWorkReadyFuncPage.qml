import QtQuick 1.1
import "../../ICCustomElement"
import "../immcustomitems"
ICStackContainer {

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
        onEditorFocusChanged: {
            console.log("focus Changed")
        }

        Row{
            ICLineEdit{

            }
            ICLineEdit{

            }
            ICLineEdit{

            }
        }
    }
}

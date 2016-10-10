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
        width: parent.width
        height: parent.height
        onEditorFocusChanged: {
            instance.editorFocusChanged(now);
        }
        ICSettingConfigsScope{
            ICGroupPage{
                title: qsTr("Clear Materia")
                width: workReadyPage1.width
                height: workReadyPage1.height - y
                Grid{
                    columns: 5
                    spacing: 6
                    x:4
                    y:4
                    Text {
                        text: qsTr("CEAR")
                    }
                    Text {
                        text: qsTr("PRES")
                    }
                    Text {
                        text: qsTr("SPE")
                    }
                    Text {
                        text: qsTr("POSN")
                    }
                    Text {
                        text: qsTr("TIME")
                    }

                    Text {
                        text: " "
                    }
                    Text {
                        text: qsTr("(bar)")
                    }
                    Text {
                        text: qsTr("(%)")
                    }
                    Text {
                        text: qsTr("(mm)")
                    }
                    Text {
                        text: qsTr("(s)")
                    }

                    Text {
                        text: qsTr("Inj.Seg1")
                    }
                    ICLineEdit{
                        id:m_rw_17_15_0_407
                        bindConfig: "m_rw_17_15_0_407"
                    }
                    ICLineEdit{
                        id:m_rw_0_16_0_408
                        bindConfig: "m_rw_0_16_0_408"
                    }
                    ICLineEdit{
                        id:m_rw_0_17_1_407
                        bindConfig: "m_rw_0_17_1_407"
                    }
                    Text {
                        text: " "
                    }

                    Text {
                        text: qsTr("Inj.Seg2")
                    }
                    ICLineEdit{
                        id:m_rw_17_15_0_409
                        bindConfig: "m_rw_17_15_0_409"
                    }
                    ICLineEdit{
                        id:m_rw_0_16_0_410
                        bindConfig: "m_rw_0_16_0_410"
                    }
                    ICLineEdit{
                        id:m_rw_0_17_1_409
                        bindConfig: "m_rw_0_17_1_409"
                    }
                    Text {
                        text: " "
                    }

                }
            }
        }

    }
    Component.onCompleted: {
        addPage(workReadyPage1);
        setCurrentIndex(0);
    }
}

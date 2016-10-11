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
                width: workReadyPage1.width - 1
                height: workReadyPage1.height * 0.55 - y
                Grid{
                    columns: 5
                    x:4
                    y:2
                    ICIMMText {
                        text: qsTr("CEAR")
                    }
                    ICIMMText {
                        text: qsTr("PRES")
                    }
                    ICIMMText {
                        text: qsTr("SPE")
                    }
                    ICIMMText {
                        text: qsTr("POSN")
                    }
                    ICIMMText {
                        text: qsTr("TIME")
                    }

                    ICIMMText {
                    }
                    ICIMMText {
                        text: qsTr("(bar)")
                    }
                    ICIMMText {
                        text: qsTr("(%)")
                    }
                    ICIMMText {
                        text: qsTr("(mm)")
                    }
                    ICIMMText {
                        text: qsTr("(s)")
                    }

                    ICIMMText {
                        text: qsTr("Inj.Seg1")
                    }
                    ICIMMLineEdit{
                        id:m_rw_17_15_0_407
                        configAddr: "m_rw_17_15_0_407"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_16_0_408
                        configAddr: "m_rw_0_16_0_408"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_17_1_407
                        configAddr: "m_rw_0_17_1_407"
                    }
                    ICIMMText {
                    }

                    ICIMMText {
                        text: qsTr("Inj.Seg2")
                    }
                    ICIMMLineEdit{
                        id:m_rw_17_15_0_409
                        configAddr: "m_rw_17_15_0_409"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_16_0_410
                        configAddr: "m_rw_0_16_0_410"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_17_1_409
                        configAddr: "m_rw_0_17_1_409"
                    }
                    ICIMMText {
                    }

                    ICIMMText {
                        text: qsTr("S.B")
                    }
                    ICIMMLineEdit{
                        id:m_rw_17_15_0_411
                        configAddr: "m_rw_17_15_0_411"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_16_0_412
                        configAddr: "m_rw_0_16_0_412"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_17_1_411
                        configAddr: "m_rw_0_17_1_411"
                    }
                    ICIMMText {
                    }

                    ICIMMText {
                        text: qsTr("Feed")
                    }
                    ICIMMLineEdit{
                        id:m_rw_17_15_0_413
                        configAddr: "m_rw_17_15_0_413"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_16_0_414
                        configAddr: "m_rw_0_16_0_414"
                    }
                    ICIMMText {
                    }
                    ICIMMLineEdit{
                        id:m_rw_16_16_2_414
                        configAddr: "m_rw_16_16_2_414"
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

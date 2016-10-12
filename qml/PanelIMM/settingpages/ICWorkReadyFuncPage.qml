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
            ICIMMFrame{
//                title: qsTr("Clear Materia")
                width: workReadyPage1.width - 1
                height: workReadyPage1.height * 0.55 - y
                Grid{
                    id:chargeContainer
                    x:4
                    y:2
                    columns: 5
                    ICIMMText{text: qsTr("CHARGE")}
                    ICIMMText{text: qsTr("PRES")}
                    ICIMMText{text: qsTr("SPE")}
                    ICIMMText{text: qsTr("B-P")}
                    ICIMMText{text: qsTr("POSN")}

                    ICIMMText{}
                    ICIMMText{text: qsTr("(bar)")}
                    ICIMMText{text: qsTr("(%)")}
                    ICIMMText{text: qsTr("(bar)")}
                    ICIMMText{text: qsTr("(mm)")}

                    ICIMMText{text: qsTr("B.S.B")}
                    ICIMMLineEdit{
                        id:m_rw_17_15_1_285
                        configAddr: "m_rw_17_15_1_285"
                        objectName: "0"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_10_1_286
                        configAddr: "m_rw_0_10_1_286"
                        objectName: "1"
                    }
                    ICIMMText{}
                    ICIMMLineEdit{
                        id:m_rw_0_17_2_285
                        configAddr: "m_rw_0_17_2_285"
                        objectName: "2"
                    }

                    ICIMMText{text:qsTr("SEC1")}
                    ICIMMLineEdit{
                        id:m_rw_17_15_1_261
                        configAddr: "m_rw_17_15_1_261"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_10_1_262
                        configAddr: "m_rw_0_10_1_262"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_16_0_279
                        configAddr: "m_rw_0_16_0_279"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_17_2_261
                        configAddr: "m_rw_0_17_2_261"
                    }

                    ICIMMText{text:qsTr("SEC2")}
                    ICIMMLineEdit{
                        id:m_rw_17_15_1_265
                        configAddr: "m_rw_17_15_1_265"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_10_1_266
                        configAddr: "m_rw_0_10_1_266"
                    }
                    ICIMMLineEdit{
                        id:m_rw_16_16_0_279
                        configAddr: "m_rw_16_16_0_279"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_17_2_265
                        configAddr: "m_rw_0_17_2_265"
                    }

                    ICIMMText{text:qsTr("A.S.B")}
                    ICIMMLineEdit{
                        id:m_rw_17_15_1_292
                        configAddr: "m_rw_17_15_1_292"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_10_1_293
                        configAddr: "m_rw_0_10_1_293"
                    }
                    ICIMMText{}
                    ICIMMLineEdit{
                        id:m_rw_0_17_2_292
                        configAddr: "m_rw_0_17_2_292"
                    }
                }

                ICVerSplitLine{
                    id:verSplitLine1
                    height: parent.height
                    anchors.left: chargeContainer.right
                    anchors.leftMargin: 4
                }

                Grid{
                    id:clearMateriaContainer
                    columns: 5
                    anchors.left: verSplitLine1.right
                    anchors.leftMargin: 4
                    y: chargeContainer.y
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
                        id:injSeg1Label
                        text: qsTr("Inj.Seg1")
                    }
                    ICIMMLineEdit{
                        id:m_rw_17_15_0_407
                        configAddr: "m_rw_17_15_0_407"
                        objectName: "3"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_16_0_408
                        configAddr: "m_rw_0_16_0_408"
                        objectName: "4"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_17_1_407
                        configAddr: "m_rw_0_17_1_407"
                        objectName: "5"
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
                    ICIMMText {}
                    ICIMMLineEdit{
                        id:m_rw_16_16_2_414
                        configAddr: "m_rw_16_16_2_414"
                    }
                }
                ICIMMLabelLineEdit{
                    id:m_rw_0_8_0_415
                    configAddr: "m_rw_0_8_0_415"
                    configName: qsTr("Clr.T")
                    unit: qsTr("times")
                    anchors.top: clearMateriaContainer.bottom
                    x: clearMateriaContainer.x
                    configNameWidth: injSeg1Label.width - 1
                    inputWidth: m_rw_0_10_1_262.width << 1
                }

                ICVerSplitLine{
                    id:verSplitLine2
                    height: parent.height
                    anchors.left: clearMateriaContainer.right
                    anchors.leftMargin: 4
                }
                Grid{
                    id:otherChargeContainer
                    columns: 2
                    anchors.left: verSplitLine2.right
                    anchors.leftMargin: 4
//                    ICCheckBoxEdit{
//                        id:m_rw_0_1_0_253
//                        text: qsTr("F.B.INJ")
//                    }
                    ICIMMText{}

                }
            }
        }

    }
    Component.onCompleted: {
        addPage(workReadyPage1);
        setCurrentIndex(0);
    }
}

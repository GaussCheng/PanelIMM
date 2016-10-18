import QtQuick 1.1
import "../../ICCustomElement"
import "../immcustomitems"
import "../../styles/style.js" as Style
ICIMMFunctionPageBase {
    id:instance
    property variant detailsMenuItems: {
        "f6":qsTr("Aid Settings"),
    }
    function onF6Triggered(){
        return "ICCoreAidCVMonitorPage.qml";
    }
//    function onF7Triggered(){
//        return "ICTemperaturePIDCVMonitorPage.qml";
//    }
//    function onF8Triggered(){
//        return "ICTemperatureBlowCVMonitorPage.qml";
//    }
    ICSettingPageBase{
        id:page1
        width: parent.width
        height: parent.height
        onEditorFocusChanged: {
            instance.editorFocusChanged(now);
        }
        ICSettingConfigsScope{
            ICIMMFrame{
                id:topRow
                width: page1.width
                height: page1.height * 0.8
                Grid{
                    id:coreContainer
                    columns: 8
                    x:4
                    y:2
                    ICIMMText{}
                    ICIMMText{text: qsTr("MODE")}
                    ICIMMText{text: qsTr("PRES")}
                    ICIMMText{text: qsTr("SPE")}
                    ICIMMText{text: qsTr("TIME")}
                    ICIMMText{text: qsTr("oth Cou")}
                    ICIMMText{text: qsTr("A.P")}
                    ICIMMText{text: qsTr("A.T")}
                    ICIMMText{}
                    ICIMMText{}
                    ICIMMText{text: qsTr("(bar)")}
                    ICIMMText{text: qsTr("(%)")}
                    ICIMMText{text: qsTr("(s)")}
                    ICIMMText{text: qsTr("(pc)")}
                    ICIMMText{text: qsTr("(mm)")}
                    ICIMMText{}

                    ICIMMText{text: qsTr("Core-A IN")}
                    ICIMMLabelComboBoxEdit{
                        id:m_rw_0_4_0_335
                        configAddr: "m_rw_0_4_0_335"
                        items: [qsTr("UNUSE"), qsTr("LIMIT"), qsTr("TIME")]
                        popupMode: 1
                        inputWidth: m_rw_4_4_0_335.inputWidth

                    }
                    ICIMMLineEdit{
                        id:m_rw_0_16_1_336
                        configAddr: "m_rw_0_16_1_336"
                    }
                    ICIMMLineEdit{
                        id:m_rw_20_12_1_335
                        configAddr: "m_rw_20_12_1_335"
                    }
                    ICIMMLineEdit{
                        id:m_rw_16_16_2_336
                        configAddr: "m_rw_16_16_2_336"
                    }
                    ICIMMLineEdit{
                        id:m_rw_8_12_0_335
                        configAddr: "m_rw_8_12_0_335"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_17_2_337
                        configAddr: "m_rw_0_17_2_337"
                    }
                    ICIMMLabelComboBoxEdit{
                        id:m_rw_4_4_0_335
                        configAddr: "m_rw_4_4_0_335"
                        items:[qsTr("BF-M"), qsTr("AF-M"), qsTr("DURI")]
                        inputWidth: 70 * Style.wRatio
                        popupMode: 1
                    }


                    ICIMMText{text: qsTr("Core-A OUT")}
                    ICIMMLabelComboBoxEdit{
                        id:m_rw_0_4_0_338
                        configAddr: "m_rw_0_4_0_338"
                        items: m_rw_0_4_0_335.items
                        popupMode: 1
                        inputWidth: m_rw_4_4_0_335.inputWidth
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_16_1_339
                        configAddr: "m_rw_0_16_1_339"
                    }
                    ICIMMLineEdit{
                        id:m_rw_20_12_1_338
                        configAddr: "m_rw_20_12_1_338"
                    }
                    ICIMMLineEdit{
                        id:m_rw_16_16_2_339
                        configAddr: "m_rw_16_16_2_339"
                    }
                    ICIMMLineEdit{
                        id:m_rw_8_12_0_338
                        configAddr: "m_rw_8_12_0_338"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_17_2_340
                        configAddr: "m_rw_0_17_2_340"
                    }
                    ICIMMLabelComboBoxEdit{
                        id:m_rw_4_4_0_338
                        configAddr: "m_rw_4_4_0_338"
                        items:m_rw_4_4_0_335.items
                        popupMode: 1
                        inputWidth: m_rw_4_4_0_335.inputWidth

                    }

                    ICIMMText{text: qsTr("Core-B IN")}
                    ICIMMLabelComboBoxEdit{
                        id:m_rw_0_4_0_341
                        configAddr: "m_rw_0_4_0_341"
                        items: m_rw_0_4_0_335.items
                        popupMode: 1
                        inputWidth: m_rw_4_4_0_335.inputWidth

                    }
                    ICIMMLineEdit{
                        id:m_rw_0_16_1_342
                        configAddr: "m_rw_0_16_1_342"
                    }
                    ICIMMLineEdit{
                        id:m_rw_20_12_1_341
                        configAddr: "m_rw_20_12_1_341"
                    }
                    ICIMMLineEdit{
                        id:m_rw_16_16_2_342
                        configAddr: "m_rw_16_16_2_342"
                    }
                    ICIMMLineEdit{
                        id:m_rw_8_12_0_341
                        configAddr: "m_rw_8_12_0_341"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_17_2_343
                        configAddr: "m_rw_0_17_2_343"
                    }
                    ICIMMLabelComboBoxEdit{
                        id:m_rw_4_4_0_341
                        configAddr: "m_rw_4_4_0_341"
                        items:m_rw_4_4_0_335.items
                        popupMode: 1
                        inputWidth: m_rw_4_4_0_335.inputWidth

                    }

                    ICIMMText{text: qsTr("Core-B OUT")}
                    ICIMMLabelComboBoxEdit{
                        id:m_rw_0_4_0_344
                        configAddr: "m_rw_0_4_0_344"
                        items: m_rw_0_4_0_335.items
                        popupMode: 1
                        inputWidth: m_rw_4_4_0_335.inputWidth

                    }
                    ICIMMLineEdit{
                        id:m_rw_0_16_1_345
                        configAddr: "m_rw_0_16_1_345"
                    }
                    ICIMMLineEdit{
                        id:m_rw_20_12_1_344
                        configAddr: "m_rw_20_12_1_344"
                    }
                    ICIMMLineEdit{
                        id:m_rw_16_16_2_345
                        configAddr: "m_rw_16_16_2_345"
                    }
                    ICIMMLineEdit{
                        id:m_rw_8_12_0_344
                        configAddr: "m_rw_8_12_0_344"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_17_2_346
                        configAddr: "m_rw_0_17_2_346"
                    }
                    ICIMMLabelComboBoxEdit{
                        id:m_rw_4_4_0_344
                        configAddr: "m_rw_4_4_0_344"
                        items:m_rw_4_4_0_335.items
                        popupMode: 1
                        inputWidth: m_rw_4_4_0_335.inputWidth

                    }

                    ICIMMText{text: qsTr("Core-C IN")}
                    ICIMMLabelComboBoxEdit{
                        id:m_rw_0_4_0_347
                        configAddr: "m_rw_0_4_0_347"
                        items: m_rw_0_4_0_335.items
                        popupMode: 1
                        inputWidth: m_rw_4_4_0_335.inputWidth

                    }
                    ICIMMLineEdit{
                        id:m_rw_0_16_1_348
                        configAddr: "m_rw_0_16_1_348"
                    }
                    ICIMMLineEdit{
                        id:m_rw_20_12_1_347
                        configAddr: "m_rw_20_12_1_347"
                    }
                    ICIMMLineEdit{
                        id:m_rw_16_16_2_348
                        configAddr: "m_rw_16_16_2_348"
                    }
                    ICIMMLineEdit{
                        id:m_rw_8_12_0_347
                        configAddr: "m_rw_8_12_0_347"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_17_2_349
                        configAddr: "m_rw_0_17_2_349"
                    }
                    ICIMMLabelComboBoxEdit{
                        id:m_rw_4_4_0_347
                        configAddr: "m_rw_4_4_0_347"
                        items:m_rw_4_4_0_335.items
                        popupMode: 1
                        inputWidth: m_rw_4_4_0_335.inputWidth

                    }

                    ICIMMText{text: qsTr("Core-C OUT")}
                    ICIMMLabelComboBoxEdit{
                        id:m_rw_0_4_0_350
                        configAddr: "m_rw_0_4_0_350"
                        items: m_rw_0_4_0_335.items
                        popupMode: 1
                        inputWidth: m_rw_4_4_0_335.inputWidth

                    }
                    ICIMMLineEdit{
                        id:m_rw_0_16_1_351
                        configAddr: "m_rw_0_16_1_351"
                    }
                    ICIMMLineEdit{
                        id:m_rw_20_12_1_350
                        configAddr: "m_rw_20_12_1_350"
                    }
                    ICIMMLineEdit{
                        id:m_rw_16_16_2_351
                        configAddr: "m_rw_16_16_2_351"
                    }
                    ICIMMLineEdit{
                        id:m_rw_8_12_0_350
                        configAddr: "m_rw_8_12_0_350"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_17_2_352
                        configAddr: "m_rw_0_17_2_352"
                    }
                    ICIMMLabelComboBoxEdit{
                        id:m_rw_4_4_0_350
                        configAddr: "m_rw_4_4_0_350"
                        items:m_rw_4_4_0_335.items
                        popupMode: 1
                        inputWidth: m_rw_4_4_0_335.inputWidth

                    }

                    ICIMMText{text: qsTr("Core-D IN")}
                    ICIMMLabelComboBoxEdit{
                        id:m_rw_0_4_0_353
                        configAddr: "m_rw_0_4_0_353"
                        items: m_rw_0_4_0_335.items
                        popupMode: 1
                        inputWidth: m_rw_4_4_0_335.inputWidth

                    }
                    ICIMMLineEdit{
                        id:m_rw_0_16_1_354
                        configAddr: "m_rw_0_16_1_354"
                    }
                    ICIMMLineEdit{
                        id:m_rw_20_12_1_353
                        configAddr: "m_rw_20_12_1_353"
                    }
                    ICIMMLineEdit{
                        id:m_rw_16_16_2_354
                        configAddr: "m_rw_16_16_2_354"
                    }
                    ICIMMLineEdit{
                        id:m_rw_8_12_0_353
                        configAddr: "m_rw_8_12_0_353"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_17_2_355
                        configAddr: "m_rw_0_17_2_355"
                    }
                    ICIMMLabelComboBoxEdit{
                        id:m_rw_4_4_0_353
                        configAddr: "m_rw_4_4_0_353"
                        items:m_rw_4_4_0_335.items
                        popupMode: 1
                        inputWidth: m_rw_4_4_0_335.inputWidth

                    }

                    ICIMMText{text: qsTr("Core-D OUT")}
                    ICIMMLabelComboBoxEdit{
                        id:m_rw_0_4_0_356
                        configAddr: "m_rw_0_4_0_356"
                        items: m_rw_0_4_0_335.items
                        popupMode: 1
                        inputWidth: m_rw_4_4_0_335.inputWidth

                    }
                    ICIMMLineEdit{
                        id:m_rw_0_16_1_357
                        configAddr: "m_rw_0_16_1_357"
                    }
                    ICIMMLineEdit{
                        id:m_rw_20_12_1_356
                        configAddr: "m_rw_20_12_1_356"
                    }
                    ICIMMLineEdit{
                        id:m_rw_16_16_2_357
                        configAddr: "m_rw_16_16_2_357"
                    }
                    ICIMMLineEdit{
                        id:m_rw_8_12_0_356
                        configAddr: "m_rw_8_12_0_356"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_17_2_358
                        configAddr: "m_rw_0_17_2_358"
                    }
                    ICIMMLabelComboBoxEdit{
                        id:m_rw_4_4_0_356
                        configAddr: "m_rw_4_4_0_356"
                        items:m_rw_4_4_0_335.items
                        popupMode: 1
                        inputWidth: m_rw_4_4_0_335.inputWidth

                    }
                }
                ICVerSplitLine{
                    id:verSplitLine1
                    height: parent.height
                    anchors.left: coreContainer.right
                    anchors.leftMargin: 4
                }
                Column{
                    id:topTopContainer
                    anchors.left: verSplitLine1.right
                    anchors.leftMargin: verSplitLine1.anchors.leftMargin
                    y:coreContainer.y
                    ICIMMText{text: qsTr("Pis.Core")}
                    ICIMMLabelLineEdit{
                        id:m_rw_16_8_0_366
                        configAddr: "m_rw_16_8_0_366"
                        configName: qsTr("S.1.Vec")
                        unit: qsTr("%")
                    }
                    ICIMMLabelLineEdit{
                        id:m_rw_0_16_1_367
                        configAddr: "m_rw_0_16_1_367"
                        configName: qsTr("S.1.Dis")
                        unit: qsTr("mm")
                        configNameWidth: m_rw_16_8_0_366.configNameWidth
                    }
                    ICIMMLabelLineEdit{
                        id:m_rw_24_8_0_366
                        configAddr: "m_rw_24_8_0_366"
                        configName: qsTr("S.2.Vec")
                        unit: qsTr("%")
                        configNameWidth: m_rw_16_8_0_366.configNameWidth

                    }
                    ICIMMLabelLineEdit{
                        id:m_rw_16_16_1_367
                        configAddr: "m_rw_16_16_1_367"
                        configName: qsTr("S.2.Dis")
                        unit: qsTr("mm")
                        configNameWidth: m_rw_16_8_0_366.configNameWidth
                    }
                }
                ICHorSplitLine{
                    id:horSplitLine
                    width: parent.width - verSplitLine1.x
                    anchors.top: topTopContainer.bottom
                    anchors.topMargin: 4
                    x: verSplitLine1.x
                }
                Column{
                    id:topBottomContainer
                    anchors.top: horSplitLine.bottom
                    anchors.topMargin: horSplitLine.anchors.topMargin
                    x: topTopContainer.x
                    ICIMMText{text: qsTr("SCRW")}
                    ICIMMLabelLineEdit{
                        id:m_rw_0_16_0_366
                        configAddr: "m_rw_0_16_0_366"
                        configName: qsTr("S.PRES")
                        unit: qsTr("bar")
                        configNameWidth: m_rw_16_8_0_366.configNameWidth
                    }
                    ICIMMLabelLineEdit{
                        id:m_rw_10_11_0_365
                        configAddr: "m_rw_10_11_0_365"
                        configName: qsTr("S.Vec")
                        unit: qsTr("%")
                        configNameWidth: m_rw_16_8_0_366.configNameWidth
                    }
                    ICIMMLabelLineEdit{
                        id:m_rw_21_11_0_365
                        configAddr: "m_rw_21_11_0_365"
                        configName: qsTr("S.TooTh")
                        unit: qsTr("pc")
                        configNameWidth: m_rw_16_8_0_366.configNameWidth
                    }
                }
            }
            ICIMMFrame{
                width: page1.width
                height: page1.height - topRow.height
                anchors.top: topRow.bottom
                ICIMMLabelLineEdit{
                    id:m_rw_0_16_2_359
                    configAddr: "m_rw_0_16_2_359"
                    x:4
                    y:2
                    configName: qsTr("B.C.Delay")
                    unit: qsTr("s")
                }
            }
        }
    }
}

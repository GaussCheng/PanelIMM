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
        return "ICProductControlCVMonitorPage.qml";
    }
    ICSettingPageBase{
        id:page1
        width: parent.width
        height: parent.height
        onEditorFocusChanged: {
            instance.editorFocusChanged(now);
        }
        ICIMMSettingConfigsScope{
            id:topRow
            width: page1.width * 0.54
            height: page1.height * 0.5
            Grid{
                x:4
                y:2
                columns: 5
                ICIMMText{}
                ICIMMText{text:qsTr("TOTAL")}
                ICIMMText{text:qsTr("GOOD")}
                ICIMMText{text:qsTr("BAD")}
                ICIMMText{text:qsTr("BOX NO.")}

                ICIMMText{text: qsTr("FUNC")}
                ICIMMCheckBoxEdit{
                    id:m_rw_12_1_0_444
                    configAddr: "m_rw_12_1_0_444"
                }
                ICIMMCheckBoxEdit{
                    id:m_rw_13_1_0_444
                    configAddr: "m_rw_13_1_0_444"
                }
                ICIMMCheckBoxEdit{
                    id:m_rw_14_1_0_444
                    configAddr: "m_rw_14_1_0_444"
                }
                ICIMMCheckBoxEdit{
                    id:m_rw_15_1_0_444
                    configAddr: "m_rw_15_1_0_444"
                }

                ICIMMText{text: qsTr("Tips Select")}
                ICIMMCheckBoxEdit{
                    id:m_rw_18_1_0_444
                    configAddr: "m_rw_18_1_0_444"
                }
                ICIMMCheckBoxEdit{
                    id:m_rw_19_1_0_444
                    configAddr: "m_rw_19_1_0_444"
                }
                ICIMMCheckBoxEdit{
                    id:m_rw_20_1_0_444
                    configAddr: "m_rw_20_1_0_444"
                }
                ICIMMCheckBoxEdit{
                    id:m_rw_21_1_0_444
                    configAddr: "m_rw_21_1_0_444"
                }

                ICIMMText{text: qsTr("TARGET")}
                ICIMMLineEdit{
                    id:m_rw_0_32_0_432
                    configAddr: "m_rw_0_32_0_432"
                }
                ICIMMLineEdit{
                    id:m_rw_0_32_0_433
                    configAddr: "m_rw_0_32_0_433"
                }
                ICIMMLineEdit{
                    id:m_rw_0_32_0_434
                    configAddr: "m_rw_0_32_0_434"
                }
                ICIMMLineEdit{
                    id:m_rw_0_32_0_435
                    configAddr: "m_rw_0_32_0_435"
                }

                ICIMMText{text: qsTr("CURRENT")}
                ICIMMStatusWidget{
                    id:c_ro_0_32_0_1564
                    bindStatus: "c_ro_0_32_0_1564"
                }
                ICIMMStatusWidget{
                    id:c_ro_0_32_0_1565
                    bindStatus: "c_ro_0_32_0_1565"
                }
                ICIMMStatusWidget{
                    id:c_ro_0_32_0_1566
                    bindStatus: "c_ro_0_32_0_1566"
                }
                ICIMMStatusWidget{
                    id:c_ro_0_32_0_1567
                    bindStatus: "c_ro_0_32_0_1567"
                }

                ICIMMText{}
                ICIMMButton{
                    id:resetTotal
                    text: qsTr("Reset")
                }
                ICIMMButton{
                    id:resetGood
                    text: qsTr("Reset")
                }
                ICIMMButton{
                    id:resetBad
                    text: qsTr("Reset")
                }
                ICIMMButton{
                    id:resetBoxNo
                    text: qsTr("Reset")
                }
            }
        }
        ICHorSplitLine{
            id:horSplitLine1
            anchors.top: topRow.bottom
            anchors.topMargin: 4
            width: bottomRow.width
        }

        ICIMMSettingConfigsScope{
            id:bottomRow
            width: topRow.width
            height: page1.height * 0.5
            anchors.top: horSplitLine1.bottom
            anchors.topMargin: 4
            Grid{
                x:4
                y:2
                columns: 6

                ICIMMText{}
                ICIMMText{text: qsTr("CUSHION")}
                ICIMMText{text: qsTr("CHRG_END")}
                ICIMMText{text: qsTr("MD O END")}
                ICIMMText{text: qsTr("CYCLE TM")}
                ICIMMText{text: qsTr("CAVITY NO")}

                ICIMMText{}
                ICIMMText{text: qsTr("(mm)")}
                ICIMMText{text: qsTr("(mm)")}
                ICIMMText{text: qsTr("(mm)")}
                ICIMMText{text: qsTr("(s)")}
                ICIMMText{}

                ICIMMText{text: qsTr("FUNC")}
                ICIMMCheckBoxEdit{
                    id:m_rw_8_1_0_444
                    configAddr: "m_rw_8_1_0_444"
                }
                ICIMMCheckBoxEdit{
                    id:m_rw_9_1_0_444
                    configAddr: "m_rw_9_1_0_444"
                }
                ICIMMCheckBoxEdit{
                    id:m_rw_10_1_0_444
                    configAddr: "m_rw_10_1_0_444"
                }
                ICIMMCheckBoxEdit{
                    id:m_rw_11_1_0_444
                    configAddr: "m_rw_11_1_0_444"
                }
                ICIMMLineEdit{
                    id:m_rw_0_8_0_444
                    configAddr: "m_rw_0_8_0_444"
                }

                ICIMMText{text: qsTr("QC_VALUE")}
                ICIMMLineEdit{
                    id:m_rw_0_16_1_440
                    configAddr: "m_rw_0_16_1_440"
                }
                ICIMMLineEdit{
                    id:m_rw_16_16_1_440
                    configAddr: "m_rw_16_16_1_440"
                }
                ICIMMLineEdit{
                    id:m_rw_0_16_1_441
                    configAddr: "m_rw_0_16_1_441"
                }
                ICIMMLineEdit{
                    id:m_rw_16_16_1_441
                    configAddr: "m_rw_16_16_1_441"
                }
                ICIMMText{}

                ICIMMText{text: qsTr("TOLERANCE")}
                ICIMMLineEdit{
                    id:m_rw_0_16_1_442
                    configAddr: "m_rw_0_16_1_442"
                }
                ICIMMLineEdit{
                    id:m_rw_16_16_1_442
                    configAddr: "m_rw_16_16_1_442"
                }
                ICIMMLineEdit{
                    id:m_rw_0_16_1_443
                    configAddr: "m_rw_0_16_1_443"
                }
                ICIMMLineEdit{
                    id:m_rw_16_16_1_443
                    configAddr: "m_rw_16_16_1_443"
                }
                ICIMMText{}

                ICIMMText{text: qsTr("AVERAGE")}
                ICIMMStatusWidget{
                }
                ICIMMStatusWidget{
                }
                ICIMMStatusWidget{
                }
                ICIMMStatusWidget{
                }
                ICIMMText{}

            }
        }

        ICVerSplitLine{
            id:verSplitLine1
            anchors.left: horSplitLine1.right
            height: page1.height
        }
        ICIMMSettingConfigsScope{
            width: page1.width - topRow.width
            height: page1.height
            anchors.left: verSplitLine1.right
            anchors.rightMargin: 4
            Column{
                x:4
                y:2
                spacing: 6
                ICIMMCheckBoxEdit{
                    id:m_rw_16_1_0_421
                    configAddr: "m_rw_16_1_0_421"
                    configName: qsTr("Robot En")
                }
                ICIMMCheckBoxEdit{
                    id:m_rw_26_1_0_444
                    configAddr: "m_rw_26_1_0_444"
                    configName: qsTr("Alarm Out Time En")
                }
                ICIMMLabelComboBoxEdit{
                    id:m_rw_27_5_0_444
                    configAddr: "m_rw_27_5_0_444"
                    configName: qsTr("Alarm Out Time")
                    items: [qsTr("SEG5s"), qsTr("SEG10s"), qsTr("SEG20s"), qsTr("SEG30s"), qsTr("1min"), qsTr("5min"), qsTr("10min"), qsTr("30min")]
                }

                Row{
                    spacing: 4
                    ICIMMLabelLineEdit{
                        id:m_rw_0_16_0_420
                        configAddr: "m_rw_0_16_0_420"
                        configName: qsTr("Cycle Pro.")
                        inputWidth: 60 * Style.wRatio
                        unit: qsTr("s")
                    }
                    ICIMMLabelLineEdit{
                        id:m_rw_0_16_2_452
                        configAddr: "m_rw_0_16_2_452"
                        inputWidth: m_rw_0_16_0_420.inputWidth
                        configName: qsTr("E Eye Pro.")
                        configNameWidth: m_rw_16_16_2_452.configNameWidth
                        unit: qsTr("s")
                    }

                }
                Row{
                    spacing: 4
                    ICIMMLabelLineEdit{
                        id:m_rw_16_16_0_420
                        configAddr: "m_rw_16_16_0_420"
                        configName: qsTr("Abn.Time")
                        configNameWidth: m_rw_0_16_0_420.configNameWidth
                        inputWidth: m_rw_0_16_0_420.inputWidth

                        unit: qsTr("s")
                    }
                    ICIMMLabelLineEdit{
                        id:m_rw_16_16_2_452
                        configAddr: "m_rw_16_16_2_452"
                        configName: qsTr("E.Eye.Cover")
                        inputWidth: m_rw_0_16_0_420.inputWidth

                        unit: qsTr("s")
                    }
                }
                ICIMMCheckBoxEdit{
                    id:m_rw_24_1_0_429
                    configAddr: "m_rw_24_1_0_429"
                    configName: qsTr("Lub A.Boot")
                }
                Grid{
                    columns: 3
                    ICIMMText{text: qsTr("Lub.Mold Count")}
                    ICIMMText{text: qsTr("Lub.Mold Time")}
                    ICIMMText{text: qsTr("Lub.Che Time")}

                    ICIMMLineEdit{
                        id:m_rw_0_24_0_429
                        configAddr: "m_rw_0_24_0_429"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_16_2_428
                        configAddr: "m_rw_0_16_2_428"
                        unit: qsTr("s")
                    }
                    ICIMMLineEdit{
                        id:m_rw_16_16_2_428
                        configAddr: "m_rw_16_16_2_428"
                        unit: qsTr("s")
                    }
                }
            }
        }
    }
}

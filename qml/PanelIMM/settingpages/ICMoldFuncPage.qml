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
        return "ICBlowCVMonitorPage.qml";
    }
    ICSettingPageBase{
        id:moldPage1
        width: parent.width
        height: parent.height
        onEditorFocusChanged: {
            instance.editorFocusChanged(now);
        }
        ICIMMSettingConfigsScope{
            ICIMMFrame{
                id:topRow
                width: moldPage1.width
                height: moldPage1.height * 0.64
                Grid{
                    id:closeMoldContainer
                    x:4
                    y:2
                    columns: 4
                    ICIMMText{text:qsTr("CLOSE")}
                    ICIMMText{text:qsTr("PRES")}
                    ICIMMText{text:qsTr("SPE")}
                    ICIMMText{text:qsTr("POSN")}

                    ICIMMText{}
                    ICIMMText{text:qsTr("(bar)")}
                    ICIMMText{text:qsTr("(%)")}
                    ICIMMText{text:qsTr("(mm)")}

                    ICIMMText{text:qsTr("SEC1")}
                    ICIMMLineEdit{
                        id:m_rw_17_15_1_52
                        configAddr: "m_rw_17_15_1_52"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_10_1_53
                        configAddr: "m_rw_0_10_1_53"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_17_2_52
                        configAddr: "m_rw_0_17_2_52"
                    }

                    ICIMMText{text:qsTr("SEC2")}
                    ICIMMLineEdit{
                        id:m_rw_17_15_1_56
                        configAddr: "m_rw_17_15_1_56"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_10_1_57
                        configAddr: "m_rw_0_10_1_57"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_17_2_56
                        configAddr: "m_rw_0_17_2_56"
                    }

                    ICIMMText{text:qsTr("SEC3")}
                    ICIMMLineEdit{
                        id:m_rw_17_15_1_60
                        configAddr: "m_rw_17_15_1_60"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_10_1_61
                        configAddr: "m_rw_0_10_1_61"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_17_2_60
                        configAddr: "m_rw_0_17_2_60"
                    }

                    ICIMMText{text:qsTr("SEC4")}
                    ICIMMLineEdit{
                        id:m_rw_17_15_1_64
                        configAddr: "m_rw_17_15_1_64"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_10_1_65
                        configAddr: "m_rw_0_10_1_65"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_17_2_64
                        configAddr: "m_rw_0_17_2_64"
                    }

                    ICIMMText{text:qsTr("LP.")}
                    ICIMMLineEdit{
                        id:m_rw_17_15_1_84
                        configAddr: "m_rw_17_15_1_84"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_10_1_85
                        configAddr: "m_rw_0_10_1_85"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_17_2_84
                        configAddr: "m_rw_0_17_2_84"
                    }

                    ICIMMText{text:qsTr("HP.")}
                    ICIMMLineEdit{
                        id:m_rw_17_15_1_88
                        configAddr: "m_rw_17_15_1_88"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_10_1_89
                        configAddr: "m_rw_0_10_1_89"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_17_2_88
                        configAddr: "m_rw_0_17_2_88"
                    }

                }
                ICVerSplitLine{
                    id:verSplitLine1
                    height: topRow.height
                    anchors.left: closeMoldContainer.right
                    anchors.leftMargin: 4
                }
                Grid{
                    id:openMoldContainer
                    x:4
                    y:2
                    anchors.left: verSplitLine1.right
                    anchors.leftMargin: verSplitLine1.anchors.leftMargin
                    columns: 4
                    ICIMMText{text:qsTr("OPEN")}
                    ICIMMText{text:qsTr("PRES")}
                    ICIMMText{text:qsTr("SPE")}
                    ICIMMText{text:qsTr("POSN")}

                    ICIMMText{}
                    ICIMMText{text:qsTr("(bar)")}
                    ICIMMText{text:qsTr("(%)")}
                    ICIMMText{text:qsTr("(mm)")}

                    ICIMMText{text:qsTr("SEC1")}
                    ICIMMLineEdit{
                        id:m_rw_17_15_1_102
                        configAddr: "m_rw_17_15_1_102"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_10_1_103
                        configAddr: "m_rw_0_10_1_103"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_17_2_102
                        configAddr: "m_rw_0_17_2_102"
                    }

                    ICIMMText{text:qsTr("SEC2")}
                    ICIMMLineEdit{
                        id:m_rw_17_15_1_106
                        configAddr: "m_rw_17_15_1_106"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_10_1_107
                        configAddr: "m_rw_0_10_1_107"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_17_2_106
                        configAddr: "m_rw_0_17_2_106"
                    }

                    ICIMMText{text:qsTr("SEC3")}
                    ICIMMLineEdit{
                        id:m_rw_17_15_1_110
                        configAddr: "m_rw_17_15_1_110"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_10_1_111
                        configAddr: "m_rw_0_10_1_111"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_17_2_110
                        configAddr: "m_rw_0_17_2_110"
                    }

                    ICIMMText{text:qsTr("SEC4")}
                    ICIMMLineEdit{
                        id:m_rw_17_15_1_114
                        configAddr: "m_rw_17_15_1_114"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_10_1_115
                        configAddr: "m_rw_0_10_1_115"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_17_2_114
                        configAddr: "m_rw_0_17_2_114"
                    }

                    ICIMMText{text:qsTr("SEC5")}
                    ICIMMLineEdit{
                        id:m_rw_17_15_1_118
                        configAddr: "m_rw_17_15_1_118"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_10_1_119
                        configAddr: "m_rw_0_10_1_119"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_17_2_118
                        configAddr: "m_rw_0_17_2_118"
                    }

                    ICIMMText{text:qsTr("SEC6")}
                    ICIMMLineEdit{
                        id:m_rw_17_15_1_122
                        configAddr: "m_rw_17_15_1_122"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_10_1_123
                        configAddr: "m_rw_0_10_1_123"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_17_2_122
                        configAddr: "m_rw_0_17_2_122"
                    }

                }
                ICVerSplitLine{
                    id:verSplitLine2
                    height: verSplitLine1.height
                    anchors.left: openMoldContainer.right
                    anchors.leftMargin: 4
                }
                Column{
                    id:otherContainer
                    y:closeMoldContainer.y
                    anchors.left: verSplitLine2.right
                    anchors.leftMargin: verSplitLine2.anchors.leftMargin
                    ICIMMLabelLineEdit{
                        id:m_rw_16_16_2_94
                        configAddr: "m_rw_16_16_2_94"
                        configName: qsTr("LP.Protect")
                        unit: qsTr("s")
                        configNameWidth: m_rw_0_16_0_144.configNameWidth
                    }
                    ICIMMLabelLineEdit{
                        id:m_rw_0_16_0_144
                        configAddr: "m_rw_0_16_0_144"
                        configName: qsTr("OM.Protect")
                        unit: qsTr("s")
//                        configNameWidth: m_rw_16_16_2_94.configNameWidth
                    }
                    ICIMMLabelLineEdit{
                        id:m_rw_17_15_2_421
                        configAddr: "m_rw_17_15_2_421"
                        configName: qsTr("Rec.Time")
                        unit: qsTr("s")
                        configNameWidth: m_rw_16_16_2_94.configNameWidth
                    }
                    ICIMMLabelLineEdit{
                        id:m_rw_0_16_2_92
                        configAddr: "m_rw_0_16_2_92"
                        configName: qsTr("CM.B.Delay")
                        unit: qsTr("s")
                        configNameWidth: m_rw_16_16_2_94.configNameWidth
                    }
                    ICIMMLabelLineEdit{
                        id:m_rw_0_16_2_142
                        configAddr: "m_rw_0_16_2_142"
                        configName: qsTr("OM.B.Delay")
                        unit: qsTr("s")
                        configNameWidth: m_rw_16_16_2_94.configNameWidth
                    }
                    ICIMMLabelLineEdit{
                        id:m_rw_0_16_2_96
                        configAddr: "m_rw_0_16_2_96"
                        configName: qsTr("MT.O.Delay")
                        unit: qsTr("s")
                        configNameWidth: m_rw_16_16_2_94.configNameWidth
                    }
                    ICIMMCheckBoxEdit{
                        id:m_rw_0_1_0_94
                        configAddr: "m_rw_0_1_0_94"
                        configName: qsTr("D.C En")
                    }
                    ICIMMLabelLineEdit{
                        id:m_rw_1_15_2_94
                        configAddr: "m_rw_1_15_2_94"
                        configName: qsTr("D.C.Delay")
                        unit: qsTr("s")
                        configNameWidth: m_rw_16_16_2_94.configNameWidth
                    }
                }
            }
            ICIMMFrame{
                id:bottomRow
                height: moldPage1.height - topRow.height
                anchors.top: topRow.bottom
                Grid{
                    id:ejeADContainer
                    x:closeMoldContainer.x
                    y:closeMoldContainer.y
                    columns: 4
                    ICIMMText{text: qsTr("EJE.AD")}
                    ICIMMText{text: qsTr("PRES")}
                    ICIMMText{text: qsTr("SPE")}
                    ICIMMText{text: qsTr("POSN")}

                    ICIMMText{}
                    ICIMMText{text: qsTr("(bar)")}
                    ICIMMText{text: qsTr("(%)")}
                    ICIMMText{text: qsTr("(mm)")}

                    ICIMMText{text: qsTr("SEC1")}
                    ICIMMLineEdit{
                        id:m_rw_17_15_1_299
                        configAddr: "m_rw_17_15_1_299"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_10_1_300
                        configAddr: "m_rw_0_10_1_300"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_17_2_299
                        configAddr: "m_rw_0_17_2_299"
                    }

                    ICIMMText{text: qsTr("SEC2")}
                    ICIMMLineEdit{
                        id:m_rw_17_15_1_303
                        configAddr: "m_rw_17_15_1_303"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_10_1_304
                        configAddr: "m_rw_0_10_1_304"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_17_2_303
                        configAddr: "m_rw_0_17_2_303"
                    }
                }

                ICVerSplitLine{
                    id:verSplitLine3
                    height: parent.height
                    anchors.left: ejeADContainer.right
                    anchors.leftMargin: verSplitLine1.anchors.leftMargin
                }

                Grid{
                    id:ejeRETContainer
                    y:ejeADContainer.y
                    anchors.left: verSplitLine3.right
                    anchors.leftMargin: verSplitLine3.anchors.leftMargin
                    columns: 4
                    ICIMMText{text: qsTr("EJE.RET")}
                    ICIMMText{text: qsTr("PRES")}
                    ICIMMText{text: qsTr("SPE")}
                    ICIMMText{text: qsTr("POSN")}

                    ICIMMText{}
                    ICIMMText{text: qsTr("(bar)")}
                    ICIMMText{text: qsTr("(%)")}
                    ICIMMText{text: qsTr("(mm)")}

                    ICIMMText{text: qsTr("SEC1")}
                    ICIMMLineEdit{
                        id:m_rw_17_15_1_311
                        configAddr: "m_rw_17_15_1_311"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_10_1_312
                        configAddr: "m_rw_0_10_1_312"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_17_2_311
                        configAddr: "m_rw_0_17_2_311"
                    }

                    ICIMMText{text: qsTr("SEC2")}
                    ICIMMLineEdit{
                        id:m_rw_17_15_1_315
                        configAddr: "m_rw_17_15_1_315"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_10_1_316
                        configAddr: "m_rw_0_10_1_316"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_17_2_315
                        configAddr: "m_rw_0_17_2_315"
                    }
                }

                ICVerSplitLine{
                    id:verSplitLine4
                    height: parent.height
                    anchors.left: ejeRETContainer.right
                    anchors.leftMargin: verSplitLine3.anchors.leftMargin
                }

                ICIMMLabelComboBoxEdit{
                    id:m_rw_4_4_0_421
                    anchors.left: verSplitLine4.right
                    anchors.leftMargin: verSplitLine4.anchors.leftMargin
                    y:ejeRETContainer.y
                    configAddr: "m_rw_4_4_0_421"
                    configName: qsTr("EJECT MODE")
                    items: [qsTr("UNUSE"), qsTr("REPEATED"), qsTr("OSILLATE"), qsTr("HOLDING")]
                    configNameWidth: m_rw_8_8_0_421.configNameWidth
                    popupMode: 1
                    z:2
                }
                Column{
                    id:ejeOtherContainer
                    anchors.left: verSplitLine4.right
                    anchors.leftMargin: verSplitLine4.anchors.leftMargin
                    anchors.top: m_rw_4_4_0_421.bottom
                    ICIMMLabelLineEdit{
                        id:m_rw_8_8_0_421
                        configAddr: "m_rw_8_8_0_421"
                        configName: qsTr("EJECT COUNT")
                        unit: qsTr("times")
//                        configNameWidth: m_rw_0_16_2_307.configNameWidth
                        inputWidth: 70 * Style.wRatio
                    }
                    ICIMMLabelLineEdit{
                        id:m_rw_0_16_2_307
                        configAddr: "m_rw_0_16_2_307"
                        configName: qsTr("B.EJ.F Delay")
                        unit: qsTr("s")
                        configNameWidth: m_rw_8_8_0_421.configNameWidth
                        inputWidth: m_rw_8_8_0_421.inputWidth
                    }
                    ICIMMLabelLineEdit{
                        id:m_rw_0_16_2_319
                        configAddr: "m_rw_0_16_2_319"
                        configName: qsTr("B.EJ.B Delay")
                        unit: qsTr("s")
                        configNameWidth: m_rw_8_8_0_421.configNameWidth
                        inputWidth: m_rw_8_8_0_421.inputWidth
                    }
                }

                Column{
                    id:ejeOtherContainer1
                    anchors.left: ejeOtherContainer.right
                    anchors.leftMargin: 4
                    y: ejeOtherContainer.y
                    ICIMMLabelLineEdit{
                        id:m_rw_0_16_2_309
                        configAddr: "m_rw_0_16_2_309"
                        configName: qsTr("O.T.EJ.F D")
                        unit: qsTr("s")
                        inputWidth: m_rw_8_8_0_421.inputWidth
                    }
                    ICIMMCheckBoxEdit{
                        id:m_rw_16_1_0_421
                        configAddr: "m_rw_16_1_0_421"
                        configName: qsTr("Robot En")
                    }
                }
            }

        }
    }
}

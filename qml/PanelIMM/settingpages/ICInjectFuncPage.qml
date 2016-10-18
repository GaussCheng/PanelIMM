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
        return "";
    }
    ICSettingPageBase{
        id:injectPage1
        width: parent.width
        height: parent.height
        onEditorFocusChanged: {
            instance.editorFocusChanged(now);
        }
        ICIMMSettingConfigsScope{
            ICIMMFrame{
                id:topRow
                width: injectPage1.width
                height: injectPage1.height * 0.68
                Grid{
                    id:injectContainer
                    x:4
                    y:2
                    columns: 4
                    ICIMMText{text:qsTr("INJ.")}
                    ICIMMText{text:qsTr("PRES")}
                    ICIMMText{text:qsTr("SPE")}
                    ICIMMText{text:qsTr("POSN")}

                    ICIMMText{}
                    ICIMMText{text:qsTr("(bar)")}
                    ICIMMText{text:qsTr("(%)")}
                    ICIMMText{text:qsTr("(mm)")}

                    ICIMMText{text:qsTr("SEC1")}
                    ICIMMLineEdit{
                        id:m_rw_17_15_1_152
                        configAddr: "m_rw_17_15_1_152"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_10_1_153
                        configAddr: "m_rw_0_10_1_153"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_17_2_152
                        configAddr: "m_rw_0_17_2_152"
                    }

                    ICIMMText{text:qsTr("SEC2")}
                    ICIMMLineEdit{
                        id:m_rw_17_15_1_156
                        configAddr: "m_rw_17_15_1_156"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_10_1_157
                        configAddr: "m_rw_0_10_1_157"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_17_2_156
                        configAddr: "m_rw_0_17_2_156"
                    }

                    ICIMMText{text:qsTr("SEC3")}
                    ICIMMLineEdit{
                        id:m_rw_17_15_1_160
                        configAddr: "m_rw_17_15_1_160"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_10_1_161
                        configAddr: "m_rw_0_10_1_161"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_17_2_160
                        configAddr: "m_rw_0_17_2_160"
                    }

                    ICIMMText{text:qsTr("SEC4")}
                    ICIMMLineEdit{
                        id:m_rw_17_15_1_164
                        configAddr: "m_rw_17_15_1_164"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_10_1_165
                        configAddr: "m_rw_0_10_1_165"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_17_2_164
                        configAddr: "m_rw_0_17_2_164"
                    }

                    ICIMMText{text:qsTr("SEC5")}
                    ICIMMLineEdit{
                        id:m_rw_17_15_1_168
                        configAddr: "m_rw_17_15_1_168"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_10_1_169
                        configAddr: "m_rw_0_10_1_169"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_17_2_168
                        configAddr: "m_rw_0_17_2_168"
                    }

                }
                ICIMMLabelComboBoxEdit{
                    id:m_rw_20_4_0_199
                    x:injectContainer.x
                    anchors.top: injectContainer.bottom
                    configAddr: "m_rw_20_4_0_199"
                    configName: qsTr("INJ.T.H.Mode")
                    items: [qsTr("POSN"), qsTr("TIME"), qsTr("POSN + TIME")]
                    inputWidth: m_rw_0_17_2_168.x + m_rw_0_17_2_168.width - x - configNameWidth + 2
                }
                ICIMMLabelLineEdit{
                    id:m_rw_0_20_2_199
                    anchors.top: m_rw_20_4_0_199.bottom
                    configAddr: "m_rw_0_20_2_199"
                    configName: qsTr("Total Time")
                    unit: qsTr("s")
                    configNameWidth: m_rw_20_4_0_199.configNameWidth
                    inputWidth: m_rw_20_4_0_199.inputWidth
                    x:m_rw_20_4_0_199.x
                }

                ICVerSplitLine{
                    id:verSplitLine1
                    height: parent.height
                    anchors.left: injectContainer.right
                    anchors.leftMargin: 4
                }

                Grid{
                    id:holdContainer
                    y:injectContainer.y
                    columns: 4
                    anchors.left: verSplitLine1.right
                    anchors.leftMargin: verSplitLine1.anchors.leftMargin
                    ICIMMText{text:qsTr("HP.")}
                    ICIMMText{text:qsTr("PRES")}
                    ICIMMText{text:qsTr("SPE")}
                    ICIMMText{text:qsTr("TIME")}

                    ICIMMText{}
                    ICIMMText{text:qsTr("(bar)")}
                    ICIMMText{text:qsTr("(%)")}
                    ICIMMText{text:qsTr("(s)")}

                    ICIMMText{text:qsTr("SEC1")}
                    ICIMMLineEdit{
                        id:m_rw_17_15_1_202
                        configAddr: "m_rw_17_15_1_202"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_10_1_203
                        configAddr: "m_rw_0_10_1_203"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_17_3_202
                        configAddr: "m_rw_0_17_3_202"
                    }

                    ICIMMText{text:qsTr("SEC2")}
                    ICIMMLineEdit{
                        id:m_rw_17_15_1_206
                        configAddr: "m_rw_17_15_1_206"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_10_1_207
                        configAddr: "m_rw_0_10_1_207"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_17_3_206
                        configAddr: "m_rw_0_17_3_206"
                    }

                    ICIMMText{text:qsTr("SEC3")}
                    ICIMMLineEdit{
                        id:m_rw_17_15_1_210
                        configAddr: "m_rw_17_15_1_210"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_10_1_211
                        configAddr: "m_rw_0_10_1_211"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_17_3_210
                        configAddr: "m_rw_0_17_3_210"
                    }

                    ICIMMText{text:qsTr("SEC4")}
                    ICIMMLineEdit{
                        id:m_rw_17_15_1_214
                        configAddr: "m_rw_17_15_1_214"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_10_1_215
                        configAddr: "m_rw_0_10_1_215"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_17_3_214
                        configAddr: "m_rw_0_17_3_214"
                    }

                    ICIMMText{text:qsTr("SEC5")}
                    ICIMMLineEdit{
                        id:m_rw_17_15_1_218
                        configAddr: "m_rw_17_15_1_218"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_10_1_219
                        configAddr: "m_rw_0_10_1_219"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_17_3_218
                        configAddr: "m_rw_0_17_3_218"
                    }

                }

                ICVerSplitLine{
                    id:verSplitLine2
                    height: parent.height
                    anchors.left: holdContainer.right
                    anchors.leftMargin: verSplitLine1.anchors.leftMargin
                }

                Column{
                    y:holdContainer.y
                    anchors.left: verSplitLine2.right
                    anchors.leftMargin: verSplitLine2.anchors.leftMargin
                    ICIMMLabelLineEdit{
                        id:m_rw_0_16_0_200
                        configAddr: "m_rw_0_16_0_200"
                        configName: qsTr("INJ.Protect")
                        unit: qsTr("s")
                        configNameWidth: m_rw_0_16_2_192.configNameWidth
                    }
                    ICIMMLabelLineEdit{
                        id:m_rw_0_16_2_192
                        configAddr: "m_rw_0_16_2_192"
                        configName: qsTr("INJ.B.Delay")
                        unit: qsTr("s")
                    }
                }
            }

            ICIMMFrame{
                id:bottomRow
                width: injectPage1.width
                height: injectPage1.height - topRow.height
                anchors.top: topRow.bottom
                Grid{
                    id:preInjectContainer
                    x:4
                    y:2
                    columns: 3
                    ICIMMCheckBoxEdit{
                        id:m_rw_16_1_0_200
                        configAddr: "m_rw_16_1_0_200"
                        configName: qsTr("Pre En")
                    }
                    ICIMMText{text: "  "}
                    ICIMMLabelComboBoxEdit{
                        id:m_rw_17_3_0_200
                        configAddr: "m_rw_17_3_0_200"
                        configName: qsTr("Pre Mode")
                        items: m_rw_20_4_0_199.items
                    }
                    ICIMMLabelLineEdit{
                        id:m_rw_20_12_2_200
                        configAddr: "m_rw_20_12_2_200"
                        configName: qsTr("Pre TIME")
                        configNameWidth: m_rw_17_15_0_284.configNameWidth
                        unit: qsTr("s")
                    }
                    ICIMMText{text: "  "}
                    ICIMMLabelLineEdit{
                        id:m_rw_8_16_1_201
                        configAddr: "m_rw_8_16_1_201"
                        configName: qsTr("Pre POSN")
                        unit: qsTr("mm")
                    }
                    ICIMMLabelLineEdit{
                        id:m_rw_17_15_0_284
                        configAddr: "m_rw_17_15_0_284"
                        configName: qsTr("Pre PRES")
                        unit: qsTr("bar")
                    }
                    ICIMMText{text: "  "}
                    ICIMMLabelLineEdit{
                        id:m_rw_24_8_0_199
                        configAddr: "m_rw_24_8_0_199"
                        configName: qsTr("Pre SPE")
                        configNameWidth: m_rw_8_16_1_201.configNameWidth
                        unit: qsTr("%")
                    }

                }
            }
        }
    }
}

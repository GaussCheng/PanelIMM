import QtQuick 1.1
import "../../ICCustomElement"
import "../immcustomitems"
import "../../styles/style.js" as Style
ICIMMFunctionPageBase {
    id:instance
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
                height: page1.height
                Grid{
                    id:carrContainer
                    x:4
                    y:2
                    columns: 4
                    ICIMMText{text:qsTr("CARR")}
                    ICIMMText{text:qsTr("PRES")}
                    ICIMMText{text:qsTr("SPE")}
                    ICIMMText{text:qsTr("POSN")}

                    ICIMMText{}
                    ICIMMText{text:qsTr("(bar)")}
                    ICIMMText{text:qsTr("(%)")}
                    ICIMMText{text:qsTr("(mm)")}

                    ICIMMText{text:qsTr("F.Fast")}
                    ICIMMLineEdit{
                        id:m_rw_17_15_1_368
                        configAddr: "m_rw_17_15_1_368"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_10_1_369
                        configAddr: "m_rw_0_10_1_369"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_17_2_368
                        configAddr: "m_rw_0_17_2_368"
                    }

                    ICIMMText{text:qsTr("F.Slow")}
                    ICIMMLineEdit{
                        id:m_rw_17_15_1_372
                        configAddr: "m_rw_17_15_1_372"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_10_1_373
                        configAddr: "m_rw_0_10_1_373"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_17_2_372
                        configAddr: "m_rw_0_17_2_372"
                    }

                    ICIMMText{text:qsTr("BW")}
                    ICIMMLineEdit{
                        id:m_rw_17_15_1_380
                        configAddr: "m_rw_17_15_1_380"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_10_1_381
                        configAddr: "m_rw_0_10_1_381"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_17_2_380
                        configAddr: "m_rw_0_17_2_380"
                    }
                }
                ICVerSplitLine{
                    id:verSplitLine1
                    height: topRow.height
                    anchors.left: carrContainer.right
                    anchors.leftMargin: 4
                }
                Grid{
                    id:otherContainer
                    x:4
                    y:2
                    anchors.left: verSplitLine1.right
                    anchors.leftMargin: verSplitLine1.anchors.leftMargin
                    columns: 3
                    ICIMMLabelLineEdit{
                        id:m_rw_0_16_0_378
                        configAddr: "m_rw_0_16_0_378"
                        configName: qsTr("FWD_PROT")
                        unit: qsTr("s")
                        configNameWidth: m_rw_0_4_0_386.configNameWidth
                    }
                    ICIMMText{width: 10}
                    ICIMMLabelLineEdit{
                        id:m_rw_4_16_2_386
                        configAddr: "m_rw_4_16_2_386"
                        configName: qsTr("BWD-TIME")
                        unit: qsTr("s")
                    }
                    ICIMMLabelComboBoxEdit{
                        id:m_rw_0_4_0_386
                        configAddr: "m_rw_0_4_0_386"
                        configName: qsTr("BWD-MODE")
                        items: [qsTr("TIME"), qsTr("POSN")]
                    }
                    ICIMMText{width: 10}
                    ICIMMCheckBoxEdit{
                        id:m_rw_20_1_0_386
                        configAddr: "m_rw_20_1_0_386"
                        configName: qsTr("Man.Ret.No.Limit")
                    }

                    ICIMMLabelLineEdit{
                        id:m_rw_0_16_2_376
                        configAddr: "m_rw_0_16_2_376"
                        configName: qsTr("D.FB.DLY")
                        unit: qsTr("s")
                        configNameWidth: m_rw_0_4_0_386.configNameWidth
                    }
                    ICIMMText{width: 10}
                    ICIMMLabelLineEdit{
                        id:m_rw_0_16_2_384
                        configAddr: "m_rw_0_16_2_384"
                        configName: qsTr("D.BB.DLY")
                        unit: qsTr("s")
                        configNameWidth: m_rw_4_16_2_386.configNameWidth
                    }
                }
            }
        }
    }
}

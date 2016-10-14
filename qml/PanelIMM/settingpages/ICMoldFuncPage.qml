import QtQuick 1.1
import "../../ICCustomElement"
import "../immcustomitems"
ICIMMFunctionPageBase {
    id:instance
    property variant detailsMenuItems: {
        "f6":qsTr("Aid Settings"),
    }
    function onF6Triggered(){
        return "";
    }
    ICSettingPageBase{
        id:moldPage1
        width: parent.width
        height: parent.height
        onEditorFocusChanged: {
            instance.editorFocusChanged(now);
        }
        ICSettingConfigsScope{
            ICIMMFrame{
                id:topRow
                width: moldPage1.width
                height: moldPage1.height * 0.65
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
                    anchors.left: verSplitLine2.right
                    anchors.leftMargin: verSplitLine2.anchors.leftMargin
                }
            }
        }
    }
}

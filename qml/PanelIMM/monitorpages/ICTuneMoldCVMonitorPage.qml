import QtQuick 1.1
import "../../ICCustomElement"
import "../immcustomitems"
import "../../styles/style.js" as Style

ICSettingPageBase {
    id:instance
    ICIMMSettingConfigsScope{
        Grid{
            id:manualContainer
            x:4
            y:2
            columns: 5
            ICIMMText{
                id:manualLabel
                text: qsTr("Manual")
            }
            ICIMMText{}
            ICIMMText{text: qsTr("Tune.F")}
            ICIMMText{text: qsTr("Tune.B")}
            ICIMMText{text: qsTr("Tune.CM")}
//            ICIMMButton{
//                id:moldBaseZero
//                text: qsTr("Zero")
//            }

            ICIMMText{text: qsTr("PRES")}
            ICIMMText{text: qsTr("(bar)")}
            ICIMMLineEdit{
                id:m_rw_0_16_0_388
                configAddr: "m_rw_0_16_0_388"
            }
            ICIMMLineEdit{
                id:m_rw_16_16_0_388
                configAddr: "m_rw_16_16_0_388"
            }
            ICIMMLineEdit{
                id:m_rw_16_16_0_389
                configAddr: "m_rw_16_16_0_389"
            }
//            ICIMMText{}

            ICIMMText{text: qsTr("SPE")}
            ICIMMText{text: qsTr("(%)")}
            ICIMMLineEdit{
                id:m_rw_0_8_0_389
                configAddr: "m_rw_0_8_0_389"
            }
            ICIMMLineEdit{
                id:m_rw_8_8_0_389
                configAddr: "m_rw_8_8_0_389"
            }
            ICIMMLineEdit{
                id:m_rw_0_8_0_390
                configAddr: "m_rw_0_8_0_390"
            }
//            ICIMMText{}
        }
        ICHorSplitLine{
            id:horSplitLine1
            anchors.top: manualContainer.bottom
            anchors.topMargin: 4
            width: verSplitLine1.x
        }
        Grid{
            id:autoContainer
            x:manualContainer.x
            anchors.top: horSplitLine1.bottom
            anchors.topMargin: horSplitLine1.anchors.topMargin
            columns: 5
            ICIMMText{
                text: qsTr("Auto")
                width: manualLabel.width
            }
            ICIMMText{}
            ICIMMText{text: qsTr("Tune.F")}
            ICIMMText{text: qsTr("Tune.B")}
            ICIMMText{text: qsTr("Tune.CM")}

            ICIMMText{text: qsTr("PRES")}
            ICIMMText{text: qsTr("(bar)")}
            ICIMMLineEdit{
                id:s_rw_0_16_0_391
                configAddr: "s_rw_0_16_0_391"
            }
            ICIMMLineEdit{
                id:s_rw_16_16_0_391
                configAddr: "s_rw_16_16_0_391"
            }
            ICIMMLineEdit{
                id:s_rw_16_16_0_392
                configAddr: "s_rw_16_16_0_392"
            }

            ICIMMText{text: qsTr("SPE")}
            ICIMMText{text: qsTr("(%)")}
            ICIMMLineEdit{
                id:s_rw_0_8_0_392
                configAddr: "s_rw_0_8_0_392"
            }
            ICIMMLineEdit{
                id:s_rw_8_8_0_392
                configAddr: "s_rw_8_8_0_392"
            }
            ICIMMLineEdit{
                id:s_rw_0_8_0_393
                configAddr: "s_rw_0_8_0_393"
            }
        }

        ICVerSplitLine{
            id:verSplitLine1
            anchors.left: autoContainer.right
            height: instance.height
            anchors.leftMargin: 2
        }
        Column{
            anchors.left: verSplitLine1.left
            anchors.leftMargin: 2
            y:2
            ICIMMLabelComboBoxEdit{
                id:s_rw_0_1_0_396
                configAddr: "s_rw_0_1_0_396"
                configName: qsTr("Tune M")
                inputWidth: 70 * Style.wRatio
                items: [qsTr("Time"), qsTr("TOOTH")]
                z:2
            }
            ICIMMLabelLineEdit{
                id:s_rw_1_10_0_396
                configAddr: "s_rw_1_10_0_396"
                configName: qsTr("C.TT")
                unit: qsTr("PC")
                inputWidth: s_rw_0_1_0_396.inputWidth
                configNameWidth: s_rw_0_1_0_396.configNameWidth
            }
            ICIMMLabelLineEdit{
                id:s_rw_11_10_0_396
                configAddr: "s_rw_11_10_0_396"
                configName: qsTr("F.TT")
                unit: qsTr("PC")
                inputWidth: s_rw_0_1_0_396.inputWidth
                configNameWidth: s_rw_0_1_0_396.configNameWidth
            }
            ICIMMLabelLineEdit{
                id:s_rw_0_16_2_397
                configAddr: "s_rw_0_16_2_397"
                configName: qsTr("C.TM")
                unit: qsTr("s")
                inputWidth: s_rw_0_1_0_396.inputWidth
                configNameWidth: s_rw_0_1_0_396.configNameWidth
            }
            ICIMMLabelLineEdit{
                id:s_rw_16_16_2_397
                configAddr: "s_rw_16_16_2_397"
                configName: qsTr("F.TM")
                unit: qsTr("s")
                inputWidth: s_rw_0_1_0_396.inputWidth
                configNameWidth: s_rw_0_1_0_396.configNameWidth
            }
        }
    }
}

import QtQuick 1.1
import "../../ICCustomElement"
import "../immcustomitems"
import "../../styles/style.js" as Style
ICSettingPageBase {
    ICSettingConfigsScope{
        Grid{
            columns: 5
            x:4
            y:2
            ICIMMText{text: qsTr("Blow")}
            ICIMMText{text: qsTr("Mode")}
            ICIMMText{text: qsTr("ACT POSN")}
            ICIMMText{text: qsTr("ACT TIME")}
            ICIMMText{text: qsTr("DELAY")}

            ICIMMText{height: font.pixelSize}
            ICIMMText{height: font.pixelSize}
            ICIMMText{text: qsTr("(mm)");height: font.pixelSize}
            ICIMMText{text: qsTr("(s)");height: font.pixelSize}
            ICIMMText{text: qsTr("(s)");height: font.pixelSize}

            ICIMMText{text: qsTr("S-MD-AIR1")}
            ICIMMLabelComboBoxEdit{
                id:m_rw_0_4_0_323
                configAddr: "m_rw_0_4_0_323"
                items: [qsTr("UNUSE"), qsTr("OM.Pos"), qsTr("INJ.Pos"), qsTr("EJE.Pos"), qsTr("CM.Pos")]
                inputWidth: 80 * Style.wRatio
                z:10
            }
            ICIMMLineEdit{
                id:m_rw_15_17_1_323
                configAddr: "m_rw_15_17_1_323"
            }
            ICIMMLineEdit{
                id:m_rw_0_16_2_324
                configAddr: "m_rw_0_16_2_324"
            }
            ICIMMLineEdit{
                id:m_rw_16_16_2_324
                configAddr: "m_rw_16_16_2_324"
            }

            ICIMMText{text: qsTr("S-MD-AIR2")}
            ICIMMLabelComboBoxEdit{
                id:m_rw_0_4_0_325
                configAddr: "m_rw_0_4_0_325"
                items: m_rw_0_4_0_323.items
                inputWidth: m_rw_0_4_0_323.inputWidth
                z:9
            }
            ICIMMLineEdit{
                id:m_rw_15_17_1_325
                configAddr: "m_rw_15_17_1_325"
            }
            ICIMMLineEdit{
                id:m_rw_0_16_2_326
                configAddr: "m_rw_0_16_2_326"
            }
            ICIMMLineEdit{
                id:m_rw_16_16_2_326
                configAddr: "m_rw_16_16_2_326"
            }

            ICIMMText{text: qsTr("S-MD-AIR3")}
            ICIMMLabelComboBoxEdit{
                id:m_rw_0_4_0_327
                configAddr: "m_rw_0_4_0_327"
                items: m_rw_0_4_0_323.items
                inputWidth: m_rw_0_4_0_323.inputWidth
                z:8
            }
            ICIMMLineEdit{
                id:m_rw_15_17_1_327
                configAddr: "m_rw_15_17_1_327"
            }
            ICIMMLineEdit{
                id:m_rw_0_16_2_328
                configAddr: "m_rw_0_16_2_328"
            }
            ICIMMLineEdit{
                id:m_rw_16_16_2_328
                configAddr: "m_rw_16_16_2_328"
            }

            ICIMMText{text: qsTr("M-MD-AIR1")}
            ICIMMLabelComboBoxEdit{
                id:m_rw_0_4_0_329
                configAddr: "m_rw_0_4_0_329"
                items: m_rw_0_4_0_323.items
                inputWidth: m_rw_0_4_0_323.inputWidth
                z:7
            }
            ICIMMLineEdit{
                id:m_rw_15_17_1_329
                configAddr: "m_rw_15_17_1_329"
            }
            ICIMMLineEdit{
                id:m_rw_0_16_2_330
                configAddr: "m_rw_0_16_2_330"
            }
            ICIMMLineEdit{
                id:m_rw_16_16_2_330
                configAddr: "m_rw_16_16_2_330"
            }

            ICIMMText{text: qsTr("M-MD-AIR2")}
            ICIMMLabelComboBoxEdit{
                id:m_rw_0_4_0_331
                configAddr: "m_rw_0_4_0_331"
                items: m_rw_0_4_0_323.items
                inputWidth: m_rw_0_4_0_323.inputWidth
                z:6
            }
            ICIMMLineEdit{
                id:m_rw_15_17_1_331
                configAddr: "m_rw_15_17_1_331"
            }
            ICIMMLineEdit{
                id:m_rw_0_16_2_332
                configAddr: "m_rw_0_16_2_332"
            }
            ICIMMLineEdit{
                id:m_rw_16_16_2_332
                configAddr: "m_rw_16_16_2_332"
            }

            ICIMMText{text: qsTr("M-MD-AIR3")}
            ICIMMLabelComboBoxEdit{
                id:m_rw_0_4_0_333
                configAddr: "m_rw_0_4_0_333"
                items: m_rw_0_4_0_323.items
                inputWidth: m_rw_0_4_0_323.inputWidth
                z:5
            }
            ICIMMLineEdit{
                id:m_rw_15_17_1_333
                configAddr: "m_rw_15_17_1_333"
            }
            ICIMMLineEdit{
                id:m_rw_0_16_2_334
                configAddr: "m_rw_0_16_2_334"
            }
            ICIMMLineEdit{
                id:m_rw_16_16_2_334
                configAddr: "m_rw_16_16_2_334"
            }
        }
    }
}

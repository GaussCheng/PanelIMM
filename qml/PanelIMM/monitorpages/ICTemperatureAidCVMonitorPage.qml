import QtQuick 1.1
import "../../ICCustomElement"
import "../immcustomitems"
import "../../styles/style.js" as Style
ICSettingPageBase {
    ICIMMSettingConfigsScope{
        Grid{
            columns: 5
            x:4
            y:2
            ICIMMText{text: qsTr("MAX_TEM")}
            ICIMMLineEdit{
                id:s_rw_16_10_0_485
                configAddr: "s_rw_16_10_0_485"
                unit: qsTr("°C")
            }
            ICIMMText{width: 10}
            ICIMMText{text: qsTr("OIL COOL")}
            ICIMMLineEdit{
                id:s_rw_23_7_0_489
                configAddr: "s_rw_23_7_0_489"
                unit: qsTr("°C")

            }
            ICIMMText{text: qsTr("TEMP.SEC NUM")}
            ICIMMLineEdit{
                id:s_rw_26_4_0_485
                configAddr: "s_rw_26_4_0_485"
                unit: qsTr("sec")
            }
            ICIMMText{width: 10}
            ICIMMText{text: qsTr("MAX OIL")}
            ICIMMLineEdit{
                id:s_rw_16_7_0_489
                configAddr: "s_rw_16_7_0_489"
                unit: qsTr("°C")
            }
            ICIMMText{text: qsTr("TEMP.CYC")}
            ICIMMLineEdit{
                id:s_rw_16_8_0_481
                configAddr: "s_rw_16_8_0_481"
                unit: qsTr("s")
            }
            ICIMMText{width: 10}
            ICIMMText{text: qsTr("NOZZ MODE")}
            ICIMMLabelComboBoxEdit{
                id:s_rw_31_1_0_481
                configAddr: "s_rw_31_1_0_481"
                items: [qsTr("OPEN"), qsTr("CLOSE")]
                inputWidth: 80 * Style.wRatio
            }
        }
    }
}

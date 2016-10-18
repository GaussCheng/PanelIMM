import QtQuick 1.1
import "../../ICCustomElement"
import "../immcustomitems"
import "../../styles/style.js" as Style
ICSettingPageBase {
    ICIMMSettingConfigsScope{
        Grid{
            columns: 2
            x:4
            y:2
            ICIMMText{text: qsTr("Core-A Func")}
            ICIMMLabelComboBoxEdit{
                id:m_rw_0_2_0_365
                configAddr: "m_rw_0_2_0_365"
                items: [qsTr("CORE"), qsTr("SCRW")]
                z:5
            }
            ICIMMText{text: qsTr("Core-B Func")}
            ICIMMLabelComboBoxEdit{
                id:m_rw_2_2_0_365
                configAddr: "m_rw_2_2_0_365"
                items: m_rw_0_2_0_365.items
                z:4
            }
            ICIMMText{text: qsTr("Core-C Func")}
            ICIMMLabelComboBoxEdit{
                id:m_rw_4_2_0_365
                configAddr: "m_rw_4_2_0_365"
                items: m_rw_0_2_0_365.items
                z:3
            }
            ICIMMText{text: qsTr("Core-D Func")}
            ICIMMLabelComboBoxEdit{
                id:m_rw_6_2_0_365
                configAddr: "m_rw_6_2_0_365"
                items: m_rw_0_2_0_365.items
                z:2
            }

            ICIMMCheckBoxEdit{
                id:m_rw_8_1_0_365
                configAddr: "m_rw_8_1_0_365"
                configName: qsTr("Core In Protect")
            }
            ICIMMCheckBoxEdit{
                id:m_rw_9_1_0_365
                configAddr: "m_rw_9_1_0_365"
                configName: qsTr("Special Core")
            }

        }
    }
}

import QtQuick 1.1
import "../../ICCustomElement"
import "../immcustomitems"
import "../../styles/style.js" as Style
ICSettingPageBase {
    ICIMMSettingConfigsScope{
        Grid{
            columns: 10
            x:4
            y:2
            ICIMMText{}
            ICIMMText{}
            ICIMMText{text: qsTr("NOZZ")}
            ICIMMText{text: qsTr("SEC1")}
            ICIMMText{text: qsTr("SEC2")}
            ICIMMText{text: qsTr("SEC3")}
            ICIMMText{text: qsTr("SEC4")}
            ICIMMText{text: qsTr("SEC5")}
            ICIMMText{text: qsTr("SEC6")}
            ICIMMText{text: qsTr("Oil.T")}


            ICIMMText{text: qsTr("M.V")}
            ICIMMText{text: qsTr("°C")}
            ICIMMStatusWidget{
                id:c_ro_0_16_1_1560
                bindStatus: "c_ro_0_16_1_1560"
                width: 42 * Style.wRatio
            }
            ICIMMStatusWidget{
                id:c_ro_16_16_1_1560
                bindStatus: "c_ro_16_16_1_1560"
                width: c_ro_0_16_1_1560.width
            }
            ICIMMStatusWidget{
                id:c_ro_0_16_1_1561
                bindStatus: "c_ro_0_16_1_1561"
                width: c_ro_0_16_1_1560.width
            }
            ICIMMStatusWidget{
                id:c_ro_16_16_1_1561
                bindStatus: "c_ro_16_16_1_1561"
                width: c_ro_0_16_1_1560.width
            }
            ICIMMStatusWidget{
                id:c_ro_0_16_1_1562
                bindStatus: "c_ro_0_16_1_1562"
                width: c_ro_0_16_1_1560.width
            }
            ICIMMStatusWidget{
                id:c_ro_16_16_1_1562
                bindStatus: "c_ro_16_16_1_1562"
                width: c_ro_0_16_1_1560.width
            }
            ICIMMStatusWidget{
                id:c_ro_0_16_1_1563
                bindStatus: "c_ro_0_16_1_1563"
                width: c_ro_0_16_1_1560.width
            }
            ICIMMStatusWidget{
                id:c_ro_16_16_1_1563
                bindStatus: "c_ro_16_16_1_1563"
                width: c_ro_0_16_1_1560.width
            }

            ICIMMText{text: qsTr("S.V")}
            ICIMMText{text: qsTr("°C")}
            ICIMMLineEdit{
                id:m_rw_0_16_0_462
                configAddr: "m_rw_0_16_0_462"
                width: c_ro_0_16_1_1560.width
            }
            ICIMMLineEdit{
                id:m_rw_16_16_0_462
                configAddr: "m_rw_16_16_0_462"
                width: c_ro_0_16_1_1560.width
            }
            ICIMMLineEdit{
                id:m_rw_0_16_0_463
                configAddr: "m_rw_0_16_0_463"
                width: c_ro_0_16_1_1560.width
            }
            ICIMMLineEdit{
                id:m_rw_16_16_0_463
                configAddr: "m_rw_16_16_0_463"
                width: c_ro_0_16_1_1560.width
            }
            ICIMMLineEdit{
                id:m_rw_0_16_0_464
                configAddr: "m_rw_0_16_0_464"
                width: c_ro_0_16_1_1560.width
            }
            ICIMMLineEdit{
                id:m_rw_16_16_0_464
                configAddr: "m_rw_16_16_0_464"
                width: c_ro_0_16_1_1560.width
            }
            ICIMMLineEdit{
                id:m_rw_0_16_0_465
                configAddr: "m_rw_0_16_0_465"
                width: c_ro_0_16_1_1560.width
            }
            ICIMMLineEdit{
                id:m_rw_16_16_0_465
                configAddr: "m_rw_16_16_0_465"
                width: c_ro_0_16_1_1560.width
            }

            ICIMMText{text: qsTr("P.V")}
            ICIMMText{text: qsTr("°C")}
            ICIMMLineEdit{
                id:m_rw_0_16_0_466
                configAddr: "m_rw_0_16_0_466"
                width: c_ro_0_16_1_1560.width
            }
            ICIMMLineEdit{
                id:m_rw_16_16_0_466
                configAddr: "m_rw_16_16_0_466"
                width: c_ro_0_16_1_1560.width
            }
            ICIMMLineEdit{
                id:m_rw_0_16_0_467
                configAddr: "m_rw_0_16_0_467"
                width: c_ro_0_16_1_1560.width
            }
            ICIMMLineEdit{
                id:m_rw_16_16_0_467
                configAddr: "m_rw_16_16_0_467"
                width: c_ro_0_16_1_1560.width
            }
            ICIMMLineEdit{
                id:m_rw_0_16_0_468
                configAddr: "m_rw_0_16_0_468"
                width: c_ro_0_16_1_1560.width
            }
            ICIMMLineEdit{
                id:m_rw_16_16_0_468
                configAddr: "m_rw_16_16_0_468"
                width: c_ro_0_16_1_1560.width
            }
            ICIMMLineEdit{
                id:m_rw_0_16_0_469
                configAddr: "m_rw_0_16_0_469"
                width: c_ro_0_16_1_1560.width
            }
            ICIMMText{}
        }
    }
}

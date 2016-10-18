import QtQuick 1.1
import "../../ICCustomElement"
import "../immcustomitems"
import "../../styles/style.js" as Style
ICSettingPageBase {
    ICSettingConfigsScope{
        Grid{
            columns: 9
            x:4
            y:2

            ICIMMText{}
            ICIMMText{}
            ICIMMText{id:widthLabel;text: qsTr("NOZZ")}
            ICIMMText{text: qsTr("SEC1")}
            ICIMMText{text: qsTr("SEC2")}
            ICIMMText{text: qsTr("SEC3")}
            ICIMMText{text: qsTr("SEC4")}
            ICIMMText{text: qsTr("SEC5")}
            ICIMMText{text: qsTr("SEC6")}

            ICIMMText{text: qsTr("B.En")}
            ICIMMText{}
            ICIMMCheckBoxEdit{
                id:s_rw_0_1_0_499
                configAddr: "s_rw_0_1_0_499"
            }
            ICIMMCheckBoxEdit{
                id:s_rw_1_1_0_499
                configAddr: "s_rw_1_1_0_499"
            }
            ICIMMCheckBoxEdit{
                id:s_rw_2_1_0_499
                configAddr: "s_rw_2_1_0_499"
            }
            ICIMMCheckBoxEdit{
                id:s_rw_3_1_0_499
                configAddr: "s_rw_3_1_0_499"
            }
            ICIMMCheckBoxEdit{
                id:s_rw_4_1_0_499
                configAddr: "s_rw_4_1_0_499"
            }
            ICIMMCheckBoxEdit{
                id:s_rw_5_1_0_499
                configAddr: "s_rw_5_1_0_499"
            }
            ICIMMCheckBoxEdit{
                id:s_rw_6_1_0_499
                configAddr: "s_rw_6_1_0_499"
            }

            ICIMMText{text: qsTr("D.Tem")}
            ICIMMText{}
            ICIMMLineEdit{
                id:s_rw_0_4_0_501
                configAddr: "s_rw_0_4_0_501"
                width: widthLabel.width
            }
            ICIMMLineEdit{
                id:s_rw_4_4_0_501
                configAddr: "s_rw_4_4_0_501"
                width: widthLabel.width
            }
            ICIMMLineEdit{
                id:s_rw_8_4_0_501
                configAddr: "s_rw_8_4_0_501"
                width: widthLabel.width
            }
            ICIMMLineEdit{
                id:s_rw_12_4_0_501
                configAddr: "s_rw_12_4_0_501"
                width: widthLabel.width
            }
            ICIMMLineEdit{
                id:s_rw_16_4_0_501
                configAddr: "s_rw_16_4_0_501"
                width: widthLabel.width
            }
            ICIMMLineEdit{
                id:s_rw_20_4_0_501
                configAddr: "s_rw_20_4_0_501"
                width: widthLabel.width
            }
            ICIMMLineEdit{
                id:s_rw_24_4_0_501
                configAddr: "s_rw_24_4_0_501"
                width: widthLabel.width
            }

            ICIMMText{text: qsTr("Output")}
            ICIMMText{}
            ICIMMLineEdit{
                id:s_rw_8_8_0_499
                configAddr: "s_rw_8_8_0_499"
                width: widthLabel.width

            }
            ICIMMLineEdit{
                id:s_rw_16_8_0_499
                configAddr: "s_rw_16_8_0_499"
                width: widthLabel.width
            }
            ICIMMLineEdit{
                id:s_rw_24_8_0_499
                configAddr: "s_rw_24_8_0_499"
                width: widthLabel.width
            }
            ICIMMLineEdit{
                id:s_rw_0_8_0_500
                configAddr: "s_rw_0_8_0_500"
                width: widthLabel.width
            }
            ICIMMLineEdit{
                id:s_rw_8_8_0_500
                configAddr: "s_rw_8_8_0_500"
                width: widthLabel.width
            }
            ICIMMLineEdit{
                id:s_rw_16_8_0_500
                configAddr: "s_rw_16_8_0_500"
                width: widthLabel.width
            }
            ICIMMLineEdit{
                id:s_rw_24_8_0_500
                configAddr: "s_rw_24_8_0_500"
                width: widthLabel.width
            }
        }
    }
}

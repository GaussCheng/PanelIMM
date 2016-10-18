import QtQuick 1.1
import "../../ICCustomElement"
import "../immcustomitems"
import "../../styles/style.js" as Style
ICSettingPageBase {
    ICIMMSettingConfigsScope{
        Grid{
            id:topRow
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


            ICIMMText{text: qsTr("P")}
            ICIMMText{}
            ICIMMLineEdit{
                id:s_rw_0_16_0_478
                configAddr: "s_rw_0_16_0_478"
                width: widthLabel.width
            }
            ICIMMLineEdit{
                id:s_rw_16_16_0_478
                configAddr: "s_rw_16_16_0_478"
                width: widthLabel.width
            }
            ICIMMLineEdit{
                id:s_rw_0_16_0_479
                configAddr: "s_rw_0_16_0_479"
                width: widthLabel.width
            }
            ICIMMLineEdit{
                id:s_rw_16_16_0_479
                configAddr: "s_rw_16_16_0_479"
                width: widthLabel.width
            }
            ICIMMLineEdit{
                id:s_rw_0_16_0_480
                configAddr: "s_rw_0_16_0_480"
                width: widthLabel.width
            }
            ICIMMLineEdit{
                id:s_rw_16_16_0_480
                configAddr: "s_rw_16_16_0_480"
                width: widthLabel.width
            }
            ICIMMLineEdit{
                id:s_rw_0_16_0_481
                configAddr: "s_rw_0_16_0_481"
                width: widthLabel.width
            }

            ICIMMText{text: qsTr("I")}
            ICIMMText{}
            ICIMMLineEdit{
                id:s_rw_0_16_0_482
                configAddr: "s_rw_0_16_0_482"
                width: widthLabel.width
            }
            ICIMMLineEdit{
                id:s_rw_16_16_0_482
                configAddr: "s_rw_16_16_0_482"
                width: widthLabel.width
            }
            ICIMMLineEdit{
                id:s_rw_0_16_0_483
                configAddr: "s_rw_0_16_0_483"
                width: widthLabel.width
            }
            ICIMMLineEdit{
                id:s_rw_16_16_0_483
                configAddr: "s_rw_16_16_0_483"
                width: widthLabel.width
            }
            ICIMMLineEdit{
                id:s_rw_0_16_0_484
                configAddr: "s_rw_0_16_0_484"
                width: widthLabel.width
            }
            ICIMMLineEdit{
                id:s_rw_16_16_0_484
                configAddr: "s_rw_16_16_0_484"
                width: widthLabel.width
            }
            ICIMMLineEdit{
                id:s_rw_0_16_0_485
                configAddr: "s_rw_0_16_0_485"
                width: widthLabel.width
            }

            ICIMMText{text: qsTr("D")}
            ICIMMText{}
            ICIMMLineEdit{
                id:s_rw_0_16_0_486
                configAddr: "s_rw_0_16_0_486"
                width: widthLabel.width
            }
            ICIMMLineEdit{
                id:s_rw_16_16_0_486
                configAddr: "s_rw_16_16_0_486"
                width: widthLabel.width
            }
            ICIMMLineEdit{
                id:s_rw_0_16_0_487
                configAddr: "s_rw_0_16_0_487"
                width: widthLabel.width
            }
            ICIMMLineEdit{
                id:s_rw_16_16_0_487
                configAddr: "s_rw_16_16_0_487"
                width: widthLabel.width
            }
            ICIMMLineEdit{
                id:s_rw_0_16_0_488
                configAddr: "s_rw_0_16_0_488"
                width: widthLabel.width
            }
            ICIMMLineEdit{
                id:s_rw_16_16_0_488
                configAddr: "s_rw_16_16_0_488"
                width: widthLabel.width
            }
            ICIMMLineEdit{
                id:s_rw_0_16_0_489
                configAddr: "s_rw_0_16_0_489"
                width: widthLabel.width
            }

            ICIMMText{id:widthLabel2;text: qsTr("A.T")}
            ICIMMText{}
            ICIMMCheckBoxEdit{
                id:s_rw_24_1_0_481
                configAddr: "s_rw_24_1_0_481"
            }
            ICIMMCheckBoxEdit{
                id:s_rw_25_1_0_481
                configAddr: "s_rw_25_1_0_481"
            }
            ICIMMCheckBoxEdit{
                id:s_rw_26_1_0_481
                configAddr: "s_rw_26_1_0_481"
            }
            ICIMMCheckBoxEdit{
                id:s_rw_27_1_0_481
                configAddr: "s_rw_27_1_0_481"
            }
            ICIMMCheckBoxEdit{
                id:s_rw_28_1_0_481
                configAddr: "s_rw_28_1_0_481"
            }
            ICIMMCheckBoxEdit{
                id:s_rw_29_1_0_481
                configAddr: "s_rw_29_1_0_481"
            }
            ICIMMCheckBoxEdit{
                id:s_rw_30_1_0_481
                configAddr: "s_rw_30_1_0_481"
            }

            ICIMMText{text: qsTr("H.SPE")}
            ICIMMText{text: qsTr("(%)")}
            ICIMMLineEdit{
                id:s_rw_0_16_0_490
                configAddr: "s_rw_0_16_0_490"
                width: widthLabel.width
            }
            ICIMMLineEdit{
                id:s_rw_16_16_0_490
                configAddr: "s_rw_16_16_0_490"
                width: widthLabel.width
            }
            ICIMMLineEdit{
                id:s_rw_0_16_0_491
                configAddr: "s_rw_0_16_0_491"
                width: widthLabel.width
            }
            ICIMMLineEdit{
                id:s_rw_16_16_0_491
                configAddr: "s_rw_16_16_0_491"
                width: widthLabel.width
            }
            ICIMMLineEdit{
                id:s_rw_0_16_0_492
                configAddr: "s_rw_0_16_0_492"
                width: widthLabel.width
            }
            ICIMMLineEdit{
                id:s_rw_16_16_0_492
                configAddr: "s_rw_16_16_0_492"
                width: widthLabel.width
            }
            ICIMMLineEdit{
                id:s_rw_0_16_0_493
                configAddr: "s_rw_0_16_0_493"
                width: widthLabel.width
            }

            ICIMMText{text: qsTr("H.SPE")}
            ICIMMText{text: qsTr("(%)")}
            ICIMMLineEdit{
                id:s_rw_0_16_0_494
                configAddr: "s_rw_0_16_0_494"
                width: widthLabel.width
            }
            ICIMMLineEdit{
                id:s_rw_16_16_0_494
                configAddr: "s_rw_16_16_0_494"
                width: widthLabel.width
            }
            ICIMMLineEdit{
                id:s_rw_0_16_0_495
                configAddr: "s_rw_0_16_0_495"
                width: widthLabel.width
            }
            ICIMMLineEdit{
                id:s_rw_16_16_0_495
                configAddr: "s_rw_16_16_0_495"
                width: widthLabel.width
            }
            ICIMMLineEdit{
                id:s_rw_0_16_0_496
                configAddr: "s_rw_0_16_0_496"
                width: widthLabel.width
            }
            ICIMMLineEdit{
                id:s_rw_16_16_0_496
                configAddr: "s_rw_16_16_0_496"
                width: widthLabel.width
            }
            ICIMMLineEdit{
                id:s_rw_0_16_0_497
                configAddr: "s_rw_0_16_0_497"
                width: widthLabel.width
            }
        }
    }
}

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
        return "ICCoreAidCVMonitorPage.qml";
    }
    //    function onF7Triggered(){
    //        return "ICTemperaturePIDCVMonitorPage.qml";
    //    }
    //    function onF8Triggered(){
    //        return "ICTemperatureBlowCVMonitorPage.qml";
    //    }
    ICSettingPageBase{
        id:page1
        width: parent.width
        height: parent.height
        onEditorFocusChanged: {
            instance.editorFocusChanged(now);
        }
        ICIMMSettingConfigsScope{
            ICIMMFrame{
                id:topRow
                width: page1.width
                height: page1.height
                Grid{
                    id:axisContainer
                    columns: 6
                    x:4
                    y:2
                    ICIMMText{}
                    ICIMMText{}
                    ICIMMText{text: qsTr("CLAMP")}
                    ICIMMText{text: qsTr("EJECT")}
                    ICIMMText{text: qsTr("CARRIGE")}
                    ICIMMText{text: qsTr("INJECT")}


                    ICIMMText{text: qsTr("CURRENT POS")}
                    ICIMMText{text: qsTr("(mm)")}
                    ICIMMStatusWidget{
                        id:c_ro_0_32_2_1541
                        bindStatus: "c_ro_0_32_2_1541"
                    }
                    ICIMMStatusWidget{
                        id:c_ro_0_32_2_1544
                        bindStatus: "c_ro_0_32_2_1544"
                    }
                    ICIMMStatusWidget{
                        id:c_ro_0_32_2_1543
                        bindStatus: "c_ro_0_32_2_1543"
                    }
                    ICIMMStatusWidget{
                        id:c_ro_0_32_2_1542
                        bindStatus: "c_ro_0_32_2_1542"
                    }

                    ICIMMText{text: qsTr("POSISON LEN")}
                    ICIMMText{text: qsTr("(mm)")}
                    ICIMMLineEdit{
                        id:s_rw_0_16_1_552
                        configAddr: "s_rw_0_16_1_552"
                    }
                    ICIMMLineEdit{
                        id:s_rw_16_16_1_553
                        configAddr: "s_rw_16_16_1_553"
                    }
                    ICIMMLineEdit{
                        id:s_rw_0_16_1_553
                        configAddr: "s_rw_0_16_1_553"
                    }
                    ICIMMLineEdit{
                        id:s_rw_16_16_1_552
                        configAddr: "s_rw_16_16_1_552"
                    }

                    ICIMMText{text: qsTr("CYLIDER STR.")}
                    ICIMMText{text: qsTr("(mm)")}
                    ICIMMLineEdit{
                        id:s_rw_0_16_1_554
                        configAddr: "s_rw_0_16_1_554"
                    }
                    ICIMMLineEdit{
                        id:s_rw_16_16_1_555
                        configAddr: "s_rw_16_16_1_555"
                    }
                    ICIMMLineEdit{
                        id:s_rw_0_16_1_555
                        configAddr: "s_rw_0_16_1_555"
                    }
                    ICIMMLineEdit{
                        id:s_rw_16_16_1_554
                        configAddr: "s_rw_16_16_1_554"
                    }

                    ICIMMText{text: qsTr("MAX A/D")}
                    ICIMMText{}
                    ICIMMLineEdit{
                        id:s_rw_0_16_0_556
                        configAddr: "s_rw_0_16_0_556"
                    }
                    ICIMMLineEdit{
                        id:s_rw_16_16_0_557
                        configAddr: "s_rw_16_16_0_557"
                    }
                    ICIMMLineEdit{
                        id:s_rw_0_16_0_557
                        configAddr: "s_rw_0_16_0_557"
                    }
                    ICIMMLineEdit{
                        id:s_rw_16_16_0_556
                        configAddr: "s_rw_16_16_0_556"
                    }

                    ICIMMText{text: qsTr("MIN A/D")}
                    ICIMMText{}
                    ICIMMLineEdit{
                        id:s_rw_0_16_0_558
                        configAddr: "s_rw_0_16_0_558"
                    }
                    ICIMMLineEdit{
                        id:s_rw_16_16_0_559
                        configAddr: "s_rw_16_16_0_559"
                    }
                    ICIMMLineEdit{
                        id:s_rw_0_16_0_559
                        configAddr: "s_rw_0_16_0_559"
                    }
                    ICIMMLineEdit{
                        id:s_rw_16_16_0_558
                        configAddr: "s_rw_16_16_0_558"
                    }

                    ICIMMText{text: qsTr("CURRENT A/D")}
                    ICIMMText{}
                    ICIMMStatusWidget{
                        id:c_ro_0_16_0_1545
                        bindStatus: "c_ro_0_16_0_1545"
                    }
                    ICIMMStatusWidget{
                        id:c_ro_16_16_0_1546
                        bindStatus: "c_ro_16_16_0_1546"
                    }
                    ICIMMStatusWidget{
                        id:c_ro_0_16_0_1546
                        bindStatus: "c_ro_0_16_0_1546"
                    }
                    ICIMMStatusWidget{
                        id:c_ro_16_16_0_1545
                        bindStatus: "c_ro_16_16_0_1545"
                    }

                    ICIMMText{text: qsTr("Oil Cylider Adjust")}
                    ICIMMText{}
                    ICIMMButton{
                        id:dmMax
                        text: qsTr("max")
                    }
                    ICIMMButton{
                        id:ejeMax
                        text: qsTr("max")
                    }
                    ICIMMButton{
                        id:carrMax
                        text: qsTr("max")
                    }
                    ICIMMButton{
                        id:injMax
                        text: qsTr("max")
                    }

                    ICIMMText{text: qsTr("Zero Adjust")}
                    ICIMMText{}
                    ICIMMButton{
                        id:dmZero
                        text: qsTr("zero")
                    }
                    ICIMMButton{
                        id:ejeZero
                        text: qsTr("zero")
                    }
                    ICIMMButton{
                        id:carrZero
                        text: qsTr("zero")
                    }
                    ICIMMButton{
                        id:injZero
                        text: qsTr("zero")
                    }

                    ICIMMText{text: qsTr("A/D Channel")}
                    ICIMMText{}
                    ICIMMLineEdit{
                        id:s_rw_4_3_0_560
                        configAddr: "s_rw_4_3_0_560"
                    }
                    ICIMMLineEdit{
                        id:s_rw_13_3_0_560
                        configAddr: "s_rw_13_3_0_560"
                    }
                    ICIMMLineEdit{
                        id:s_rw_10_3_0_560
                        configAddr: "s_rw_10_3_0_560"
                    }
                    ICIMMLineEdit{
                        id:s_rw_7_3_0_560
                        configAddr: "s_rw_7_3_0_560"
                    }

                }
                ICVerSplitLine{
                    id:verSplitLine1
                    height: parent.height
                    anchors.left: axisContainer.right
                    anchors.leftMargin: 4
                }
                Column{
                    id:motorContainer
                    anchors.left: verSplitLine1.right
                    anchors.leftMargin: verSplitLine1.anchors.leftMargin
                    y:axisContainer.y
                    ICIMMLabelComboBoxEdit{
                        id:s_rw_4_4_0_459
                        configAddr: "s_rw_4_4_0_459"
                        configName: qsTr("Motor Co")
                        items: [qsTr("None"), qsTr("JinYi"), qsTr("SiFang"), qsTr("XingChen-1"), qsTr("XingChen-2"), qsTr("yikemix")]
                        z:10
                        configNameWidth: s_rw_0_16_2_457.configNameWidth
                    }
                    ICIMMLabelComboBoxEdit{
                        id:s_rw_0_4_0_459
                        configAddr: "s_rw_0_4_0_459"
                        configName: qsTr("Motor Type")
                        items: [qsTr("No-Oil"), qsTr("Uart5"), qsTr("Analog Channel"), qsTr("Rev"), qsTr("CAN")]
                        z:9
                        configNameWidth: s_rw_0_16_2_457.configNameWidth
                    }
                    ICIMMLabelLineEdit{
                        id:s_rw_0_16_2_457
                        configAddr: "s_rw_0_16_2_457"
                        configName: qsTr("Motor Boot Protect")
                        unit: qsTr("s")
                    }
                    ICIMMLabelLineEdit{
                        id:s_rw_16_16_2_457
                        configAddr: "s_rw_16_16_2_457"
                        configName: qsTr("Motor OV-LOAD")
                        unit: qsTr("s")
                        configNameWidth: s_rw_0_16_2_457.configNameWidth

                    }
                    ICIMMLabelLineEdit{
                        id:s_rw_0_16_2_458
                        configAddr: "s_rw_0_16_2_458"
                        configName: qsTr("Motor Boot Delay")
                        unit: qsTr("s")
                        configNameWidth: s_rw_0_16_2_457.configNameWidth

                    }
                    ICIMMLabelLineEdit{
                        id:s_rw_16_16_2_458
                        configAddr: "s_rw_16_16_2_458"
                        configName: qsTr("Tri Toggle Time")
                        unit: qsTr("s")
                        configNameWidth: s_rw_0_16_2_457.configNameWidth
                    }
                    ICIMMCheckBoxEdit{
                        id:s_rw_8_1_0_459
                        configAddr: "s_rw_8_1_0_459"
                        configName: qsTr("Tri En")
                    }
                }
            }
        }
    }
}

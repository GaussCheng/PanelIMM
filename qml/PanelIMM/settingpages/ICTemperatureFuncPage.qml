import QtQuick 1.1
import "../../ICCustomElement"
import "../immcustomitems"
import "../../styles/style.js" as Style
ICIMMFunctionPageBase {
    id:instance
    property variant detailsMenuItems: {
        "f6":qsTr("Aid Settings"),
        "f7":qsTr("PID"),
        "f8":qsTr("Blow"),
    }
    function onF6Triggered(){
        return "ICTemperatureAidCVMonitorPage.qml";
    }
    function onF7Triggered(){
        return "ICTemperaturePIDCVMonitorPage.qml";
    }
    function onF8Triggered(){
        return "ICTemperatureBlowCVMonitorPage.qml";
    }
    ICSettingPageBase{
        id:tempPage1
        width: parent.width
        height: parent.height
        onEditorFocusChanged: {
            instance.editorFocusChanged(now);
        }
        ICIMMSettingConfigsScope{
            ICIMMFrame{
                id:topRow
                width: tempPage1.width
                height: tempPage1.height * 0.4
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

                    ICIMMText{text: qsTr("HEATING")}
                    ICIMMText{text: qsTr("(°C)")}
                    ICIMMLineEdit{
                        id:m_rw_0_16_0_462
                        configAddr: "m_rw_0_16_0_462"
                    }
                    ICIMMLineEdit{
                        id:m_rw_16_16_0_462
                        configAddr: "m_rw_16_16_0_462"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_16_0_463
                        configAddr: "m_rw_0_16_0_463"
                    }
                    ICIMMLineEdit{
                        id:m_rw_16_16_0_463
                        configAddr: "m_rw_16_16_0_463"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_16_0_464
                        configAddr: "m_rw_0_16_0_464"
                    }
                    ICIMMLineEdit{
                        id:m_rw_16_16_0_464
                        configAddr: "m_rw_16_16_0_464"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_16_0_465
                        configAddr: "m_rw_0_16_0_465"
                    }
                    ICIMMLineEdit{
                        id:m_rw_16_16_0_465
                        configAddr: "m_rw_16_16_0_465"
                    }

                    ICIMMText{text: qsTr("PREHEAT")}
                    ICIMMText{text: qsTr("(°C)")}
                    ICIMMLineEdit{
                        id:m_rw_0_16_0_466
                        configAddr: "m_rw_0_16_0_466"
                    }
                    ICIMMLineEdit{
                        id:m_rw_16_16_0_466
                        configAddr: "m_rw_16_16_0_466"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_16_0_467
                        configAddr: "m_rw_0_16_0_467"
                    }
                    ICIMMLineEdit{
                        id:m_rw_16_16_0_467
                        configAddr: "m_rw_16_16_0_467"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_16_0_468
                        configAddr: "m_rw_0_16_0_468"
                    }
                    ICIMMLineEdit{
                        id:m_rw_16_16_0_468
                        configAddr: "m_rw_16_16_0_468"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_16_0_469
                        configAddr: "m_rw_0_16_0_469"
                    }
                    ICIMMText{}

                    ICIMMText{text: qsTr("Up Offset")}
                    ICIMMText{text: qsTr("(°C)")}
                    ICIMMLineEdit{
                        id:m_rw_0_16_0_470
                        configAddr: "m_rw_0_16_0_470"
                    }
                    ICIMMLineEdit{
                        id:m_rw_16_16_0_470
                        configAddr: "m_rw_16_16_0_470"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_16_0_471
                        configAddr: "m_rw_0_16_0_471"
                    }
                    ICIMMLineEdit{
                        id:m_rw_16_16_0_471
                        configAddr: "m_rw_16_16_0_471"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_16_0_472
                        configAddr: "m_rw_0_16_0_472"
                    }
                    ICIMMLineEdit{
                        id:m_rw_16_16_0_472
                        configAddr: "m_rw_16_16_0_472"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_16_0_473
                        configAddr: "m_rw_0_16_0_473"
                    }
                    ICIMMLineEdit{
                        id:m_rw_16_16_0_473
                        configAddr: "m_rw_16_16_0_473"
                    }

                    ICIMMText{text: qsTr("Up Offset")}
                    ICIMMText{text: qsTr("(°C)")}
                    ICIMMLineEdit{
                        id:m_rw_0_16_0_474
                        configAddr: "m_rw_0_16_0_474"
                    }
                    ICIMMLineEdit{
                        id:m_rw_16_16_0_474
                        configAddr: "m_rw_16_16_0_474"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_16_0_475
                        configAddr: "m_rw_0_16_0_475"
                    }
                    ICIMMLineEdit{
                        id:m_rw_16_16_0_475
                        configAddr: "m_rw_16_16_0_475"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_16_0_476
                        configAddr: "m_rw_0_16_0_476"
                    }
                    ICIMMLineEdit{
                        id:m_rw_16_16_0_476
                        configAddr: "m_rw_16_16_0_476"
                    }
                    ICIMMLineEdit{
                        id:m_rw_0_16_0_477
                        configAddr: "m_rw_0_16_0_477"
                    }
                    ICIMMText{}
                }

            }
            ICIMMFrame{
                id:middleRow
                width: tempPage1.width
                height: tempPage1.height * 0.2
                anchors.top: topRow.bottom
                Grid{
                    x:4
                    y:2
                    columns: 7
                    ICIMMText{text: qsTr("HEAT_MODE")}
                    ICIMMLabelComboBoxEdit{
                        id:m_rw_24_4_0_498
                        configAddr: "m_rw_24_4_0_498"
                        items: [qsTr("NO HEAT"), qsTr("HEAT"), qsTr("PREHEAT"), qsTr("AUTO HEAT"), qsTr("AUTO PREHEAT")]
                    }
                    ICIMMText{width: 10}
                    ICIMMText{text: qsTr("NOZZ CYC TM")}
                    ICIMMLineEdit{
                        id:m_rw_0_10_1_498
                        configAddr: "m_rw_0_10_1_498"
                        unit: qsTr("s")
                    }
                    ICIMMText{width: 10}
                    ICIMMCheckBoxEdit{
                        id:m_rw_28_1_0_498
                        configAddr: "m_rw_28_1_0_498"
                        configName: qsTr("Alm.S.HT")
                    }

                    ICIMMCheckBoxEdit{
                        id:m_rw_30_1_0_498
                        configAddr: "m_rw_30_1_0_498"
                        configName: qsTr("Screw.P")
                    }
                    ICIMMLineEdit{
                        id:m_rw_17_7_0_498
                        configAddr: "m_rw_17_7_0_498"
                        width: m_rw_24_4_0_498.width
                        unit: qsTr("s")
                    }
                    ICIMMText{width: 10}
                    ICIMMText{text: qsTr("NOZZ DUTY %")}
                    ICIMMLineEdit{
                        id:m_rw_10_7_0_498
                        configAddr: "m_rw_10_7_0_498"
                        unit: qsTr("%")
                    }
                    ICIMMText{width: 10}
                    ICIMMCheckBoxEdit{
                        id:m_rw_29_1_0_498
                        configAddr: "m_rw_29_1_0_498"
                        configName: qsTr("Alm.S.HD")
                    }
                }
            }
            ICIMMFrame{
                id:bottomRow
                width: tempPage1.width
                height: tempPage1.height - topRow.height - middleRow.height
                anchors.top: middleRow.bottom
                anchors.topMargin: -1
                Grid{
                    x:4
                    y:2
                    columns: 8
                    ICIMMText{}
                    ICIMMCheckBoxEdit{
                        id:m_rw_0_1_0_1436
                        configAddr: "m_rw_0_1_0_1436"
                        configName: qsTr("Sun")
                    }
                    ICIMMCheckBoxEdit{
                        id:m_rw_0_1_0_1437
                        configAddr: "m_rw_0_1_0_1437"
                        configName: qsTr("Mon")
                    }
                    ICIMMCheckBoxEdit{
                        id:m_rw_0_1_0_1438
                        configAddr: "m_rw_0_1_0_1438"
                        configName: qsTr("Tur")
                    }
                    ICIMMCheckBoxEdit{
                        id:m_rw_0_1_0_1439
                        configAddr: "m_rw_0_1_0_1439"
                        configName: qsTr("Web")
                    }
                    ICIMMCheckBoxEdit{
                        id:m_rw_0_1_0_1440
                        configAddr: "m_rw_0_1_0_1440"
                        configName: qsTr("Thu")
                    }
                    ICIMMCheckBoxEdit{
                        id:m_rw_0_1_0_1441
                        configAddr: "m_rw_0_1_0_1441"
                        configName: qsTr("Fri")
                    }
                    ICIMMCheckBoxEdit{
                        id:m_rw_0_1_0_1442
                        configAddr: "m_rw_0_1_0_1442"
                        configName: qsTr("Sat")
                    }

                    ICIMMText{text:qsTr("HT.Time")}
                    ICIMMTimeLineEdit{
                        id:m_rw_1_15_0_1436
                        configAddr: "m_rw_1_15_0_1436"
                    }
                    ICIMMTimeLineEdit{
                        id:m_rw_1_15_0_1437
                        configAddr: "m_rw_1_15_0_1437"
                    }
                    ICIMMTimeLineEdit{
                        id:m_rw_1_15_0_1438
                        configAddr: "m_rw_1_15_0_1438"
                    }
                    ICIMMTimeLineEdit{
                        id:m_rw_1_15_0_1439
                        configAddr: "m_rw_1_15_0_1439"
                    }
                    ICIMMTimeLineEdit{
                        id:m_rw_1_15_0_1440
                        configAddr: "m_rw_1_15_0_1440"
                    }
                    ICIMMTimeLineEdit{
                        id:m_rw_1_15_0_1441
                        configAddr: "m_rw_1_15_0_1441"
                    }
                    ICIMMTimeLineEdit{
                        id:m_rw_1_15_0_1442
                        configAddr: "m_rw_1_15_0_1442"
                    }

                    ICIMMText{text:qsTr("HD.Time")}
                    ICIMMTimeLineEdit{
                        id:m_rw_16_15_0_1436
                        configAddr: "m_rw_16_15_0_1436"
                    }
                    ICIMMTimeLineEdit{
                        id:m_rw_16_15_0_1437
                        configAddr: "m_rw_16_15_0_1437"
                    }
                    ICIMMTimeLineEdit{
                        id:m_rw_16_15_0_1438
                        configAddr: "m_rw_16_15_0_1438"
                    }
                    ICIMMTimeLineEdit{
                        id:m_rw_16_15_0_1439
                        configAddr: "m_rw_16_15_0_1439"
                    }
                    ICIMMTimeLineEdit{
                        id:m_rw_16_15_0_1440
                        configAddr: "m_rw_16_15_0_1440"
                    }
                    ICIMMTimeLineEdit{
                        id:m_rw_16_15_0_1441
                        configAddr: "m_rw_16_15_0_1441"
                    }
                    ICIMMTimeLineEdit{
                        id:m_rw_16_15_0_1442
                        configAddr: "m_rw_16_15_0_1442"
                    }
                }
            }
        }
    }
}

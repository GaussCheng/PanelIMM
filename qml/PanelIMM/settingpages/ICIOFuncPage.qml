import QtQuick 1.1
import "../../ICCustomElement"
import "../immcustomitems"
import "../../styles/style.js" as Style
ICIMMFunctionPageBase {
    id:instance
    property variant detailsMenuItems: {
        'f1':qsTr("I/O Define"),
                'f2':qsTr("Aid Output"),
                'f3':qsTr("Input Sim"),
                'f4':qsTr("Output Sim")
    }
    function onF1Triggered(){
        //        return "ICBlowCVMonitorPage.qml";
        setCurrentIndex(0);
        return ""
    }
    function onF2Triggered(){
        setCurrentIndex(1);
        return ""
    }
    ICSettingPageBase{
        id:ioDefinePage
        width: parent.width
        height: parent.height
        onEditorFocusChanged: {
            instance.editorFocusChanged(now);
        }
        ICIMMSettingConfigsScope{
            width: ioDefinePage.width
            height: ioDefinePage.height
            Grid{
                id:inputDefineContainer
                x:4
                y:2
                columns: 8
                ICIMMText{text:qsTr("I")}
                ICIMMText{text: qsTr("Map")}
                ICIMMText{text:qsTr("I")}
                ICIMMText{text: qsTr("Map")}
                ICIMMText{text:qsTr("I")}
                ICIMMText{text: qsTr("Map")}
                ICIMMText{text:qsTr("I")}
                ICIMMText{text: qsTr("Map")}

                ICIMMText{text: "X00"}
                ICIMMLineEdit{
                    id:s_rw_0_8_0_681
                    configAddr: "s_rw_0_8_0_681"
                }
                ICIMMText{text: "X10"}
                ICIMMLineEdit{
                    id:s_rw_0_8_0_683
                    configAddr: "s_rw_0_8_0_683"
                }
                ICIMMText{text: "X20"}
                ICIMMLineEdit{
                    id:s_rw_0_8_0_685
                    configAddr: "s_rw_0_8_0_685"
                }
                ICIMMText{text: "X30"}
                ICIMMLineEdit{
                    id:s_rw_0_8_0_687
                    configAddr: "s_rw_0_8_0_687"
                }

                ICIMMText{text: "X01"}
                ICIMMLineEdit{
                    id:s_rw_8_8_0_681
                    configAddr: "s_rw_8_8_0_681"
                }
                ICIMMText{text: "X11"}
                ICIMMLineEdit{
                    id:s_rw_8_8_0_683
                    configAddr: "s_rw_8_8_0_683"
                }
                ICIMMText{text: "X21"}
                ICIMMLineEdit{
                    id:s_rw_8_8_0_685
                    configAddr: "s_rw_8_8_0_685"
                }
                ICIMMText{text: "X31"}
                ICIMMLineEdit{
                    id:s_rw_8_8_0_687
                    configAddr: "s_rw_8_8_0_687"
                }

                ICIMMText{text: "X02"}
                ICIMMLineEdit{
                    id:s_rw_16_8_0_681
                    configAddr: "s_rw_16_8_0_681"
                }
                ICIMMText{text: "X12"}
                ICIMMLineEdit{
                    id:s_rw_16_8_0_683
                    configAddr: "s_rw_16_8_0_683"
                }
                ICIMMText{text: "X22"}
                ICIMMLineEdit{
                    id:s_rw_16_8_0_685
                    configAddr: "s_rw_16_8_0_685"
                }
                ICIMMText{text: "X32"}
                ICIMMLineEdit{
                    id:s_rw_16_8_0_687
                    configAddr: "s_rw_16_8_0_687"
                }

                ICIMMText{text: "X03"}
                ICIMMLineEdit{
                    id:s_rw_24_8_0_681
                    configAddr: "s_rw_24_8_0_681"
                }
                ICIMMText{text: "X13"}
                ICIMMLineEdit{
                    id:s_rw_24_8_0_683
                    configAddr: "s_rw_24_8_0_683"
                }
                ICIMMText{text: "X23"}
                ICIMMLineEdit{
                    id:s_rw_24_8_0_685
                    configAddr: "s_rw_24_8_0_685"
                }
                ICIMMText{text: "X33"}
                ICIMMLineEdit{
                    id:s_rw_24_8_0_687
                    configAddr: "s_rw_24_8_0_687"
                }

                ICIMMText{text: "X04"}
                ICIMMLineEdit{
                    id:s_rw_0_8_0_682
                    configAddr: "s_rw_0_8_0_682"
                }
                ICIMMText{text: "X14"}
                ICIMMLineEdit{
                    id:s_rw_0_8_0_684
                    configAddr: "s_rw_0_8_0_684"
                }
                ICIMMText{text: "X24"}
                ICIMMLineEdit{
                    id:s_rw_0_8_0_686
                    configAddr: "s_rw_0_8_0_686"
                }
                ICIMMText{text: "X34"}
                ICIMMLineEdit{
                    id:s_rw_0_8_0_688
                    configAddr: "s_rw_0_8_0_688"
                }

                ICIMMText{text: "X05"}
                ICIMMLineEdit{
                    id:s_rw_8_8_0_682
                    configAddr: "s_rw_8_8_0_682"
                }
                ICIMMText{text: "X15"}
                ICIMMLineEdit{
                    id:s_rw_8_8_0_684
                    configAddr: "s_rw_8_8_0_684"
                }
                ICIMMText{text: "X25"}
                ICIMMLineEdit{
                    id:s_rw_8_8_0_686
                    configAddr: "s_rw_8_8_0_686"
                }
                ICIMMText{text: "X35"}
                ICIMMLineEdit{
                    id:s_rw_8_8_0_688
                    configAddr: "s_rw_8_8_0_688"
                }

                ICIMMText{text: "X06"}
                ICIMMLineEdit{
                    id:s_rw_16_8_0_682
                    configAddr: "s_rw_16_8_0_682"
                }
                ICIMMText{text: "X16"}
                ICIMMLineEdit{
                    id:s_rw_16_8_0_684
                    configAddr: "s_rw_16_8_0_684"
                }
                ICIMMText{text: "X26"}
                ICIMMLineEdit{
                    id:s_rw_16_8_0_686
                    configAddr: "s_rw_16_8_0_686"
                }
                ICIMMText{text: "X36"}
                ICIMMLineEdit{
                    id:s_rw_16_8_0_688
                    configAddr: "s_rw_16_8_0_688"
                }

                ICIMMText{text: "X07"}
                ICIMMLineEdit{
                    id:s_rw_24_8_0_682
                    configAddr: "s_rw_24_8_0_682"
                }
                ICIMMText{text: "X17"}
                ICIMMLineEdit{
                    id:s_rw_24_8_0_684
                    configAddr: "s_rw_24_8_0_684"
                }
                ICIMMText{text: "X27"}
                ICIMMLineEdit{
                    id:s_rw_24_8_0_686
                    configAddr: "s_rw_24_8_0_686"
                }
                ICIMMText{text: "X37"}
                ICIMMLineEdit{
                    id:s_rw_24_8_0_688
                    configAddr: "s_rw_24_8_0_688"
                }
            }
            ICVerSplitLine{
                id:verSplitLine1
                anchors.left: inputDefineContainer.right
                anchors.leftMargin: 4
                height:ioDefinePage.height
            }
            Grid{
                id:outputDefineContainer
                y:inputDefineContainer.y
                anchors.left: verSplitLine1.right
                anchors.leftMargin: verSplitLine1.anchors.leftMargin

                columns: 10
                ICIMMText{text:qsTr("O")}
                ICIMMText{text: qsTr("Map")}
                ICIMMText{text:qsTr("O")}
                ICIMMText{text: qsTr("Map")}
                ICIMMText{text:qsTr("O")}
                ICIMMText{text: qsTr("Map")}
                ICIMMText{text:qsTr("O")}
                ICIMMText{text: qsTr("Map")}
                ICIMMText{text:qsTr("O")}
                ICIMMText{text: qsTr("Map")}

                ICIMMText{text: "Y00"}
                ICIMMLineEdit{
                    id:s_rw_0_8_0_689
                    configAddr: "s_rw_0_8_0_689"
                }
                ICIMMText{text: "Y10"}
                ICIMMLineEdit{
                    id:s_rw_0_8_0_691
                    configAddr: "s_rw_0_8_0_691"
                }
                ICIMMText{text: "Y20"}
                ICIMMLineEdit{
                    id:s_rw_0_8_0_693
                    configAddr: "s_rw_0_8_0_693"
                }
                ICIMMText{text: "Y30"}
                ICIMMLineEdit{
                    id:s_rw_0_8_0_695
                    configAddr: "s_rw_0_8_0_695"
                }
                ICIMMText{text: "Y40"}
                ICIMMLineEdit{
                    id:s_rw_0_8_0_697
                    configAddr: "s_rw_0_8_0_697"
                }

                ICIMMText{text: "Y01"}
                ICIMMLineEdit{
                    id:s_rw_8_8_0_689
                    configAddr: "s_rw_8_8_0_689"
                }
                ICIMMText{text: "Y11"}
                ICIMMLineEdit{
                    id:s_rw_8_8_0_691
                    configAddr: "s_rw_8_8_0_691"
                }
                ICIMMText{text: "Y21"}
                ICIMMLineEdit{
                    id:s_rw_8_8_0_693
                    configAddr: "s_rw_8_8_0_693"
                }
                ICIMMText{text: "Y31"}
                ICIMMLineEdit{
                    id:s_rw_8_8_0_695
                    configAddr: "s_rw_8_8_0_695"
                }
                ICIMMText{text: "Y41"}
                ICIMMLineEdit{
                    id:s_rw_8_8_0_697
                    configAddr: "s_rw_8_8_0_697"
                }

                ICIMMText{text: "Y02"}
                ICIMMLineEdit{
                    id:s_rw_16_8_0_689
                    configAddr: "s_rw_16_8_0_689"
                }
                ICIMMText{text: "Y12"}
                ICIMMLineEdit{
                    id:s_rw_16_8_0_691
                    configAddr: "s_rw_16_8_0_691"
                }
                ICIMMText{text: "Y22"}
                ICIMMLineEdit{
                    id:s_rw_16_8_0_693
                    configAddr: "s_rw_16_8_0_693"
                }
                ICIMMText{text: "Y32"}
                ICIMMLineEdit{
                    id:s_rw_16_8_0_695
                    configAddr: "s_rw_16_8_0_695"
                }
                ICIMMText{text: "Y42"}
                ICIMMLineEdit{
                    id:s_rw_16_8_0_697
                    configAddr: "s_rw_16_8_0_697"
                }

                ICIMMText{text: "Y03"}
                ICIMMLineEdit{
                    id:s_rw_24_8_0_689
                    configAddr: "s_rw_24_8_0_689"
                }
                ICIMMText{text: "Y13"}
                ICIMMLineEdit{
                    id:s_rw_24_8_0_691
                    configAddr: "s_rw_24_8_0_691"
                }
                ICIMMText{text: "Y23"}
                ICIMMLineEdit{
                    id:s_rw_24_8_0_693
                    configAddr: "s_rw_24_8_0_693"
                }
                ICIMMText{text: "Y33"}
                ICIMMLineEdit{
                    id:s_rw_24_8_0_695
                    configAddr: "s_rw_24_8_0_695"
                }
                ICIMMText{text: "Y43"}
                ICIMMLineEdit{
                    id:s_rw_24_8_0_697
                    configAddr: "s_rw_24_8_0_697"
                }

                ICIMMText{text: "Y04"}
                ICIMMLineEdit{
                    id:s_rw_0_8_0_690
                    configAddr: "s_rw_0_8_0_690"
                }
                ICIMMText{text: "Y14"}
                ICIMMLineEdit{
                    id:s_rw_0_8_0_692
                    configAddr: "s_rw_0_8_0_692"
                }
                ICIMMText{text: "Y24"}
                ICIMMLineEdit{
                    id:s_rw_0_8_0_694
                    configAddr: "s_rw_0_8_0_694"
                }
                ICIMMText{text: "Y34"}
                ICIMMLineEdit{
                    id:s_rw_0_8_0_696
                    configAddr: "s_rw_0_8_0_696"
                }
                ICIMMText{text: "Y44"}
                ICIMMLineEdit{
                    id:s_rw_0_8_0_698
                    configAddr: "s_rw_0_8_0_698"
                }

                ICIMMText{text: "Y05"}
                ICIMMLineEdit{
                    id:s_rw_8_8_0_690
                    configAddr: "s_rw_8_8_0_690"
                }
                ICIMMText{text: "Y15"}
                ICIMMLineEdit{
                    id:s_rw_8_8_0_692
                    configAddr: "s_rw_8_8_0_692"
                }
                ICIMMText{text: "Y25"}
                ICIMMLineEdit{
                    id:s_rw_8_8_0_694
                    configAddr: "s_rw_8_8_0_694"
                }
                ICIMMText{text: "Y35"}
                ICIMMLineEdit{
                    id:s_rw_8_8_0_696
                    configAddr: "s_rw_8_8_0_696"
                }
                ICIMMText{text: "Y45"}
                ICIMMLineEdit{
                    id:s_rw_8_8_0_698
                    configAddr: "s_rw_8_8_0_698"
                }

                ICIMMText{text: "Y06"}
                ICIMMLineEdit{
                    id:s_rw_16_8_0_690
                    configAddr: "s_rw_16_8_0_690"
                }
                ICIMMText{text: "Y16"}
                ICIMMLineEdit{
                    id:s_rw_16_8_0_692
                    configAddr: "s_rw_16_8_0_692"
                }
                ICIMMText{text: "Y26"}
                ICIMMLineEdit{
                    id:s_rw_16_8_0_694
                    configAddr: "s_rw_16_8_0_694"
                }
                ICIMMText{text: "Y36"}
                ICIMMLineEdit{
                    id:s_rw_16_8_0_696
                    configAddr: "s_rw_16_8_0_696"
                }
                ICIMMText{text: "Y46"}
                ICIMMLineEdit{
                    id:s_rw_16_8_0_698
                    configAddr: "s_rw_16_8_0_698"
                }

                ICIMMText{text: "Y07"}
                ICIMMLineEdit{
                    id:s_rw_24_8_0_690
                    configAddr: "s_rw_24_8_0_690"
                }
                ICIMMText{text: "Y17"}
                ICIMMLineEdit{
                    id:s_rw_24_8_0_692
                    configAddr: "s_rw_24_8_0_692"
                }
                ICIMMText{text: "Y27"}
                ICIMMLineEdit{
                    id:s_rw_24_8_0_694
                    configAddr: "s_rw_24_8_0_694"
                }
                ICIMMText{text: "Y37"}
                ICIMMLineEdit{
                    id:s_rw_24_8_0_696
                    configAddr: "s_rw_24_8_0_696"
                }
                ICIMMText{text: "Y47"}
                ICIMMLineEdit{
                    id:s_rw_24_8_0_698
                    configAddr: "s_rw_24_8_0_698"
                }
            }
        }

    }
    ICSettingPageBase{
        id:aidOutputPage
        width: parent.width
        height: parent.height
        onEditorFocusChanged: {
            instance.editorFocusChanged(now);
        }
        ICIMMSettingConfigsScope{
            width: parent.width
            height: parent.height
            Grid{
                x:4
                y:2
                columns: 11
                ICIMMText{text:qsTr("En")}
                ICIMMText{text:qsTr("Mode")}
                ICIMMText{text:qsTr("Output")}
                ICIMMText{text:qsTr("Action")}
                ICIMMText{text:qsTr("Seg")}
                ICIMMText{}
                ICIMMText{text:qsTr("En")}
                ICIMMText{text:qsTr("Mode")}
                ICIMMText{text:qsTr("Output")}
                ICIMMText{text:qsTr("Action")}
                ICIMMText{text:qsTr("Seg")}

                ICIMMCheckBoxEdit{
                    id:s_rw_29_1_0_630
                    configAddr: "s_rw_29_1_0_630"
                }
                ICIMMLabelComboBoxEdit{
                    id:s_rw_30_2_0_630
                    configAddr: "s_rw_30_2_0_630"
                    items: [qsTr("Manual"), qsTr("Auto"), qsTr("Both")]
                    z:2

                }
                ICIMMLabelComboBoxEdit{
                    id:s_rw_20_9_0_630
                    configAddr: "s_rw_20_9_0_630"
                    items: ["Y01", "Y14","Y15","Y16","Y17","Y20", "Y21", "Y22", "Y23", "Y24","Y25","Y26","Y27", "Y34","Y40","Y41","Y42","Y43","Y44","Y45","Y46","Y47"]
                }
                ICIMMLineEdit{
                    id:s_rw_10_10_0_630
                    configAddr: "s_rw_10_10_0_630"
                }
                ICIMMLineEdit{
                    id:s_rw_0_10_0_630
                    configAddr: "s_rw_0_10_0_630"
                }
                ICIMMText{width: 10}
                ICIMMCheckBoxEdit{
                    id:s_rw_29_1_0_631
                    configAddr: "s_rw_29_1_0_631"
                }
                ICIMMLabelComboBoxEdit{
                    id:s_rw_30_2_0_631
                    configAddr: "s_rw_30_2_0_631"
                    items: s_rw_30_2_0_630.items
                }
                ICIMMLabelComboBoxEdit{
                    id:s_rw_20_9_0_631
                    configAddr: "s_rw_20_9_0_631"
                    items: s_rw_20_9_0_630.items
                }
                ICIMMLineEdit{
                    id:s_rw_10_10_0_631
                    configAddr: "s_rw_10_10_0_631"
                }
                ICIMMLineEdit{
                    id:s_rw_0_10_0_631
                    configAddr: "s_rw_0_10_0_631"
                }

                ICIMMCheckBoxEdit{
                    id:s_rw_29_1_0_632
                    configAddr: "s_rw_29_1_0_632"
                }
                ICIMMLabelComboBoxEdit{
                    id:s_rw_30_2_0_632
                    configAddr: "s_rw_30_2_0_632"
                    items:s_rw_30_2_0_630.items
                }
                ICIMMLabelComboBoxEdit{
                    id:s_rw_20_9_0_632
                    configAddr: "s_rw_20_9_0_632"
                    items: s_rw_20_9_0_630.items
                }
                ICIMMLineEdit{
                    id:s_rw_10_10_0_632
                    configAddr: "s_rw_10_10_0_632"
                }
                ICIMMLineEdit{
                    id:s_rw_0_10_0_632
                    configAddr: "s_rw_0_10_0_632"
                }
                ICIMMText{width: 10}
                ICIMMCheckBoxEdit{
                    id:s_rw_29_1_0_633
                    configAddr: "s_rw_29_1_0_633"
                }
                ICIMMLabelComboBoxEdit{
                    id:s_rw_30_2_0_633
                    configAddr: "s_rw_30_2_0_633"
                    items: s_rw_30_2_0_630.items
                }
                ICIMMLabelComboBoxEdit{
                    id:s_rw_20_9_0_633
                    configAddr: "s_rw_20_9_0_633"
                    items: s_rw_20_9_0_630.items
                }
                ICIMMLineEdit{
                    id:s_rw_10_10_0_633
                    configAddr: "s_rw_10_10_0_633"
                }
                ICIMMLineEdit{
                    id:s_rw_0_10_0_633
                    configAddr: "s_rw_0_10_0_633"
                }

                ICIMMCheckBoxEdit{
                    id:s_rw_29_1_0_634
                    configAddr: "s_rw_29_1_0_634"
                }
                ICIMMLabelComboBoxEdit{
                    id:s_rw_30_2_0_634
                    configAddr: "s_rw_30_2_0_634"
                    items:s_rw_30_2_0_630.items
                }
                ICIMMLabelComboBoxEdit{
                    id:s_rw_20_9_0_634
                    configAddr: "s_rw_20_9_0_634"
                    items: s_rw_20_9_0_630.items
                }
                ICIMMLineEdit{
                    id:s_rw_10_10_0_634
                    configAddr: "s_rw_10_10_0_634"
                }
                ICIMMLineEdit{
                    id:s_rw_0_10_0_634
                    configAddr: "s_rw_0_10_0_634"
                }
                ICIMMText{width: 10}
                ICIMMCheckBoxEdit{
                    id:s_rw_29_1_0_635
                    configAddr: "s_rw_29_1_0_635"
                }
                ICIMMLabelComboBoxEdit{
                    id:s_rw_30_2_0_635
                    configAddr: "s_rw_30_2_0_635"
                    items: s_rw_30_2_0_630.items
                }
                ICIMMLabelComboBoxEdit{
                    id:s_rw_20_9_0_635
                    configAddr: "s_rw_20_9_0_635"
                    items: s_rw_20_9_0_630.items
                }
                ICIMMLineEdit{
                    id:s_rw_10_10_0_635
                    configAddr: "s_rw_10_10_0_635"
                }
                ICIMMLineEdit{
                    id:s_rw_0_10_0_635
                    configAddr: "s_rw_0_10_0_635"
                }

                ICIMMCheckBoxEdit{
                    id:s_rw_29_1_0_636
                    configAddr: "s_rw_29_1_0_636"
                }
                ICIMMLabelComboBoxEdit{
                    id:s_rw_30_2_0_636
                    configAddr: "s_rw_30_2_0_636"
                    items:s_rw_30_2_0_630.items
                }
                ICIMMLabelComboBoxEdit{
                    id:s_rw_20_9_0_636
                    configAddr: "s_rw_20_9_0_636"
                    items: s_rw_20_9_0_630.items
                }
                ICIMMLineEdit{
                    id:s_rw_10_10_0_636
                    configAddr: "s_rw_10_10_0_636"
                }
                ICIMMLineEdit{
                    id:s_rw_0_10_0_636
                    configAddr: "s_rw_0_10_0_636"
                }
                ICIMMText{width: 10}
                ICIMMCheckBoxEdit{
                    id:s_rw_29_1_0_637
                    configAddr: "s_rw_29_1_0_637"
                }
                ICIMMLabelComboBoxEdit{
                    id:s_rw_30_2_0_637
                    configAddr: "s_rw_30_2_0_637"
                    items: s_rw_30_2_0_630.items
                }
                ICIMMLabelComboBoxEdit{
                    id:s_rw_20_9_0_637
                    configAddr: "s_rw_20_9_0_637"
                    items: s_rw_20_9_0_630.items
                }
                ICIMMLineEdit{
                    id:s_rw_10_10_0_637
                    configAddr: "s_rw_10_10_0_637"
                }
                ICIMMLineEdit{
                    id:s_rw_0_10_0_637
                    configAddr: "s_rw_0_10_0_637"
                }

                ICIMMCheckBoxEdit{
                    id:s_rw_29_1_0_638
                    configAddr: "s_rw_29_1_0_638"
                }
                ICIMMLabelComboBoxEdit{
                    id:s_rw_30_2_0_638
                    configAddr: "s_rw_30_2_0_638"
                    items:s_rw_30_2_0_630.items
                }
                ICIMMLabelComboBoxEdit{
                    id:s_rw_20_9_0_638
                    configAddr: "s_rw_20_9_0_638"
                    items: s_rw_20_9_0_630.items
                }
                ICIMMLineEdit{
                    id:s_rw_10_10_0_638
                    configAddr: "s_rw_10_10_0_638"
                }
                ICIMMLineEdit{
                    id:s_rw_0_10_0_638
                    configAddr: "s_rw_0_10_0_638"
                }
                ICIMMText{width: 10}
                ICIMMCheckBoxEdit{
                    id:s_rw_29_1_0_639
                    configAddr: "s_rw_29_1_0_639"
                }
                ICIMMLabelComboBoxEdit{
                    id:s_rw_30_2_0_639
                    configAddr: "s_rw_30_2_0_639"
                    items: s_rw_30_2_0_630.items
                }
                ICIMMLabelComboBoxEdit{
                    id:s_rw_20_9_0_639
                    configAddr: "s_rw_20_9_0_639"
                    items: s_rw_20_9_0_630.items
                }
                ICIMMLineEdit{
                    id:s_rw_10_10_0_639
                    configAddr: "s_rw_10_10_0_639"
                }
                ICIMMLineEdit{
                    id:s_rw_0_10_0_639
                    configAddr: "s_rw_0_10_0_639"
                }

                ICIMMCheckBoxEdit{
                    id:s_rw_29_1_0_640
                    configAddr: "s_rw_29_1_0_640"
                }
                ICIMMLabelComboBoxEdit{
                    id:s_rw_30_2_0_640
                    configAddr: "s_rw_30_2_0_640"
                    items:s_rw_30_2_0_630.items
                }
                ICIMMLabelComboBoxEdit{
                    id:s_rw_20_9_0_640
                    configAddr: "s_rw_20_9_0_640"
                    items: s_rw_20_9_0_630.items
                }
                ICIMMLineEdit{
                    id:s_rw_10_10_0_640
                    configAddr: "s_rw_10_10_0_640"
                }
                ICIMMLineEdit{
                    id:s_rw_0_10_0_640
                    configAddr: "s_rw_0_10_0_640"
                }
                ICIMMText{width: 10}
                ICIMMCheckBoxEdit{
                    id:s_rw_29_1_0_641
                    configAddr: "s_rw_29_1_0_641"
                }
                ICIMMLabelComboBoxEdit{
                    id:s_rw_30_2_0_641
                    configAddr: "s_rw_30_2_0_641"
                    items: s_rw_30_2_0_630.items
                }
                ICIMMLabelComboBoxEdit{
                    id:s_rw_20_9_0_641
                    configAddr: "s_rw_20_9_0_641"
                    items: s_rw_20_9_0_630.items
                }
                ICIMMLineEdit{
                    id:s_rw_10_10_0_641
                    configAddr: "s_rw_10_10_0_641"
                }
                ICIMMLineEdit{
                    id:s_rw_0_10_0_641
                    configAddr: "s_rw_0_10_0_641"
                }

                ICIMMCheckBoxEdit{
                    id:s_rw_29_1_0_642
                    configAddr: "s_rw_29_1_0_642"
                }
                ICIMMLabelComboBoxEdit{
                    id:s_rw_30_2_0_642
                    configAddr: "s_rw_30_2_0_642"
                    items:s_rw_30_2_0_630.items
                }
                ICIMMLabelComboBoxEdit{
                    id:s_rw_20_9_0_642
                    configAddr: "s_rw_20_9_0_642"
                    items: s_rw_20_9_0_630.items
                }
                ICIMMLineEdit{
                    id:s_rw_10_10_0_642
                    configAddr: "s_rw_10_10_0_642"
                }
                ICIMMLineEdit{
                    id:s_rw_0_10_0_642
                    configAddr: "s_rw_0_10_0_642"
                }
                ICIMMText{width: 10}
                ICIMMCheckBoxEdit{
                    id:s_rw_29_1_0_643
                    configAddr: "s_rw_29_1_0_643"
                }
                ICIMMLabelComboBoxEdit{
                    id:s_rw_30_2_0_643
                    configAddr: "s_rw_30_2_0_643"
                    items: s_rw_30_2_0_630.items
                }
                ICIMMLabelComboBoxEdit{
                    id:s_rw_20_9_0_643
                    configAddr: "s_rw_20_9_0_643"
                    items: s_rw_20_9_0_630.items
                }
                ICIMMLineEdit{
                    id:s_rw_10_10_0_643
                    configAddr: "s_rw_10_10_0_643"
                }
                ICIMMLineEdit{
                    id:s_rw_0_10_0_643
                    configAddr: "s_rw_0_10_0_643"
                }

                ICIMMCheckBoxEdit{
                    id:s_rw_29_1_0_644
                    configAddr: "s_rw_29_1_0_644"
                }
                ICIMMLabelComboBoxEdit{
                    id:s_rw_30_2_0_644
                    configAddr: "s_rw_30_2_0_644"
                    items:s_rw_30_2_0_630.items
                }
                ICIMMLabelComboBoxEdit{
                    id:s_rw_20_9_0_644
                    configAddr: "s_rw_20_9_0_644"
                    items: s_rw_20_9_0_630.items
                }
                ICIMMLineEdit{
                    id:s_rw_10_10_0_644
                    configAddr: "s_rw_10_10_0_644"
                }
                ICIMMLineEdit{
                    id:s_rw_0_10_0_644
                    configAddr: "s_rw_0_10_0_644"
                }
                ICIMMText{width: 10}
                ICIMMCheckBoxEdit{
                    id:s_rw_29_1_0_645
                    configAddr: "s_rw_29_1_0_645"
                }
                ICIMMLabelComboBoxEdit{
                    id:s_rw_30_2_0_645
                    configAddr: "s_rw_30_2_0_645"
                    items: s_rw_30_2_0_630.items
                }
                ICIMMLabelComboBoxEdit{
                    id:s_rw_20_9_0_645
                    configAddr: "s_rw_20_9_0_645"
                    items: s_rw_20_9_0_630.items
                }
                ICIMMLineEdit{
                    id:s_rw_10_10_0_645
                    configAddr: "s_rw_10_10_0_645"
                }
                ICIMMLineEdit{
                    id:s_rw_0_10_0_645
                    configAddr: "s_rw_0_10_0_645"
                }

                ICIMMCheckBoxEdit{
                    id:s_rw_29_1_0_646
                    configAddr: "s_rw_29_1_0_646"
                }
                ICIMMLabelComboBoxEdit{
                    id:s_rw_30_2_0_646
                    configAddr: "s_rw_30_2_0_646"
                    items:s_rw_30_2_0_630.items
                }
                ICIMMLabelComboBoxEdit{
                    id:s_rw_20_9_0_646
                    configAddr: "s_rw_20_9_0_646"
                    items: s_rw_20_9_0_630.items
                }
                ICIMMLineEdit{
                    id:s_rw_10_10_0_646
                    configAddr: "s_rw_10_10_0_646"
                }
                ICIMMLineEdit{
                    id:s_rw_0_10_0_646
                    configAddr: "s_rw_0_10_0_646"
                }
                ICIMMText{width: 10}
                ICIMMCheckBoxEdit{
                    id:s_rw_29_1_0_647
                    configAddr: "s_rw_29_1_0_647"
                }
                ICIMMLabelComboBoxEdit{
                    id:s_rw_30_2_0_647
                    configAddr: "s_rw_30_2_0_647"
                    items: s_rw_30_2_0_630.items
                }
                ICIMMLabelComboBoxEdit{
                    id:s_rw_20_9_0_647
                    configAddr: "s_rw_20_9_0_647"
                    items: s_rw_20_9_0_630.items
                }
                ICIMMLineEdit{
                    id:s_rw_10_10_0_647
                    configAddr: "s_rw_10_10_0_647"
                }
                ICIMMLineEdit{
                    id:s_rw_0_10_0_647
                    configAddr: "s_rw_0_10_0_647"
                }

                ICIMMCheckBoxEdit{
                    id:s_rw_29_1_0_648
                    configAddr: "s_rw_29_1_0_648"
                }
                ICIMMLabelComboBoxEdit{
                    id:s_rw_30_2_0_648
                    configAddr: "s_rw_30_2_0_648"
                    items:s_rw_30_2_0_630.items
                }
                ICIMMLabelComboBoxEdit{
                    id:s_rw_20_9_0_648
                    configAddr: "s_rw_20_9_0_648"
                    items: s_rw_20_9_0_630.items
                }
                ICIMMLineEdit{
                    id:s_rw_10_10_0_648
                    configAddr: "s_rw_10_10_0_648"
                }
                ICIMMLineEdit{
                    id:s_rw_0_10_0_648
                    configAddr: "s_rw_0_10_0_648"
                }
                ICIMMText{width: 10}
                ICIMMCheckBoxEdit{
                    id:s_rw_29_1_0_649
                    configAddr: "s_rw_29_1_0_649"
                }
                ICIMMLabelComboBoxEdit{
                    id:s_rw_30_2_0_649
                    configAddr: "s_rw_30_2_0_649"
                    items: s_rw_30_2_0_630.items
                }
                ICIMMLabelComboBoxEdit{
                    id:s_rw_20_9_0_649
                    configAddr: "s_rw_20_9_0_649"
                    items: s_rw_20_9_0_630.items
                }
                ICIMMLineEdit{
                    id:s_rw_10_10_0_649
                    configAddr: "s_rw_10_10_0_649"
                }
                ICIMMLineEdit{
                    id:s_rw_0_10_0_649
                    configAddr: "s_rw_0_10_0_649"
                }

            }
        }
    }

    Component.onCompleted: {
        addPage(ioDefinePage);
        addPage(aidOutputPage);
    }

}

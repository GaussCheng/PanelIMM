import QtQuick 1.1
import "../../ICCustomElement"
import "../immcustomitems"
import "../../styles/style.js" as Style
ICIMMFunctionPageBase {
    id:instance
    ICSettingPageBase{
        id:page1
        width: parent.width
        height: parent.height
        onEditorFocusChanged: {
            instance.editorFocusChanged(now);
        }
        ICIMMSettingConfigsScope{
            id:topRow
            width: page1.width
            height: page1.height
            Grid{
                x:4
                y:2
                columns: 5
                ICIMMText{}
                ICIMMText{text:qsTr("TOTAL")}
                ICIMMText{text:qsTr("GOOD")}
                ICIMMText{text:qsTr("BAD")}
                ICIMMText{text:qsTr("BOX NO.")}

                ICIMMText{text: qsTr("FUNC")}
                ICIMMCheckBoxEdit{
                    id:m_rw_12_1_0_444
                    configAddr: "m_rw_12_1_0_444"
                }
                ICIMMCheckBoxEdit{
                    id:m_rw_13_1_0_444
                    configAddr: "m_rw_13_1_0_444"
                }
                ICIMMCheckBoxEdit{
                    id:m_rw_14_1_0_444
                    configAddr: "m_rw_14_1_0_444"
                }
                ICIMMCheckBoxEdit{
                    id:m_rw_15_1_0_444
                    configAddr: "m_rw_15_1_0_444"
                }

                ICIMMText{text: qsTr("Tips Select")}
                ICIMMCheckBoxEdit{
                    id:m_rw_18_1_0_444
                    configAddr: "m_rw_18_1_0_444"
                }
                ICIMMCheckBoxEdit{
                    id:m_rw_19_1_0_444
                    configAddr: "m_rw_19_1_0_444"
                }
                ICIMMCheckBoxEdit{
                    id:m_rw_20_1_0_444
                    configAddr: "m_rw_20_1_0_444"
                }
                ICIMMCheckBoxEdit{
                    id:m_rw_21_1_0_444
                    configAddr: "m_rw_21_1_0_444"
                }

                ICIMMText{text: qsTr("TARGET")}
                ICIMMLineEdit{
                    id:m_rw_0_32_0_432
                    configAddr: "m_rw_0_32_0_432"
                }
                ICIMMLineEdit{
                    id:m_rw_0_32_0_433
                    configAddr: "m_rw_0_32_0_433"
                }
                ICIMMLineEdit{
                    id:m_rw_0_32_0_434
                    configAddr: "m_rw_0_32_0_434"
                }
                ICIMMLineEdit{
                    id:m_rw_0_32_0_435
                    configAddr: "m_rw_0_32_0_435"
                }

                ICIMMText{text: qsTr("CURRENT")}
                ICIMMStatusWidget{
                    id:c_ro_0_32_0_1564
                    bindStatus: "c_ro_0_32_0_1564"
                }
                ICIMMStatusWidget{
                    id:c_ro_0_32_0_1565
                    bindStatus: "c_ro_0_32_0_1565"
                }
                ICIMMStatusWidget{
                    id:c_ro_0_32_0_1566
                    bindStatus: "c_ro_0_32_0_1566"
                }
                ICIMMStatusWidget{
                    id:c_ro_0_32_0_1567
                    bindStatus: "c_ro_0_32_0_1567"
                }

                ICIMMText{}
                ICIMMButton{
                    id:resetTotal
                    text: qsTr("Reset")
                }
                ICIMMButton{
                    id:resetGood
                    text: qsTr("Reset")
                }
                ICIMMButton{
                    id:resetBad
                    text: qsTr("Reset")
                }
                ICIMMButton{
                    id:resetBoxNo
                    text: qsTr("Reset")
                }
            }
        }
        ICIMMSettingConfigsScope{
            id:bottomRow
            width: page1.width
            height: page1.height
            Grid{
                x:4
                y:2
                anchors.top: topRow.bottom
                columns: 6

                ICIMMText{}
                ICIMMText{text: qsTr("CUSHION")}
                ICIMMText{text: qsTr("CHRG_END")}
                ICIMMText{text: qsTr("MD O END")}
                ICIMMText{text: qsTr("CYCLE TM")}
                ICIMMText{text: qsTr("CAVITY NO")}

                ICIMMText{}
                ICIMMText{text: qsTr("(mm)")}
                ICIMMText{text: qsTr("(mm)")}
                ICIMMText{text: qsTr("(mm)")}
                ICIMMText{text: qsTr("(s)")}
                ICIMMText{}

                ICIMMText{text: qsTr("FUNC")}
                ICIMMCheckBoxEdit{
                    id:m_rw_8_1_0_444
                    configAddr: "m_rw_8_1_0_444"
                }
                ICIMMCheckBoxEdit{
                    id:m_rw_9_1_0_444
                    configAddr: "m_rw_9_1_0_444"
                }
                ICIMMCheckBoxEdit{
                    id:m_rw_10_1_0_444
                    configAddr: "m_rw_10_1_0_444"
                }
                ICIMMCheckBoxEdit{
                    id:m_rw_11_1_0_444
                    configAddr: "m_rw_11_1_0_444"
                }
                ICIMMLineEdit{
                    id:m_rw_0_8_0_444
                    configAddr: "m_rw_0_8_0_444"
                }

                ICIMMText{text: qsTr("QC_VALUE")}
                ICIMMLineEdit{
                    id:m_rw_0_16_1_440
                    configAddr: "m_rw_0_16_1_440"
                }
                ICIMMLineEdit{
                    id:m_rw_16_16_1_440
                    configAddr: "m_rw_16_16_1_440"
                }
                ICIMMLineEdit{
                    id:m_rw_0_16_1_441
                    configAddr: "m_rw_0_16_1_441"
                }
                ICIMMLineEdit{
                    id:m_rw_16_16_1_441
                    configAddr: "m_rw_16_16_1_441"
                }
                ICIMMText{}

                ICIMMText{text: qsTr("TOLERANCE")}
                ICIMMLineEdit{
                    id:m_rw_0_16_1_442
                    configAddr: "m_rw_0_16_1_442"
                }
                ICIMMLineEdit{
                    id:m_rw_16_16_1_442
                    configAddr: "m_rw_16_16_1_442"
                }
                ICIMMLineEdit{
                    id:m_rw_0_16_1_443
                    configAddr: "m_rw_0_16_1_443"
                }
                ICIMMLineEdit{
                    id:m_rw_16_16_1_443
                    configAddr: "m_rw_16_16_1_443"
                }
                ICIMMText{}

                ICIMMText{text: qsTr("AVERAGE")}
                ICIMMStatusWidget{
                }
                ICIMMStatusWidget{
                }
                ICIMMStatusWidget{
                }
                ICIMMStatusWidget{
                }
                ICIMMText{}

            }
        }
    }
}

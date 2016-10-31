import QtQuick 1.1
import "../../ICCustomElement"
import "../immcustomitems"
import "../../styles/style.js" as Style
ICIMMFunctionPageBase {
    id:instance
    ICStatusScope{
        anchors.bottom: parent.bottom
        width: parent.width
        height: parent.height - 44 * Style.hRatio
        Image {
            id: machineDesk
            source: "../images/machine_desk.png"
            width: sourceSize.width * Style.wRatio
            height: sourceSize.height * Style.hRatio
            Item{
                id:statusContaine
                y:180 * Style.hRatio
                x:80 * Style.wRatio
                Row{
                    spacing: 40 * Style.wRatio
                    ICIMMLabelStatusWidget{
                        id:c_ro_0_32_0_1564
                        bindStatus: "c_ro_0_32_0_1564"
                        configName: qsTr("PC:")
                        unit: qsTr("pc")
                        color: "yellow"
                        width: 150 * Style.wRatio
                    }
                    ICIMMLabelStatusWidget{
                        id:c_ro_0_32_1_1569
                        bindStatus: "c_ro_0_32_1_1569"
                        configName: qsTr("C.C:")
                        unit: qsTr("s")
                        color: c_ro_0_32_0_1564.color
                        width: c_ro_0_32_0_1564.width
                    }
                    ICIMMLabelStatusWidget{
                        id:c_ro_0_32_1_1568
                        bindStatus: "c_ro_0_32_1_1568"
                        configName: qsTr("L.C:")
                        unit: qsTr("s")
                        color: c_ro_0_32_0_1564.color
                        width: c_ro_0_32_0_1564.width
                    }
                }
                Row{
                    y:40 * Style.hRatio
                    spacing: 180 * Style.wRatio
                    ICIMMLabelStatusWidget{
                        id:c_ro_16_16_1_1573
                        bindStatus: "c_ro_16_16_1_1573"
                        configName: qsTr("A.Time:")
                        unit: qsTr("s")
                        color: c_ro_0_32_0_1564.color
                        width: 100 * Style.wRatio
                    }
                    ICIMMLabelStatusWidget{
                        id:c_ro_16_16_1_1563
                        bindStatus: "c_ro_16_16_1_1563"
                        configName: qsTr("O.T:")
                        unit: qsTr("°C")
                        color: c_ro_0_32_0_1564.color
                        width: 60 * Style.wRatio
                    }
                }
            }
        }
        Image {
            id: machineEjectorBase
            source: "../images/machine_ejector_base.png"
            width: sourceSize.width * Style.wRatio
            height: sourceSize.height * Style.hRatio
            x:180 * Style.wRatio
            Image {
                id: machineEjector
                source: "../images/machine_ejector.png"
                width: sourceSize.width * Style.wRatio
                height: sourceSize.height * Style.hRatio
                x:-20 * Style.wRatio
            }
        }
        Image {
            id: machineDeskEf
            source: "../images/machine_desk_ef.png"
            width: sourceSize.width * Style.wRatio
            height: sourceSize.height * Style.hRatio
            x:342 * Style.wRatio

        }
        Item{
            id:machineScrewBase
            x:398 * Style.wRatio
            Image {
                id:machineScrewBaseBG
                source: "../images/machine_screw_base.png"
                width: sourceSize.width * Style.wRatio
                height: sourceSize.height * Style.hRatio
            }
            Image {
                id: machineScrew
                source: "../images/machine_screw.png"
                width: sourceSize.width * Style.wRatio
                height: sourceSize.height * Style.hRatio
            }
        }
        Column{
            anchors.bottom: parent.top
            anchors.bottomMargin: -20
            spacing: 4
            x:4
            Row{
                id:heatStatusContainer
                ICIMMTwoStatusWidget{
                    id:heatStatusSeg0
                    onImg: "../images/heat-seg0.png"
                    offImg: "../images/cool-seg0.png"
                    isOn: true
                    bindStatus: "c_ro_0_16_1_1560"
                }
                ICIMMTwoStatusWidget{
                    id:heatStatusSeg1
                    onImg: "../images/heat-segn.png"
                    offImg: "../images/cool-segn.png"
                    bindStatus: "c_ro_16_16_1_1560"

                }
                ICIMMTwoStatusWidget{
                    id:heatStatusSeg2
                    onImg: heatStatusSeg1.onImg
                    offImg: heatStatusSeg1.offImg
                    isOn: true
                    bindStatus: "c_ro_0_16_1_1561"

                }
                ICIMMTwoStatusWidget{
                    id:heatStatusSeg3
                    onImg: heatStatusSeg1.onImg
                    offImg: heatStatusSeg1.offImg
                    bindStatus: "c_ro_16_16_1_1561"

                }
                ICIMMTwoStatusWidget{
                    id:heatStatusSeg4
                    onImg: heatStatusSeg1.onImg
                    offImg: heatStatusSeg1.offImg
                    bindStatus: "c_ro_0_16_1_1562"

                }
                ICIMMTwoStatusWidget{
                    id:heatStatusSeg5
                    onImg: heatStatusSeg1.onImg
                    offImg: heatStatusSeg1.offImg
                    bindStatus: "c_ro_16_16_1_1562"

                }
                ICIMMTwoStatusWidget{
                    id:heatStatusSeg6
                    onImg: heatStatusSeg1.onImg
                    offImg: heatStatusSeg1.offImg
                    bindStatus: "c_ro_0_16_1_1563"

                }
            }
            Item{
                height: heatSeg0Setting.height
                width: heatStatusContainer.width
                ICIMMLineEdit{
                    id:heatSeg0Setting
                    enabled: false
                    width: heatStatusSeg0.width - 4
                    height: 16
                    border.color: "white"
                    x:heatStatusSeg0.x + 2
                }
                ICIMMLineEdit{
                    id:heatSeg1Setting
                    enabled: heatSeg0Setting.enabled
                    width: heatStatusSeg1.width - 4
                    height: heatSeg0Setting.height
                    border.color: "white"
                    x:heatStatusSeg1.x + 2

                }
                ICIMMLineEdit{
                    id:heatSeg2Setting
                    enabled: heatSeg0Setting.enabled
                    width: heatSeg1Setting.width
                    height: heatSeg0Setting.height
                    border.color: heatSeg1Setting.border.color
                    x:heatStatusSeg2.x + 2

                }
                ICIMMLineEdit{
                    id:heatSeg3Setting
                    enabled: heatSeg0Setting.enabled
                    width: heatSeg1Setting.width
                    height: heatSeg0Setting.height
                    border.color: heatSeg1Setting.border.color
                    x:heatStatusSeg3.x + 2

                }
                ICIMMLineEdit{
                    id:heatSeg4Setting
                    enabled: heatSeg0Setting.enabled
                    width: heatSeg1Setting.width
                    height: heatSeg0Setting.height
                    border.color: heatSeg1Setting.border.color
                    x:heatStatusSeg4.x + 2

                }
                ICIMMLineEdit{
                    id:heatSeg5Setting
                    enabled: heatSeg0Setting.enabled
                    width: heatSeg1Setting.width
                    height: heatSeg0Setting.height
                    border.color: heatSeg1Setting.border.color
                    x:heatStatusSeg5.x + 2

                }
                ICIMMLineEdit{
                    id:heatSeg6Setting
                    enabled: heatSeg0Setting.enabled
                    width: heatSeg1Setting.width
                    height: heatSeg0Setting.height
                    border.color: heatSeg1Setting.border.color
                    x:heatStatusSeg6.x + 2

                }
            }
        }
    }
}

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
    }
}

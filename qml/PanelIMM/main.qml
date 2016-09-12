import QtQuick 1.1
import "../ICCustomElement"
import "immcustomitems"
import "../utils/utils.js" as Utils
import "style.js" as Style

Rectangle {
    id:mainWindow
    width: Style.mainWindow.rect.width
    height: Style.mainWindow.rect.height

    Rectangle{
        id:monitorSection
        width: Style.monitorSection.rect.width
        height: Style.monitorSection.rect.height
        color: Style.monitorSection.bg
        Row{
            Column{
                id:convenientMonitorSection
                Rectangle{
                    id:convenientMonitorSectionHeader
                    width: Style.monitorSection.header.rect.width
                    height: Style.monitorSection.header.rect.height >> 1
                    color: Style.monitorSection.header.bg
                }
                ICStackContainer{
                    id:convenientMonitorPagesContainer
                    width: convenientMonitorSectionHeader.width
                    height: monitorSection.height - convenientMonitorSectionHeader.height
                }
            }
            Column{
                id:normalMonitorSection
                Rectangle{
                    id:normalMonitorSectionHeader
                    width: Style.monitorSection.header.rect.width
                    height: Style.monitorSection.header.rect.height
                    color: Style.monitorSection.header.bg
                }
                ICStackContainer{
                    id:normalMonitorPagesContainer
                    width: normalMonitorSectionHeader.width
                    height: monitorSection.height - normalMonitorSectionHeader.height
                }
            }
        }
    }

    Rectangle{
        id:detailPagesSection
        color: detailMenuSection.color
        width: detailMenuSection.width
        anchors.top: monitorSection.bottom
        anchors.bottom: detailMenuSection.top
    }


    Rectangle{
        id:detailMenuSection
        anchors.bottom: touchControlSection.top
        width: Style.detailMenuSection.rect.width
        height: Style.detailMenuSection.rect.height
        color: Style.detailMenuSection.bg
        ICButtonGroup{
            spacing: 1
            ICIMMDetailMenuItem{
                id:dMI1
                width: Style.detailMenuSection.rect.width / 8 - 1
                height: Style.detailMenuSection.rect.height
            }
            ICIMMDetailMenuItem{
                id:dMI2
                width: dMI1.width
                height: dMI1.height
            }
            ICIMMDetailMenuItem{
                id:dMI3
                width: dMI1.width
                height: dMI1.height
            }
            ICIMMDetailMenuItem{
                id:dMI4
                width: dMI1.width
                height: dMI1.height
            }
            ICIMMDetailMenuItem{
                id:dMI5
                width: dMI1.width
                height: dMI1.height
            }
            ICIMMDetailMenuItem{
                id:dMI6
                width: dMI1.width
                height: dMI1.height
            }
            ICIMMDetailMenuItem{
                id:dMI7
                width: dMI1.width
                height: dMI1.height
            }
            ICIMMDetailMenuItem{
                id:dMI8
                width: dMI1.width
                height: dMI1.height
            }
        }
    }
    ICTouchControlSection{
        id:touchControlSection
        anchors.bottom: parent.bottom
    }
}


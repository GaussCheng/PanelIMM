import QtQuick 1.1
import "../../styles/style.js" as Style

ICIMMDetailMenuItem{
    radius: 0
    width: Style.touchControlSection.pageMenuKeyboard.btnWidth
    height: Style.touchControlSection.pageMenuKeyboard.btnHeight
    bgColor: Style.touchControlSection.pageMenuKeyboard.btnBG
    font.pixelSize: Style.touchControlSection.functionMenuItem.font.pixelSize

    property string monitorComponent: ""
}

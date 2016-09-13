import QtQuick 1.1
import "../style.js" as Style

ICIMMDetailMenuItem{
    radius: 0
    width: Style.touchControlSection.pageMenuKeyboard.btnWidth
    height: Style.touchControlSection.pageMenuKeyboard.btnHeight
    bgColor: Style.touchControlSection.pageMenuKeyboard.btnBG

    property string monitorComponent: ""
}

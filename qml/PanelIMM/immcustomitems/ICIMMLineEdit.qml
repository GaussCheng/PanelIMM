import QtQuick 1.1
import "../../ICCustomElement"
import "../../styles/style.js" as Style

ICLineEdit {
    width: 50 * Style.wRatio
    font.pixelSize: Style.itemStyles.defaultFont.pixelSize
    height: Style.itemStyles.defaultSize.height
    horizontalAlignment:Text.AlignRight
}

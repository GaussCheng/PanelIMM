import QtQuick 1.1
import "../../ICCustomElement"
import "../../styles/style.js" as Style
ICCheckBoxEdit {
    id:instance
    property alias configName: instance.text
    height: 24 * Style.scaleRatio
    font.pixelSize: Style.itemStyles.defaultFont.pixelSize
}

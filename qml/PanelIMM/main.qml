import QtQuick 1.1
import "../ICCustomElement"
import "../utils/utils.js" as Utils
import "style.js" as Style

Rectangle {
    id:mainWindow
    width: Style.mainWindow.rect.width
    height: Style.mainWindow.rect.height

    ICTouchControlSection{
        id:touchControlSection
        anchors.bottom: parent.bottom
    }
}


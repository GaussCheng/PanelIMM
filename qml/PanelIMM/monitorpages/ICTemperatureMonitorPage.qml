import QtQuick 1.1
import Extentuis 1.0
import "../../ICCustomElement"
import "../immcustomitems"
Rectangle {
    ICAxis {
        id: temperatureCurve
        width: parent.width
        height: parent.height
        titleFont.pixelSize: 10
        xAxisTitle: qsTr("Time[hh:mm:ss]")
        yAxisTitle:qsTr("Temperature°C")
        canvasBackground:"#242424"
        majColor:"white"
    }
}

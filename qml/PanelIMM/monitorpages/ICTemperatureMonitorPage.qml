import QtQuick 1.1
import Extentuis 1.0
import "../../ICCustomElement"
import "../immcustomitems"
import "../../utils/utils.js" as Utils
import "../main.js" as Main
Rectangle {
    id:instance
    color: "transparent"
    onVisibleChanged: {
        if(!visible)
            temperatureCurveContainer.zoomOut(instance);
    }

    ICIMMTemperatureCurves{
        id:temperatureCurveContainer
        width: parent.width
        height: parent.height
        color:parent.color
        ICIMMButton{
            id:zoomInBtn
            text: "+"
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 10
            x: 4
            width: 30
            onButtonClicked: {
                if(!temperatureCurveContainer.isZoomIn)
                    temperatureCurveContainer.zoomIn(Main.mainWindow);
                else
                    temperatureCurveContainer.zoomOut(instance);
            }
        }
    }
}

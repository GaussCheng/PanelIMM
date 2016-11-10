import QtQuick 1.1
import Extentuis 1.0
import "../../ICCustomElement"
import "../immcustomitems"
import "../../utils/utils.js" as Utils
import "../main.js" as Main
Rectangle {
    id:instance
    property bool isZoomIn: false
    function zoomIn(toParent){
        color = "gray";
        axisConfigContainer.visible = true;
        instance.parent = toParent;
        width = toParent.width;
        height = width * 0.55;
        injectCurve.width = width;
        injectCurve.height = height * 0.8;
        injectCurve.y = axisConfigContainer.y + axisConfigContainer.height + 6;
        zoomInBtn.text = "-";
        isZoomIn = true;
    }

    function zoomOut(toParent){
        instance.parent = toParent;
        width = parent.width;
        height = parent.height;
        color = parent.color;
        injectCurve.height = height;
        injectCurve.width = width;
        injectCurve.y = 0;
        axisConfigContainer.visible = false;
        isZoomIn = false;
        zoomInBtn.text = "+";
    }

    Grid{
        id:axisConfigContainer
        visible: false
        columns: 6
        ICIMMText{text: qsTr("Last Count")}
        ICIMMLineEdit{
            id:lastCount
            configValue: "100"
        }
        ICIMMText{text:qsTr("Count Space")}
        ICIMMLineEdit{
            id:countSpace
            configValue: "10"
        }
        ICIMMText{}
        ICIMMText{}

        ICIMMText{text: qsTr("Pos Min")}
        ICIMMLineEdit{
            id:posMin
            decimal: 2
            configValue: "0.00"
        }
        ICIMMText{text: qsTr("Pos Max")}
        ICIMMLineEdit{
            id:posMax
            decimal: 2
            configValue: "100.00"
        }
        ICIMMText{text:qsTr("Pos Space")}
        ICIMMLineEdit{
            id:posSpace
            decimal: 2
            configValue: "10.00"
        }
    }
    ICInjectCurve{
        id:injectCurve
        width: parent.width
        height: parent.height

        color: parent.color
        titleFont.pixelSize: 10
        axisFont.pixelSize:9
        xAxisTitle: qsTr("Mold Count")
        yAxisTitle:qsTr("Pos End[mm]")
        canvasBackground:"#242424"
        majColor:"white"
        count: parseInt(lastCount.configValue)
        countSpace: parseInt(countSpace.configValue)
        minInjEnd: parseFloat(posMin.configValue)
        maxInjEnd: parseFloat(posMax.configValue)
        injSpace: parseFloat(posSpace.configValue)
    }
}

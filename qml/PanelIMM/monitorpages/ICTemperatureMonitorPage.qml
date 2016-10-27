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
            temperatureCurveContainer.zoomOut();
    }

    Rectangle{
        id:temperatureCurveContainer
        width: parent.width
        height: parent.height
        color:parent.color
        property bool isZoomIn: false
        function zoomIn(){
            color = "gray";
            curvesSelContainer.visible = true;
            axisConfigContainer.visible = true;
            temperatureCurveContainer.parent = Main.mainWindow;
            width = Main.mainWindow.width;
            height = width * 0.55;
            temperatureCurve.width = width;
            temperatureCurve.height = height * 0.8;
            temperatureCurve.y = axisConfigContainer.y + axisConfigContainer.height + 6;
            zoomInBtn.text = qsTr("ZoomOut");
            isZoomIn = true;
        }

        function zoomOut(){
            temperatureCurveContainer.parent = instance;
            width = parent.width;
            height = parent.height;
            color = parent.color;
            temperatureCurve.height = height;
            temperatureCurve.width = width;
            temperatureCurve.y = 0;
            curvesSelContainer.visible = false;
            axisConfigContainer.visible = false;
            isZoomIn = false;
        }

        Row{
            id:curvesSelContainer
            visible: false
            spacing: 6
            ICIMMText{text:qsTr("Curve to show")}
            ICIMMCheckBoxEdit{
                id:seg0
                text: qsTr("SEG-0")
                textColor: temperatureCurve.curveColor(0)
            }
            ICIMMCheckBoxEdit{
                id:seg1
                text: qsTr("SEG-1")
                textColor: temperatureCurve.curveColor(1)

            }
            ICIMMCheckBoxEdit{
                id:seg2
                text: qsTr("SEG-2")
                textColor: temperatureCurve.curveColor(2)

            }
            ICIMMCheckBoxEdit{
                id:seg3
                text: qsTr("SEG-3")
                textColor: temperatureCurve.curveColor(3)
            }
            ICIMMCheckBoxEdit{
                id:seg4
                text: qsTr("SEG-4")
                textColor: temperatureCurve.curveColor(4)
            }
            ICIMMCheckBoxEdit{
                id:seg5
                text: qsTr("SEG-5")
                textColor: temperatureCurve.curveColor(5)

            }
            ICIMMCheckBoxEdit{
                id:seg6
                text: qsTr("SEG-6")
                textColor: temperatureCurve.curveColor(6)

            }
            ICIMMCheckBoxEdit{
                id:seg7
                text: qsTr("SEG-7")
                textColor: temperatureCurve.curveColor(7)
            }
        }
        Row{
            id:axisConfigContainer
            anchors.top: curvesSelContainer.bottom
            anchors.topMargin: 6
            visible: false
            spacing: 6
            function changeYAxisScale(){
                var c = (parseInt(yMax.configValue) - parseInt(yMin.configValue))/10;
                temperatureCurve.setYAxisScale(yMin.configValue, yMax.configValue, Math.max(c, parseInt(yStep.configValue)));
            }

            ICIMMLabelLineEdit{
                id:yMin
                configName: qsTr("Min T")
                configValue: "0"
                onEditFinished: axisConfigContainer.changeYAxisScale();
            }
            ICIMMLabelLineEdit{
                id:yMax
                configName: qsTr("Max T")
                configValue: "600"
                onEditFinished: axisConfigContainer.changeYAxisScale();
            }
            ICIMMLabelLineEdit{
                id:yStep
                configName: qsTr("Y Step")
                configValue: "100"
                onEditFinished: axisConfigContainer.changeYAxisScale();
            }
            ICIMMLabelLineEdit{
                id:xStep
                configName: qsTr("Time Range")
                configValue: "20"
                unit: qsTr("Min")
            }
        }

        ICTemperatureCurve {
            id: temperatureCurve
            width: parent.width
            height: parent.height
            color:parent.color
            titleFont.pixelSize: 10
            axisFont.pixelSize:9
            //        xAxisTitle: qsTr("Time[hh:mm:ss]")
            yAxisTitle:qsTr("Temperature°C")
            canvasBackground:"#242424"
            majColor:"white"
            startUpTime: Utils.formatDate(new Date, "hh:mm:ss")

            xAxisTimeScaleEn:true
            timeRange:20
            curveVisible:"00100000"
            Component.onCompleted: {
                setYAxisScale(0, 600, 100);
            }

        }
        ICIMMButton{
            id:zoomInBtn
            text: qsTr("ZoomIn")
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 10
            x: 4
            width: 50
            onButtonClicked: {
                if(!temperatureCurveContainer.isZoomIn)
                    temperatureCurveContainer.zoomIn();
                else
                    temperatureCurveContainer.zoomOut();
            }
        }
    }
}

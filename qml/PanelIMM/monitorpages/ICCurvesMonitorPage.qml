import QtQuick 1.1
import "../../ICCustomElement"
import "../immcustomitems"
import "../../utils/utils.js" as Utils
import "../main.js" as Main

Rectangle {
    id:instance
    color: "transparent"
    ICStackContainer{
        id:container
        x:2
        y:2
        width: parent.width - x * 2
        height: parent.height - y * 2
        property string color: "transparent"
        ICIMMTemperatureCurves{
            id:tempCurves
            color:instance.color
        }
        ICIMMInjectCurves{
            id:injectCurves
            color: instance.color
        }

        Component.onCompleted: {
            addPage(injectCurves);
            addPage(tempCurves);
            setCurrentIndex(0);
        }
    }
    ICIMMButton{
        id:zoomInBtn
        text: "+"
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        x: 4
        width: 30
        onButtonClicked: {
            if(!container.currentPage().isZoomIn){
                container.currentPage().zoomIn(Main.mainWindow);
                zoomInBtn.parent = container.currentPage();
            }
            else{
                container.currentPage().zoomOut(container);
                zoomInBtn.parent = instance;
            }
        }
    }
}

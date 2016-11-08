import QtQuick 1.1
import "../../ICCustomElement"
import "../immcustomitems"
import "ICCraftsLog.js" as CraftsLog
import "../main.js" as Main

Rectangle {
    id:instance
    Rectangle{
        id:monitorContainer
        width: parent.width
        height: parent.height
        color:parent.color
        property bool isZoomIn: false

        function zoomIn(){
            monitorContainer.parent = Main.mainWindow;
            width = Main.mainWindow.width;
            height = width * 0.55;
            zoomInBtn.text = "-";
            isZoomIn = true;
            hLogTime.boxVisible = true;
            hCycleTime.boxVisible = true;
            hInjEnd.boxVisible = true;
            hInjTime.boxVisible = true;
            hHoldEnd.boxVisible = true;
            hChargeEnd.boxVisible = true;
            hOMEnd.boxVisible = true;
        }

        function zoomOut(){
            monitorContainer.parent = instance;
            width = parent.width;
            height = parent.height;
            isZoomIn = false;
            zoomInBtn.text = "+";
            hLogTime.boxVisible = false;
            hCycleTime.boxVisible = false;
            hInjEnd.boxVisible = false;
            hInjTime.boxVisible = false;
            hHoldEnd.boxVisible = false;
            hChargeEnd.boxVisible = false;
            hOMEnd.boxVisible = false;

        }

        ListModel{
            id:logModel
        }

        Row{
            id:viewHeader
            x:1
            y:1
            ICIMMTableViewHeaderItem{
                id:hLogTime
                text:qsTr("LOG.TIME")
            }
            ICIMMTableViewHeaderItem{
                id:hCycleTime
                text:qsTr("CYC.TIME")
            }
            ICIMMTableViewHeaderItem{
                id:hInjEnd
                text: qsTr("INJ.END")
            }
            ICIMMTableViewHeaderItem{
                id:hInjTime
                text:qsTr("INJ.TIME")
            }
            ICIMMTableViewHeaderItem{
                id:hHoldEnd
                text:qsTr("HOLD.END")
            }
            ICIMMTableViewHeaderItem{
                id:hChargeEnd
                text:qsTr("CHARGE.END")
            }
            ICIMMTableViewHeaderItem{
                id:hOMEnd
                text:qsTr("OM.END")
            }
        }
        ICIMMButton{
            id:zoomInBtn
            text: "+"
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 10
            x: 4
            width: 30
            z:10
            onButtonClicked: {
                if(!monitorContainer.isZoomIn)
                    monitorContainer.zoomIn();
                else
                    monitorContainer.zoomOut();
            }
        }

        ICListView{
            id:view
            width: parent.width
            height: parent.height - viewHeader.height
            anchors.top: viewHeader.bottom
            x:viewHeader.x
            delegate: Row{
                ICIMMLabel{
                    text:logTime
                    border.width: 1
                    border.color: "black"
                    width: hLogTime.width
                }
                ICIMMLabel{
                    text:cycleTime
                    border.width: 1
                    border.color: "black"
                    width: hCycleTime.width
                }
                ICIMMLabel{
                    text: injEnd
                    border.width: 1
                    border.color: "black"
                    width:hInjEnd.width
                }
                ICIMMLabel{
                    text:injTime
                    border.width: 1
                    border.color: "black"
                    width: hInjTime.width
                }
                ICIMMLabel{
                    text:holdEnd
                    border.width: 1
                    border.color: "black"
                    width: hHoldEnd.width
                }
                ICIMMLabel{
                    text:chargeEnd
                    border.width: 1
                    border.color: "black"
                    width: hChargeEnd.width
                }
                ICIMMLabel{
                    text:omEnd
                    border.width: 1
                    border.color: "black"
                    width: hOMEnd.width
                }

            }
        }
        Component.onCompleted: {
            var logs = CraftsLog.craftsLog.getLogs();
            for(var i = 0, len = logs.length; i < len; ++i){
                logModel.append(logs[i]);
            }
        }
    }
}

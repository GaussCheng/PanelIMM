import QtQuick 1.1
import "."
import "../ShareData.js" as ShareData
import "ICOperationLog.js" as ICOperationLog
import "../../ICCustomElement"
import "../../styles/style.js" as Style

Rectangle {
    id:container
    property int textOffset: 2

    color: "#d1d1d1"

    function onUserChanged(user){
        ICOperationLog.opLog.currentUser =  user.user;
    }

    ListModel{
        id:operationLogModel
    }

    Row{
        id:header
        anchors.horizontalCenter: parent.horizontalCenter
        y:6
        z:2
        ICLabel{
            id:hOpTime
            border.width: 1
            border.color: "gray"
            width: 150 * Style.wRatio
            height: 32
            text: qsTr("Operation Time")
            horizontalAlignment: Text.AlignLeft
            horizontalTextOffset: textOffset
            font.pixelSize: Style.itemStyles.defaultFont.pixelSize
        }
        ICLabel{
            id:hUser
            border.width: hOpTime.border.width
            border.color: hOpTime.border.color
            width: 80 * Style.wRatio
            height: hOpTime.height
            text: qsTr("User")
            horizontalAlignment: Text.AlignLeft
            horizontalTextOffset: textOffset
            font.pixelSize: Style.itemStyles.defaultFont.pixelSize
        }
        ICLabel{
            id:hDescr
            border.width: hOpTime.border.width
            border.color: hOpTime.border.color
            width: container.width - hOpTime.width - hUser.width
            height: hOpTime.height
            text: qsTr("Descr")
            horizontalAlignment: Text.AlignLeft
            horizontalTextOffset: textOffset
            font.pixelSize: Style.itemStyles.defaultFont.pixelSize
        }
    }

    ListView{
        id:logView
        anchors.top: header.bottom
        model: operationLogModel
        x:header.x
        width: header.width + 1
        height: {
            var cH = container.height - header.height - header.y * 2;
            var mH = header.height * operationLogModel.count;
            return Math.min(cH, mH) + 5;
        }
        clip: true
        delegate: Row{
            Rectangle{
                border.width: hOpTime.border.width
                border.color: hOpTime.border.color
                width: hOpTime.width
                height: hOpTime.height
                Text {
                    text: opTime
                    verticalAlignment: Text.AlignVCenter
                    height: parent.height
                    x:textOffset
                    font.pixelSize: hOpTime.font.pixelSize
                }
            }
            Rectangle{
                border.width: hOpTime.border.width
                border.color: hOpTime.border.color
                width: hUser.width
                height: hUser.height
                Text {
                    text: user
                    verticalAlignment: Text.AlignVCenter
                    height: parent.height
                    x:textOffset
                    font.pixelSize: hUser.font.pixelSize

                }
            }
            Rectangle{
                border.width: hOpTime.border.width
                border.color: hOpTime.border.color
                width: hDescr.width
                height: hDescr.height
                Text {
                    text:descr
                    verticalAlignment: Text.AlignVCenter
                    height: parent.height
                    x:textOffset
                    font.pixelSize: hDescr.font.pixelSize
                }
            }
        }
    }


    Component.onCompleted: {
        ICOperationLog.opLog.mapViewModel(operationLogModel);
        ShareData.UserInfo.registUserChangeEvent(container);
    }
}

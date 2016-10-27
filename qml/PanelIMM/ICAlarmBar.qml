import QtQuick 1.1
import "../ICCustomElement"
import "configs/AlarmInfo.js" as AlarmInfo
import "../utils/Storage.js" as Storage
import "immcustomitems"

Rectangle {
    id:container
    border.width: 2
    border.color: "red"
    color: "yellow"
    property variant errID: []
    property bool isShrinked: false
    property bool isUP: false
    property int  extentWidth: 0
    visible: errID.length !== 0
    Row{
        id:errTextContainer
        height: parent.height - parent.parent.border.width * 6
        anchors.verticalCenter : parent.verticalCenter
        spacing: 4
//        Text {
//            id:
////            width: 90
//            font.pixelSize: 20
//            text: "Err" + errID + ":"
//            anchors.verticalCenter: parent.verticalCenter
//            color: "red"
//        }
        Text{
            id:descr
            width:extentWidth - shrink.width
            font.pixelSize: 24
            anchors.verticalCenter: parent.verticalCenter
            color: "red"
            text: {
                var err = "";
                var errs = errID;
                for(var i = 0, len = errs.length; i < len; ++i){
                    err += "Err" + errID[i].alarmNum + ":" + AlarmInfo.getAlarmDescr(errID[i].alarmNum) + '\n';
                }
                err = err.slice(0, err.length - 2);
                container.height = Math.max(font.pixelSize * errs.length, shrink.height) + container.border.width;
                return err;
            }
//            elide: Text.ElideRight
        }
//        ICButton{
//            id:details
//            text: qsTr("i")
//            height: 40
//            width: 40
//            onButtonClicked: {
//                if(!isUP){
//                    shAnimation.start();
//                    //                    alarmDetail.visible = true;
//                }else{
//                    exAnimation.start();
//                }
//                isUP = !isUP;
//            }
//        }

    }
    ICIMMButton{
        id:shrink
        text: ">>"
        width: 54
        height: 40
        icon: "images/alarm.png"
        iconPos: 1
//        bgColor: "gray"
        onButtonClicked: {
            if(!isShrinked){
                errTextContainer.visible = false;
                shrinkAnimation.start();
                text = "<<";
            }else{
                errTextContainer.visible = true;
                extentAnimation.start();
                text = ">>"
            }
            isShrinked = !isShrinked;
        }
        anchors.right: parent.right
        anchors.rightMargin: parent.border.width
        anchors.verticalCenter : parent.verticalCenter

    }

    SequentialAnimation{
        id: flicker
        loops: 6
        PropertyAnimation{ target: container;properties: "color";to:"red";duration: 200}
        PropertyAnimation{ target: container;properties: "color";to:"yellow";duration: 200}
    }
    ParallelAnimation{
        id:shrinkAnimation;
        PropertyAnimation{ target: container; properties: "x"; to:container.extentWidth - shrink.width; duration: 100}
        PropertyAnimation{ target: container; properties: "width"; to:shrink.width;duration: 100}
        PropertyAction{ target: shrink; properties: "bgColor"; value:"yellow"}
    }
    ParallelAnimation{
        id:extentAnimation;
        PropertyAnimation{ target: container; properties: "x"; to:1; duration: 100}
        PropertyAnimation{ target: container; properties: "width"; to:container.extentWidth;duration: 100}
        PropertyAction{ target: shrink; properties: "bgColor"; value:"white"}
    }

    SequentialAnimation{
        id:shAnimation;
        PropertyAction{ target: alarmDetail; properties: "visible"; value:true;}
        ParallelAnimation{
            PropertyAnimation{ target: alarmDetail; properties: "y"; to:-alarmDetail.toShowHeight; duration: alarmDetail.toShowDuration}
            PropertyAnimation{ target: alarmDetail; properties: "height"; to:alarmDetail.toShowHeight;duration: alarmDetail.toShowDuration}
        }
    }

    SequentialAnimation{
        id: exAnimation
        ParallelAnimation{
            PropertyAnimation{ target: alarmDetail; properties: "y"; to:0; duration: alarmDetail.toShowDuration}
            PropertyAnimation{ target: alarmDetail; properties: "height"; to:0;duration: alarmDetail.toShowDuration}
        }
        PropertyAction{ target: alarmDetail; properties: "visible"; value:false}
    }

    Rectangle{
        id:alarmDetail
        property int toShowHeight: content.height + 20
        property int toShowDuration: 150
        x:50
        border.color: "black"
        width: 700
        color: "#A0A0F0"
        visible: false
        clip: true
        Column{
            id:content
            Text{
                id:customdescrb
                width:640
                font.pixelSize:20
                color: "red"
                text: "Err" + errID + ":" + AlarmInfo.getAlarmDescr(errID)

            }

            Text{
                id:detail
                width:640
                font.pixelSize: 20
                color: "red"
//                text: AlarmInfo.getAlarmDetail(errID)
                wrapMode: Text.Wrap
            }
        }
    }

    onVisibleChanged: {
        if(visible){
            flicker.start();
        }
    }
}

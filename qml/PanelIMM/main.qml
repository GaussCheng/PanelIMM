import QtQuick 1.1
import "."
import "../ICCustomElement"
import "immcustomitems"
import "monitorpages"
import "../utils/utils.js" as Utils
import "../utils/Storage.js" as Storage
import "../styles/style.js" as Style
import "main.js" as PData

Rectangle {
    id:mainWindow
    width: Style.mainWindow.rect.width
    height: Style.mainWindow.rect.height

    function changeTip(tip){
        range.text = tip;
    }

    Rectangle{
        id:monitorSection
        width: Style.monitorSection.rect.width
        height: Style.monitorSection.rect.height
        color: Style.monitorSection.bg
        Row{
            Column{
                id:convenientMonitorSection
                Rectangle{
                    id:convenientMonitorSectionHeader
                    width: Style.monitorSection.header.rect.width
                    height: Style.monitorSection.header.rect.height >> 1
                    color: Style.monitorSection.header.bg
                    ICTimeLable{
                        id:timeLabel
                        anchors.right: parent.right
                        form: "yyyy/MM/dd hh:mm:ss"
                        width: parent.width * 0.40
                        //                        height: parent.height
                        font.pixelSize: Style.monitorSection.header.convenientMonitorSection.time.font.pixelSize
                        anchors.bottom: parent.bottom
                    }
                    Image{
                        source: "images/convenientMonitorSectionHeader.png"
                        width: parent.width * 0.60
                        height: parent.height
                        smooth: true
                        Text {
                            id: convenientMonitorTitle
                            anchors.verticalCenter: parent.verticalCenter
                            text: qsTr("Main Spec")
                            x:20
                            font.pixelSize: Style.monitorSection.header.convenientMonitorSection.title.font.pixelSize
                        }
                    }
                }
                ICIMMFrame{
                    width: convenientMonitorSectionHeader.width
                    height: monitorSection.height - convenientMonitorSectionHeader.height
                    ICStackContainer{
                        id:convenientMonitorPagesContainer
                        width: parent.width
                        height: parent.height
                    }
                }
            }
            Column{
                id:normalMonitorSection
                function showNormalMonitorPage(menuItem){
                    normalMonitorTitle.text = menuItem.text
                }

                Rectangle{
                    id:normalMonitorSectionHeader
                    width: Style.monitorSection.header.rect.width
                    height: Style.monitorSection.header.rect.height
                    color: Style.monitorSection.header.bg
                    ICLabel{
                        id:normalMonitorTitle
                        width: Style.monitorSection.header.normalMonitorSection.normalMonitorTitleWidth
                        height: parent.height
                        color: Style.monitorSection.header.normalMonitorSection.normalMonitorTitleBG
                        border.width: 1
                        border.color: Style.monitorSection.header.normalMonitorSection.normalMonitorTitleBorderColor
                        font.bold: true
                        font.pixelSize: Style.monitorSection.header.normalMonitorSection.normalMonitorTitleFontPixelSize

                    }
                    Grid{
                        anchors.left: normalMonitorTitle.right
                        rows: 2
                        columns: 2
                        width: parent.width - normalMonitorTitle.width
                        ICLabel{
                            text: qsTr("Mold")
                            width: rangeTitle.width
                            height: moldName.height
                            color: Style.monitorSection.header.bg
                            border.width: 1
                            border.color: Style.monitorSection.header.normalMonitorSection.normalMonitorTitleBorderColor
                        }
                        ICLabel{
                            id:moldName
                            text: panelController.currentRecordName()
                            width: range.width
                            height: normalMonitorTitle.height >> 1
                            color: Style.monitorSection.header.bg
                            border.width: 1
                            border.color: Style.monitorSection.header.normalMonitorSection.normalMonitorTitleBorderColor
                            function onMoldChanged(){
                                moldName.text = panelController.currentRecordName();
                            }
                        }
                        ICLabel{
                            id:rangeTitle
                            text: qsTr("Range")
                            height: moldName.height
                            color: Style.monitorSection.header.bg
                            border.width: 1
                            border.color: Style.monitorSection.header.normalMonitorSection.normalMonitorTitleBorderColor
                        }
                        ICLabel{
                            id:range
                            text: "1 - 20"
                            height: moldName.height
                            color: Style.monitorSection.header.bg
                            width: parent.width -  rangeTitle.width - 1
                            border.width: 1
                            border.color: Style.monitorSection.header.normalMonitorSection.normalMonitorTitleBorderColor
                        }
                    }
                }
                ICIMMFrame{
                    width: normalMonitorSectionHeader.width - 1
                    height: monitorSection.height - normalMonitorSectionHeader.height
                    ICStackContainer{
                        id:normalMonitorPagesContainer
                        width: parent.width
                        height: parent.height
                    }
                }
            }
        }
    }

    ICIMMFrame{
        id:detailPagesSection
        color: detailMenuSection.color
        width: detailMenuSection.width - 1
        anchors.top: monitorSection.bottom
        anchors.topMargin: -1
        anchors.bottom: detailMenuSection.top
        anchors.bottomMargin: 1
        ICStackContainer{
            id:detailPagesContainer
            anchors.fill: parent
        }
    }


    Rectangle{
        id:detailMenuSection
        anchors.bottom: touchControlSection.top
        width: Style.detailMenuSection.rect.width
        height: Style.detailMenuSection.rect.height
        color: Style.detailMenuSection.bg
        property alias f1Text: dMI1.text
        property alias f2Text: dMI2.text
        property alias f3Text: dMI3.text
        property alias f4Text: dMI4.text
        property alias f5Text: dMI5.text
        property alias f6Text: dMI6.text
        property alias f7Text: dMI7.text
        property alias f8Text: dMI8.text

        property variant baseMenuItems: [
            "f1" + " " + qsTr("Linked C"),
            "f2" + " " + qsTr("Curves"),
            "f3" + " " + qsTr("determine"),
            "f4" + " " + qsTr("Servo"),
            "f5" + " " + qsTr("OP Log"),
            "","",""
        ]

        function refreshMenuItem(menuItems){
            var f;
            for(var i = 1; i < 9; ++i){
                f = "f" + i;
                if(menuItems.hasOwnProperty(f)){
                    detailMenuSection[f + "Text"] = f + " " + menuItems[f];
                }else{
                    detailMenuSection[f + "Text"] = baseMenuItems[i - 1]
                }
            }
        }

        function onF1Triggered(){
            console.log("onF1Triggered")
        }
        function onF2Triggered(){
            console.log("onF2Triggered")

        }
        function onF3Triggered(){
            console.log("onF3Triggered")

        }
        function onF4Triggered(){
            console.log("onF4Triggered")

        }
        function onF5Triggered(){
            return "ICOperationLogPage.qml"

        }
        function onF6Triggered(){
            console.log("onF6Triggered")

        }
        function onF7Triggered(){
            console.log("onF7Triggered")
        }
        function onF8Triggered(){
            console.log("onF8Triggered")
        }
        function onF9Triggered(){
            return "ICMainSpecMonitorPage.qml"
        }

        ICButtonGroup{
            spacing: 1
            mustChecked: true
            onButtonClickedID: {
                var p  = detailPagesContainer.currentPage();
                if(p.hasOwnProperty("onF" + (index + 1) + "Triggered"))
                    PData.convenientMonitorManager.showMonitor(p["onF" + (index + 1) + "Triggered"]());
                else
                    PData.convenientMonitorManager.showMonitor(detailMenuSection["onF" + (index + 1) + "Triggered"]());
                convenientMonitorTitle.text = checkedItem.text.slice(3);
            }
            ICIMMDetailMenuItem{
                id:dMI1
                width: Style.detailMenuSection.rect.width / 8 - 1
                height: Style.detailMenuSection.rect.height
                font.pixelSize: Style.detailMenuSection.menuItem.font.pixelSize
                text: detailMenuSection.baseMenuItems[0]
            }
            ICIMMDetailMenuItem{
                id:dMI2
                width: dMI1.width
                height: dMI1.height
                font.pixelSize: Style.detailMenuSection.menuItem.font.pixelSize
                text: detailMenuSection.baseMenuItems[1]
            }
            ICIMMDetailMenuItem{
                id:dMI3
                width: dMI1.width
                height: dMI1.height
                font.pixelSize: Style.detailMenuSection.menuItem.font.pixelSize
                text: detailMenuSection.baseMenuItems[2]
            }
            ICIMMDetailMenuItem{
                id:dMI4
                width: dMI1.width
                height: dMI1.height
                font.pixelSize: Style.detailMenuSection.menuItem.font.pixelSize
                text: detailMenuSection.baseMenuItems[3]
            }
            ICIMMDetailMenuItem{
                id:dMI5
                width: dMI1.width
                height: dMI1.height
                font.pixelSize: Style.detailMenuSection.menuItem.font.pixelSize
                text: detailMenuSection.baseMenuItems[4]
            }
            ICIMMDetailMenuItem{
                id:dMI6
                width: dMI1.width
                height: dMI1.height
                font.pixelSize: Style.detailMenuSection.menuItem.font.pixelSize
            }
            ICIMMDetailMenuItem{
                id:dMI7
                width: dMI1.width
                height: dMI1.height
                font.pixelSize: Style.detailMenuSection.menuItem.font.pixelSize
            }
            ICIMMDetailMenuItem{
                id:dMI8
                width: dMI1.width
                height: dMI1.height
                font.pixelSize: Style.detailMenuSection.menuItem.font.pixelSize
            }
            ICIMMDetailMenuItem{
                id:dMI9
                visible: false
                text:"f9" + " " + qsTr("Main Spec")

            }
//            Component.onCompleted: {
//                reLayout();
//            }
        }
    }
    ICTouchControlSection{
        id:touchControlSection
        anchors.bottom: parent.bottom
        function showHelper(page){
            recordManagement.hide();
            alarmHistory.hide();
            ioPage.hide();
            if(page != null)
                page.show();
        }

        onRecordMenuItemTriggered: {
            normalMonitorSection.showNormalMonitorPage(menuItem);
            showHelper(recordManagement);
        }
        onAlarmHistoryMenuItemTriggered: {
            normalMonitorSection.showNormalMonitorPage(menuItem);
            showHelper(alarmHistory);
        }
        onIoMonitorMenuItemTriggered: {
            normalMonitorSection.showNormalMonitorPage(menuItem);
            showHelper(ioPage);
        }

        onFuncMenuItemTriggered: {
            normalMonitorSection.showNormalMonitorPage(menuItem);
            PData.funcPageManager.showNormalMonitorPage(menuItem.monitorComponent);
            var page = PData.funcPageManager.showDetailPage(menuItem.bindingPageComponent);
            dMI9.setChecked(true);
            detailMenuSection.refreshMenuItem(page.detailsMenuItems);
            showHelper(null);

        }
    }
    RecordManagementPage{
        id:recordManagement
        width: parent.width
        height: detailMenuSection.y - y + detailMenuSection.height
        y:Style.monitorSection.header.rect.height
        visible: false
        function show(){
            visible = true;
        }
        function hide(){
            visible = false;
        }
    }
    ICAlarmPage{
        id:alarmHistory
        width: parent.width
        height: detailMenuSection.y - y + detailMenuSection.height
        y:Style.monitorSection.header.rect.height
        visible: false
        function show(){
            visible = true;
        }
        function hide(){
            visible = false;
        }
    }

//    ICOperationLogPage{
//        visible: false
//    }

    IOPage{
        id:ioPage
        width: parent.width
        height: detailMenuSection.y - y + detailMenuSection.height
        y:Style.monitorSection.header.rect.height
        visible: false
        function show(){
            visible = true;
        }
        function hide(){
            visible = false;
        }
    }

    ICAlarmBar{
        id:alarmBar
        y:detailMenuSection.y - height
        width: parent.width
        extentWidth: parent.width
//        height: 64 * Style.hRatio
//        errID: 1
    }

    Component.onCompleted: {
        PData.funcPageManager.init(normalMonitorPagesContainer, detailPagesContainer, mainWindow);
        PData.convenientMonitorManager.init(convenientMonitorPagesContainer);
        panelController.moldChanged.connect(moldName.onMoldChanged);
        touchControlSection.init();
        PData.convenientMonitorManager.showMonitor(detailMenuSection.onF5Triggered());
        PData.convenientMonitorManager.showMonitor(detailMenuSection.onF9Triggered());

    }
    Timer{
        id:refreshTimer
        running: true
        repeat: true
        interval: 50
        onTriggered: {
            var alams = panelController.alarms();
            if(alams != alarmHistory.errs){
                alarmHistory.errs = alams;
                alarmBar.errID = alarmHistory.unResolvedAlarms;
            }
        }
    }
}


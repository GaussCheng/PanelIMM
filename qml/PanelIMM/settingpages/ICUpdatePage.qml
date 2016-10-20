import QtQuick 1.1
import '..'
import "../../ICCustomElement"
import "../immcustomitems"
import "../../styles/style.js" as Style


ICSettingConfigsScope{
    id:maintainPage
    Column{
        spacing: 4
        x:4
        y:2
        Row{
            id:versionContainer
            ICIMMText {
                text: qsTr("UI Version:") + "IMM-1.0.0" + ";"
            }
            ICIMMText {
                id:hostVersion
            }
            onVisibleChanged: {
                if(visible)
                    hostVersion.text = qsTr("Controller Version:") + panelController.controllerVersion();
            }
        }

        ICButtonGroup{
            spacing: 24
            mustChecked: true
            checkedIndex: 0
            ICIMMCheckBoxEdit{
                id:update
                text: qsTr("Update")
                isChecked: true
            }
            ICIMMCheckBoxEdit{
                id:backupRestore
                text: qsTr("Backup/Restore")
                onIsCheckedChanged: {
                    if(isChecked)
                        backupRestoreContainer.source = "DataManagePage.qml";
                }
            }
        }
        Rectangle{
            id:splitLine
            height: 1
            width: maintainPage.width - parent.x * 2
            color: "black"
        }

        Row{
            id:updateContainer
            spacing: 6
            visible: !backupRestore.isChecked
            Rectangle{
                id:listViewContainer
                width: splitLine.width - scanUpdater.width - parent.spacing
                height: maintainPage.height - update.height - splitLine.height - versionContainer.height - 20
                ListModel{
                    id:updaterModel
                }

                ListView{
                    id:updaterView
                    width: parent.width
                    height: parent.height
                    model: updaterModel
                    clip: true
                    delegate: Rectangle{
                        width: parent.width
                        height: 32
                        border.width: 1
                        border.color: "black"
                        color: updaterView.currentIndex == index ? "lightsteelblue" : "white"

                        ICIMMText{
                            text: name
                            anchors.verticalCenter: parent.verticalCenter
                        }
                        MouseArea{
                            anchors.fill: parent
                            onClicked: {
                                updaterView.currentIndex = index;
                            }
                        }
                    }
                }
            }
            Column{
                spacing: 6
                ICIMMButton{
                    id:scanUpdater
                    text: qsTr("Scan Updater")
                    width: 150
                    height: 32
                    onButtonClicked: {
                        var updatersJSON = panelController.scanUSBUpdaters("HCRobot");

                        var upaaters = JSON.parse(updatersJSON);
                        updaterModel.clear();
                        for(var i = 0; i < upaaters.length; ++i){
                            updaterModel.append({"name":upaaters[i]});
                        }
                    }
                }
                ICIMMButton{
                    id:startUpdate
                    text: qsTr("Start Update")
                    width: 150
                    height: 32
                    onButtonClicked: {
                        var name = updaterModel.get(updaterView.currentIndex).name;
                        panelController.backupUpdater(name)
                        panelController.startUpdate(name);
                    }
                }

            }
        }

        Loader{
            id:backupRestoreContainer
            visible: backupRestore.isChecked
            width: updateContainer.width
            height: updateContainer.height
        }
    }
}

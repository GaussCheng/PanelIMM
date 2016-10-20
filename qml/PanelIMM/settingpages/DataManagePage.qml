import QtQuick 1.1
import "../../ICCustomElement"
import "../../utils/Storage.js" as Storage
import "../../utils/stringhelper.js" as ICString
import "../immcustomitems"
import "../../styles/style.js" as Style

Item {
    id:container
    ICMessageBox{
        id:backupNameDialog
        x:250
        y:50
        z:2
        onAccept: {
            tip.runningTip(qsTr("Backup..."));
            var backupName = inputText;
            if(hmiConfigs.isChecked){
                panelController.backupHMIBackup(backupName, Storage.backup());
            }else if(machineRunningConfigs.isChecked){
                panelController.backupMRBackup(backupName);
            }else if(ghost.isChecked){
                panelController.makeGhost(backupName, Storage.backup());
            }
            refreshDataModel();
            tip.hide();
        }
    }

    ICMessageBox{
        id:tip
        x:250
        y:50
        z:3
    }

    ICMessageBox{
        id:restoreTip
        x:250
        y:50
        z:2
        onAccept: {
            tip.runningTip(qsTr("Restoring..."));
            var backupName = backuViews.model.get(backuViews.currentIndex).name;
            var mode = local.isChecked ? 0 : 1;
            if(hmiConfigs.isChecked){
                var sqlData = panelController.restoreHMIBackup(backupName, mode);
                if(sqlData.length == 0) return;
                Storage.restore(sqlData);

            }else if(machineRunningConfigs.isChecked){
                panelController.restoreMRBackup(backupName,mode);
            }else if(ghost.isChecked){
                Storage.restore(panelController.restoreGhost(backupName, mode));
            }
            panelController.reboot();
        }
    }

    function refreshDataModel(){
        if(local.isChecked){
            if(hmiConfigs.isChecked){
                localHMIBackupModel.syncModel();
                backuViews.model = localHMIBackupModel;
            }else if(machineRunningConfigs.isChecked){
                localMachineBackupModel.syncModel();
                backuViews.model = localMachineBackupModel;
            }else if(ghost.isChecked){
                localGhostModel.syncModel();
                backuViews.model = localGhostModel;
            }else if(updater.isChecked){
                localUpdaterModel.syncModel();
                backuViews.model = localUpdaterModel;
            }
        }else if(uDisk.isChecked){
            if(hmiConfigs.isChecked){
                uDiskHMIBackupModel.syncModel();
                backuViews.model = uDiskHMIBackupModel;
            }else if(machineRunningConfigs.isChecked){
                uDiskMachineBackupModel.syncModel();
                backuViews.model = uDiskMachineBackupModel;
            }else if(ghost.isChecked){
                uDiskGhostModel.syncModel();
                backuViews.model = uDiskGhostModel;
            }else if(updater.isChecked){
                uDiskUpdaterModel.syncModel();
                backuViews.model = uDiskUpdaterModel;
            }
        }
        backuViews.currentIndex = -1;
    }

    Column{
        spacing: 6
        ICButtonGroup{
            spacing: 24
            checkedItem: local
            checkedIndex: 0
            mustChecked: true
            ICIMMCheckBoxEdit{
                id:local
                text: qsTr("Local")
                isChecked: true
            }
            ICIMMCheckBoxEdit{
                id:uDisk
                text: qsTr("U Disk")
            }
            onButtonClickedItem: {
                refreshDataModel();
            }
        }
        ICButtonGroup{
            spacing: 24
            checkedItem: machineRunningConfigs
            checkedIndex: 0
            mustChecked: true
            ICIMMCheckBoxEdit{
                id:machineRunningConfigs
                text: qsTr("Machine Running")
                isChecked: true
            }
            ICIMMCheckBoxEdit{
                id:hmiConfigs
                text: qsTr("HMI Configs")
            }
            ICIMMCheckBoxEdit{
                id:ghost
                text: qsTr("ghost")
            }
            ICIMMCheckBoxEdit{
                id:updater
                text: qsTr("Updater")
            }

            onButtonClickedItem: {
                refreshDataModel();
            }
        }
        Row{
            spacing: 12
            ICListView{
                id:backuViews
                width: container.width
                height: container.height - machineRunningConfigs.height - local.height - 12
                isShowHint: true
                border.color: "black"
                color: "white"
                clip: true
                highlight: Rectangle {width: 596; height: 24;color: "lightsteelblue";}
                highlightMoveDuration:100
                delegate: Text {
                    text: name
                    width: 596
                    height: 24
                    verticalAlignment: Text.AlignVCenter
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            backuViews.currentIndex = index;
                        }
                    }
                }
                ListModel{
                    id:localMachineBackupModel
                    function syncModel(){
                        localMachineBackupModel.clear();
                        var backups = JSON.parse(ICString.utf8ToUtf16(panelController.scanMachineBackups(0)));
                        for(var i = 0, len = backups.length; i < len; ++i){
                            localMachineBackupModel.append({"name":backups[i]});
                        }
                    }

                }
                ListModel{
                    id:localHMIBackupModel
                    function syncModel(){
                        localHMIBackupModel.clear();
                        var backups = JSON.parse(ICString.utf8ToUtf16(panelController.scanHMIBackups(0)));
                        for(var i = 0, len = backups.length; i < len; ++i){
                            localHMIBackupModel.append({"name":backups[i]});
                        }
                    }
                }
                ListModel{
                    id:localGhostModel
                    function syncModel(){
                        localGhostModel.clear();
                        var backups = JSON.parse(ICString.utf8ToUtf16(panelController.scanGhostBackups(0)));
                        for(var i = 0, len = backups.length; i < len; ++i){
                            localGhostModel.append({"name":backups[i]});
                        }
                    }
                }
                ListModel{
                    id:localUpdaterModel
                    function syncModel(){
                        localUpdaterModel.clear();
                        var updatersJSON = panelController.scanUpdaters("HCRobot", 0);
                        var updaters = JSON.parse(updatersJSON);
                        for(var i = 0, len = updaters.length; i < len; ++i){
                            localUpdaterModel.append({"name":updaters[i]});
                        }
                    }
                }

                ListModel{
                    id:uDiskMachineBackupModel
                    function syncModel(){
                        uDiskMachineBackupModel.clear();
                        var backups = JSON.parse(ICString.utf8ToUtf16(panelController.scanMachineBackups(1)));
                        for(var i = 0, len = backups.length; i < len; ++i){
                            uDiskMachineBackupModel.append({"name":backups[i]});
                        }
                    }
                }
                ListModel{
                    id:uDiskHMIBackupModel
                    function syncModel(){
                        uDiskHMIBackupModel.clear();
                        var backups = JSON.parse(ICString.utf8ToUtf16(panelController.scanHMIBackups(1)));
                        for(var i = 0, len = backups.length; i < len; ++i){
                            uDiskHMIBackupModel.append({"name":backups[i]});
                        }
                    }
                }
                ListModel{
                    id:uDiskGhostModel
                    function syncModel(){
                        uDiskGhostModel.clear();
                        var backups = JSON.parse(ICString.utf8ToUtf16(panelController.scanGhostBackups(1)));
                        for(var i = 0, len = backups.length; i < len; ++i){
                            uDiskGhostModel.append({"name":backups[i]});
                        }
                    }
                }
                ListModel{
                    id:uDiskUpdaterModel
                    function syncModel(){
                        uDiskUpdaterModel.clear();
                        var updatersJSON = panelController.scanUpdaters("HCRobot", 1);
                        var updaters = JSON.parse(updatersJSON);
                        for(var i = 0, len = updaters.length; i < len; ++i){
                            uDiskUpdaterModel.append({"name":updaters[i]});
                        }
                    }
                }
            }
            Column{
                ICIMMButton{
                    id:newBackup
                    width: 150
                    text: qsTr("Backup Current")
                    enabled: local.isChecked && !updater.isChecked
                    onButtonClicked: {
                        backupNameDialog.showInput(qsTr("Please input the backup name"),
                                                   qsTr("Backup Name"),
                                                   false,
                                                   qsTr("Ok"), qsTr("Cancel"));
                    }
                }
                ICIMMButton{
                    id:restore
                    width: newBackup.width
                    text: qsTr("Restore Selected")
                    enabled: !updater.isChecked
                    onButtonClicked: {
                        if(backuViews.currentIndex < 0) return;
                        restoreTip.show(qsTr("System will reboot after restore! Are you sure?"), qsTr("OK"), qsTr("Cancel"));
                    }
                }
                ICIMMButton{
                    id:deleteBackup
                    width: newBackup.width
                    text: qsTr("Delete")
                    onButtonClicked: {
                        var mode = local.isChecked ? 0 : 1;
                        var backupName = backuViews.model.get(backuViews.currentIndex).name;
                        if(hmiConfigs.isChecked){
                            panelController.deleteHIMBackup(backupName, mode);
                        }else if(machineRunningConfigs.isChecked){
                            panelController.deleteMRBackup(backupName, mode);
                        }else if(ghost.isChecked){
                            panelController.deleteGhost(backupName, mode);
                        }else if(updater.isChecked){
                            panelController.deleteUpdater(backupName, mode);
                        }

                        backuViews.model.remove(backuViews.currentIndex);
                    }
                }

                ICIMMButton{
                    id:exportOrImport
                    width: newBackup.width
                    text: qsTr("Export")
                    enabled: local.isChecked
                    onButtonClicked: {
                        var ret = 0;
                        if(backuViews.currentIndex < 0) return;
                        tip.runningTip(qsTr("Exporting..."))
                        var backupName = backuViews.model.get(backuViews.currentIndex).name;
                        if(hmiConfigs.isChecked){
                            ret = panelController.exportHMIBackup(backupName);
                        }else if(machineRunningConfigs.isChecked){
                            ret = panelController.exportMachineBackup(backupName);
                        }else if(ghost.isChecked){
                            ret = panelController.exportGhost(backupName);
                        }else if(updater.isChecked){
                            ret = panelController.exportUpdater(backupName);
                        }
                        tip.hide();

                        if(ret !== 0){
                            tip.warning(qsTr("Export fail! Err" + ret), qsTr("OK"));
                        }else{
                            tip.information(qsTr("Export successfully!"), qsTr("OK"));
                        }
                    }
                }
                ICIMMButton{
                    id:startUpdate
                    width: newBackup.width
                    text: qsTr("Start Update")
                    enabled: updater.isChecked
                    onButtonClicked: {
                        var name = backuViews.model.get(backuViews.currentIndex).name;
                        if(uDisk.isChecked)
                            panelController.backupUpdater(name)
                        panelController.startUpdate(name, uDisk.isChecked ? 0 : 1);
                    }
                }
            }
        }
    }
    Component.onCompleted: {
        refreshDataModel();
    }
}

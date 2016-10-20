import QtQuick 1.1
import "../../ICCustomElement"
import "../immcustomitems"
import "../../styles/style.js" as Style
ICIMMFunctionPageBase {
    id:panelSettingsPage
    property int rowSpacing: 12 * Style.wRatio
    ICSettingPageBase{
        id:panelSettingsContainer
        width: parent.width
        height: parent.height
        visible: false
        ICIMMButton{
            id:touchCalibrate
            anchors.right: parent.right
            anchors.rightMargin: 10
            y:10
            text: qsTr("Touch Calibrate")
            width: 120 * Style.wRatio
            onButtonClicked: {
                tip.show(qsTr("Recalibrate need to reboot. Continue?"), qsTr("Yes"), qsTr("No"));
            }
        }

        ICMessageBox{
            id:tip
            z:100
            anchors.centerIn: parent
            onAccept: {
                panelController.recal();
            }
        }

        Column{
            spacing: 16
            Row{
                spacing: panelSettingsPage.rowSpacing
                Text {
                    id: languageLabel
                    text: qsTr("Language")
                    anchors.verticalCenter: parent.verticalCenter

                }
                ICButtonGroup{
                    spacing: panelSettingsPage.rowSpacing
                    mustChecked: true
                    ICIMMCheckBoxEdit{
                        id:chineseBox
                        text: "中文"
                        onClicked: {
                            if(isChecked){
                                panelController.setCustomSettings("Language", "CN");
                                panelController.setCurrentTranslator("HAMOUI_zh_CN.qm");
                            }
                        }
                    }
                    ICIMMCheckBoxEdit{
                        id:englishBox
                        text:"English"
                        onClicked: {
                            if(isChecked){
                                panelController.setCustomSettings("Language", "US");
                                panelController.setCurrentTranslator("HAMOUI_en_US.qm");
                            }
                        }
                    }
                }
            }
            Row{
                spacing: panelSettingsPage.rowSpacing
                ICIMMText {
                    id: keytoneLabel
                    text: qsTr("Key Tone")
                    anchors.verticalCenter: parent.verticalCenter

                }
                ICButtonGroup{
                    spacing: panelSettingsPage.rowSpacing
                    ICIMMCheckBoxEdit{
                        id:keyToneOff
                        text:qsTr("Key Tone Off")
                        onClicked: {
                            if(isChecked){
                                panelController.setCustomSettings("Keytone", false);

                            }
                        }
                    }
                    ICIMMCheckBoxEdit{
                        id:keyToneOn
                        text:qsTr("Key Tone On")
                        onClicked: {
                            if(isChecked){
                                panelController.setCustomSettings("Keytone", true);

                            }
                        }
                    }
                    onButtonClickedItem: {
                        panelController.setKeyTone(item == keyToneOn);
                    }
                }
            }
            Row{
                spacing: panelSettingsPage.rowSpacing
                ICIMMText {
                    id: brightnessLabel
                    text: qsTr("Brightness")
                    anchors.verticalCenter: parent.verticalCenter


                }
                ICIMMButton{
                    id:minusBrightness
                    text: qsTr("-")
                    width: height
                    height: brightness.height
                    onButtonClicked: {
                        brightness.setValue(brightness.value() - 1);
                    }
                }

                ICProgressBar{
                    id:brightness
                    progressColor: "#A0A0F0"
                    minimum: 1
                    maximum: 8
                    onValueChanged: {
                        panelController.setBrightness(brightness.value());
                        panelController.setCustomSettings("Brightness", brightness.value());
                    }
                }
                ICIMMButton{
                    id:plusBrightness
                    text: qsTr("+")
                    width: height
                    height: brightness.height
                    onButtonClicked: {
                        brightness.setValue(brightness.value() + 1);
                    }

                }

            }
            Row{
                Text {
                    id: screensaverLabel
                    text: qsTr("Screensaver Time")
                    anchors.verticalCenter: parent.verticalCenter
                }
                ICIMMLineEdit{
                    id:screensaverTime
                    unit: qsTr("min")
                    width: year.width
                    onTextChanged: {
                        panelController.setCustomSettings("ScreensaverTime", text);
                        panelController.setScreenSaverTime(text);
                    }
                }
            }

            Row{
                id:datetimeContaner
                spacing: 2
                ICIMMText {
                    id: datetimeLabel
                    text: qsTr("Date time")
                    anchors.verticalCenter: parent.verticalCenter
                }
                function setDatetime(){
                    if(Utils.isDateTimeValid(year.text,
                                             month.text,
                                             day.text,
                                             hour.text,
                                             minute.text,
                                             second.text))
                    {
                        panelController.setDatetime(year.text + "/" +
                                                    month.text + "/" +
                                                    day.text + " " +
                                                    hour.text + ":" +
                                                    minute.text + ":" +
                                                    second.text);
                    }
                }

                ICIMMLineEdit{
                    id:year
                    unit: qsTr("year")
                    width: 100 * Style.wRatio
                }
                ICIMMLineEdit{
                    id:month
                    unit: qsTr("mon")
                    width: year.width

                }
                ICIMMLineEdit{
                    id:day
                    unit: qsTr("day")
                    width: year.width

                }
                ICIMMLineEdit{
                    id:hour
                    unit: qsTr("hour")
                    width: year.width
                }
                ICIMMLineEdit{
                    id:minute
                    unit:qsTr("minute")
                    width: year.width
                }
                ICIMMLineEdit{
                    id:second
                    unit: qsTr("sec")
                    width: year.width
                }
                Connections{
                    id:yearConnection
                    target: year
                    onTextChanged:datetimeContaner.setDatetime();
                }
                Connections{
                    id:monthConnection
                    target: month
                    onTextChanged:datetimeContaner.setDatetime();
                }
                Connections{
                    id:dayConnection
                    target: day
                    onTextChanged:datetimeContaner.setDatetime();
                }
                Connections{
                    id:hourConnection
                    target: hour
                    onTextChanged:datetimeContaner.setDatetime();
                }

                Connections{
                    id:minuteConnection
                    target: minute
                    onTextChanged:datetimeContaner.setDatetime();
                }
                Connections{
                    id:secondConnection
                    target: second
                    onTextChanged:datetimeContaner.setDatetime();
                }
            }
        }


        Component.onCompleted: {
            var lang = panelController.getCustomSettings("Language", "");
            console.log("lang", lang == "");
            if(lang == ""){
                panelController.setCustomSettings("Language", "CN");
                panelController.setCurrentTranslator("HAMOUI_zh_CN.qm");
                lang = "CN";
                console.log("language", panelController.getCustomSettings("Language", ""));
            }
            if(lang == "CN"){
                chineseBox.setChecked(true);
            }else if(lang == "US"){
                englishBox.setChecked(true);
            }
            var keytone = panelController.getCustomSettings("Keytone", true);
            if(keytone == "true")
                keyToneOn.setChecked(true);
            else
                keyToneOff.setChecked(true);
            panelController.setKeyTone(keyToneOn.isChecked);


            var brightnessval = panelController.getCustomSettings("Brightness", 8);
            brightness.setValue(brightnessval);
            panelController.setBrightness(brightness.value());


            var scsT = panelController.getCustomSettings("ScreensaverTime", 5);
            screensaverTime.text = scsT;
            panelController.setScreenSaverTime(screensaverTime.text);

        }

        onVisibleChanged: {
            if(visible){
                yearConnection.target = null;
                monthConnection.target = null;
                dayConnection.target = null;
                hourConnection.target = null;
                minuteConnection.target = null;
                secondConnection.target = null;
                var currentDate = new Date();
                year.text = currentDate.getFullYear();
                month.text = currentDate.getMonth() + 1;
                day.text =  currentDate.getDate();
                hour.text = currentDate.getHours();
                minute.text = currentDate.getMinutes();
                second.text = currentDate.getSeconds();
                yearConnection.target = year;
                monthConnection.target = month;
                dayConnection.target = day;
                hourConnection.target = hour;
                minuteConnection.target = minute;
                secondConnection.target = second;
            }
        }
    }
    ICUpdatePage{
        id:updatePage
        width: parent.width
        height: parent.height
    }
}

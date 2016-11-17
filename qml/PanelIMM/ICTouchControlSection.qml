import QtQuick 1.1
import "../styles/style.js" as Style
import "../ICCustomElement"
import "immcustomitems"
import "ICTouchControlSection.js" as PData
import "configs/MacroDefine.js" as MacroDefine

Rectangle {
    id:instance
    width: Style.touchControlSection.rect.width
    height: Style.touchControlSection.rect.height
    color: Style.touchControlSection.bg
    signal funcMenuItemTriggered(variant menuItem, bool mulPage)
    signal recordMenuItemTriggered(variant menuItem)
    signal alarmHistoryMenuItemTriggered(variant menuItem)
    signal ioMonitorMenuItemTriggered(variant menuItem)
    function init(){
        funcMenuItemTriggered(workReady, false);
        funcMenuItemTriggered(mold, false);
        funcMenuItemTriggered(core, false);
        funcMenuItemTriggered(inject, false);
        funcMenuItemTriggered(carr,false);
        funcMenuItemTriggered(temperature, false);
        funcMenuItemTriggered(ioSettingsIMM, true);
        funcMenuItemTriggered(generalSpecifications, true);
        funcMenuItemTriggered(actionMonitor, false);
    }

    Image {
        id: immModeBG
        source: "images/immModeBg.png"
        smooth: true
        anchors.right: parent.right
        anchors.rightMargin: Style.touchControlSection.immModeBG.rightMargin
        anchors.top: parent.top
        anchors.topMargin: Style.touchControlSection.immModeBG.topMargin
        width: sourceSize.width * Style.wRatio
        height: sourceSize.height * Style.hRatio
        ICButtonGroup{
            id:funcMenuItemGroup
            isAutoSize: false
            anchors.fill: parent
            layoutMode: 2
            mustChecked: true
            onCheckedItemChanged: {
                if(checkedItem == recordBtn)
                    recordMenuItemTriggered(checkedItem);
                else if(checkedItem == alarmHistory)
                    alarmHistoryMenuItemTriggered(checkedItem);
                else if(checkedItem == ioMonitor)
                    ioMonitorMenuItemTriggered(checkedItem);
                else if(checkedItem == ioSettingsIMM)
                    funcMenuItemTriggered(checkedItem, true);
                else if(checkedItem == generalSpecifications)
                    funcMenuItemTriggered(checkedItem, true);
                else
                    funcMenuItemTriggered(checkedItem, false);
            }

            ICIMMFunctionMenuItem{
                id:ejector
                text: qsTr("Ejector")

                y:4 * Style.hRatio
            }

            ICIMMFunctionMenuItem{
                id:clampDevice
                text: qsTr("Clamp\nDevice")
                y:ejector.y
                x:mold.x
            }

            ICIMMFunctionMenuItem{
                id:extentTemp
                text: qsTr("Extent\nTemp")
                y:ejector.y
                anchors.left: clampDevice.right
                anchors.leftMargin: 9 * Style.wRatio
            }

            ICIMMFunctionMenuItem{
                id:zip
                text: qsTr("zip")
                y:ejector.y
                anchors.left: extentTemp.right
                anchors.leftMargin: 9 * Style.wRatio
            }

            ICIMMFunctionMenuItem{
                id:workReady
                text: qsTr("Work\nReady")
                anchors.top: ejector.bottom
                anchors.topMargin: 12 * Style.hRatio
                //                anchors.verticalCenter: parent.verticalCenter
                bindingPageComponent: "ICWorkReadyFuncPage.qml"
                monitorComponent: "ICInjectionMonitorPage.qml"
            }
            ICIMMFunctionMenuItem{
                id:mold
                text: qsTr("Mold")
                y: workReady.y
                anchors.left: workReady.right
                anchors.leftMargin: 8 * Style.wRatio
                bindingPageComponent: "ICMoldFuncPage.qml"
                monitorComponent: "ICMoldMonitorPage.qml"
            }

            ICIMMFunctionMenuItem{
                id:core
                text: qsTr("Core")
                y:workReady.y
                x:extentTemp.x
                bindingPageComponent: "ICCoreFuncPage.qml"
                monitorComponent: "ICMoldMonitorPage.qml"
            }

            ICIMMFunctionMenuItem{
                id:opDevice
                text: qsTr("OP\nDevice")
                y:workReady.y
                x:zip.x
            }

            ICIMMFunctionMenuItem{
                id:temperature
                text: qsTr("Temp")
                y:workReady.y
                anchors.left: opDevice.right
                anchors.leftMargin: 20 * Style.wRatio
                bindingPageComponent: "ICTemperatureFuncPage.qml"
                monitorComponent: "ICTemperatureMonitorPage.qml"
            }

            ICIMMFunctionMenuItem{
                id:inject
                text: qsTr("Inject")
                y:workReady.y
                anchors.left: temperature.right
                anchors.leftMargin: 12 * Style.wRatio
                bindingPageComponent: "ICInjectFuncPage.qml"
                monitorComponent: "ICInjectionMonitorPage.qml"
            }

            ICIMMFunctionMenuItem{
                id:carr
                text: qsTr("CARR")
                anchors.top: opDevice.bottom
                anchors.topMargin: 12 * Style.hRatio
                x:inject.x
                bindingPageComponent: "ICCarrFuncPage.qml"
                monitorComponent: "ICInjectionMonitorPage.qml"
            }
        }
        Item{
            id:actLedContainer
            y:parent.height * 0.6
            height: parent.height * 0.4
            Row{
                id:ledRow1
                z:2
                ICIMMLedTextLabel{
                    id:actCMLed
                    text: qsTr("C.M")
                }
                Image {
                    source: "images/arrow-Left.png"
                    anchors.verticalCenter: parent.verticalCenter
                }
                ICIMMLedTextLabel{
                    id:actNOZADVLed
                    text: qsTr("NOZ.ADV")
                }
                Image {
                    source: "images/arrow-Left.png"
                    anchors.verticalCenter: parent.verticalCenter
                }
                ICIMMLedTextLabel{
                    id:actBCHARLed
                    text: qsTr("B.CHAR")
                }
                Image {
                    source: "images/arrow-Left.png"
                    anchors.verticalCenter: parent.verticalCenter
                }
                ICIMMLedTextLabel{
                    id:actINJLed
                    text: qsTr("INJ")
                }
                Image {
                    source: "images/arrow-Left.png"
                    anchors.verticalCenter: parent.verticalCenter
                }
                ICIMMLedTextLabel{
                    id:actHPLed
                    text: qsTr("H.P")
                }
            }
            Item{
                id:ledCol1
                anchors.top: ledRow1.bottom
                x:actHPLed.x - r2.width / 2
                Rectangle{
                    id:bgContainer
                    color: "green"
                    anchors.left: actBCCOOLLed.x > actCOOLLed.x ? actCOOLLed.left : actBCCOOLLed.left
                    anchors.right: actNOZRETLed.right
                    anchors.top: r2.top
                    anchors.bottom: actCOOLLed.bottom
                }
                Image{
                    id:r2
                    source: "images/arrow-Branch.png"
                }
                ICIMMLedTextLabel{
                    id:actBCCOOLLed
                    text: qsTr("BC.COOL")
                    anchors.top:r2.bottom
//                    anchors.topMargin: -4 * Style.hRatio
                    anchors.left: r2.left
                }
                ICIMMLedTextLabel{
                    id:actNOZRETLed
                    text: qsTr("NOZ.RET")
                    y:actBCCOOLLed.y
                    anchors.horizontalCenter: r2.right
                }
                Image{
                    id:r4
                    source: "images/arrow-Unit.png"
                    anchors.top: actNOZRETLed.bottom
                }

                ICIMMLedTextLabel{
                    id:actCHARLed
                    text: qsTr("CHAR")
                    anchors.top: r4.bottom
                    anchors.horizontalCenter: r4.horizontalCenter
                }
                Image {
                    id:r5
                    source: "images/arrow-Left.png"
                    anchors.top: actCHARLed.bottom
                    anchors.horizontalCenter: r4.horizontalCenter
                    rotation: 90
                }
                ICIMMLedTextLabel{
                    id:actNOZRET2Led
                    text: qsTr("NOZ.RET")
                    anchors.top: r5.bottom
                    anchors.horizontalCenter: r5.horizontalCenter
                }
                Image {
                    id:r6
                    source: "images/arrow-Left.png"
                    anchors.verticalCenter: actNOZRET2Led.verticalCenter
                    anchors.right: actNOZRET2Led.left
                    rotation: -180
                }
                ICIMMLedTextLabel{
                    id:actCOOLLed
                    text: qsTr("COOL")
                    y:actNOZRET2Led.y
                    anchors.right: r6.left
                }
                Image {
                    id:r7
                    source: "images/arrow-Left.png"
                    anchors.top: actCOOLLed.top
                    anchors.right: bgContainer.left
                    rotation: -180
                }
                ICIMMLedTextLabel{
                    id:actOMLed
                    text: qsTr("O.M")
                    anchors.right: r7.left
                    anchors.verticalCenter: r7.verticalCenter
                }
                Image {
                    id:r8
                    source: "images/arrow-Left.png"
                    anchors.verticalCenter: r7.verticalCenter
                    anchors.right: actOMLed.left
                    rotation: -180
                }
                ICIMMLedTextLabel{
                    id:actEJELed
                    text: qsTr("EJE")
                    anchors.right: r8.left
                    anchors.verticalCenter: r7.verticalCenter
                }
                Image {
                    id:r9
                    source: "images/arrow-Turn.png"
                    anchors.bottom: r7.verticalCenter
                    anchors.right: actEJELed.left
                    width: sourceSize.width * 0.9
                }
                ICIMMLedTextLabel{
                    id:actRecycleLed
                    text: qsTr("RECYCLE")
                    anchors.bottom: r9.top;
                    anchors.left: r9.left
                }
                Image {
                    id:r10
                    source: "images/arrow-LongUp.png"
                    anchors.bottom: actRecycleLed.top
                    anchors.left: actRecycleLed.left
                    height: sourceSize.height * 1.5
                }
            }
        }
    }

    Grid{
        id: touchKeyboard
        rows: 4
        columns: 4
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.leftMargin: Style.touchControlSection.touchKeyboard.leftMargin
        anchors.topMargin: Style.touchControlSection.touchKeyboard.topMargin
        spacing: Style.touchControlSection.touchKeyboard.spacing
        ICIMMGrowBigButtion{
            id:helpBtn
            text: "?"
            width: Style.touchControlSection.touchKeyboard.btnSize
            height: width
            bgColor: Style.touchControlSection.touchKeyboard.btnBG
            border.width: 0
            font.pixelSize: Style.touchControlSection.touchKeyboard.font.pixelSize
        }
        ICIMMGrowBigButtion{
            id:btn7
            text: "7"
            width: Style.touchControlSection.touchKeyboard.btnSize
            height: width
            bgColor: Style.touchControlSection.touchKeyboard.btnBG
            border.width: helpBtn.border.width
            onButtonClicked: panelController.posKeyEvent(Qt.Key_7, "7");
            font.pixelSize: helpBtn.font.pixelSize
        }
        ICIMMGrowBigButtion{
            id:btn8
            text: "8"
            width: Style.touchControlSection.touchKeyboard.btnSize
            height: width
            bgColor: Style.touchControlSection.touchKeyboard.btnBG
            border.width: helpBtn.border.width
            onButtonClicked: panelController.posKeyEvent(Qt.Key_8, "8");
            font.pixelSize: helpBtn.font.pixelSize

        }
        ICIMMGrowBigButtion{
            id:btn9
            text: "9"
            width: Style.touchControlSection.touchKeyboard.btnSize
            height: width
            bgColor: Style.touchControlSection.touchKeyboard.btnBG
            border.width: helpBtn.border.width
            onButtonClicked: panelController.posKeyEvent(Qt.Key_9, "9");
            font.pixelSize: helpBtn.font.pixelSize

        }
        ICIMMGrowBigButtion{
            id:clkBtn
            text: "CLK"
            width: Style.touchControlSection.touchKeyboard.btnSize
            height: width
            bgColor: Style.touchControlSection.touchKeyboard.btnBG
            border.width: helpBtn.border.width
            onButtonClicked: panelController.posKeyEvent(Qt.Key_Backspace, "");
            font.pixelSize: helpBtn.font.pixelSize

        }
        ICIMMGrowBigButtion{
            id:btn4
            text: "4"
            width: Style.touchControlSection.touchKeyboard.btnSize
            height: width
            bgColor: Style.touchControlSection.touchKeyboard.btnBG
            border.width: helpBtn.border.width
            onButtonClicked: panelController.posKeyEvent(Qt.Key_4, "4");
            font.pixelSize: helpBtn.font.pixelSize

        }
        ICIMMGrowBigButtion{
            id:btn5
            text: "5"
            width: Style.touchControlSection.touchKeyboard.btnSize
            height: width
            bgColor: Style.touchControlSection.touchKeyboard.btnBG
            border.width: helpBtn.border.width
            onButtonClicked: panelController.posKeyEvent(Qt.Key_5, "5");
            font.pixelSize: helpBtn.font.pixelSize

        }
        ICIMMGrowBigButtion{
            id:btn6
            text: "6"
            width: Style.touchControlSection.touchKeyboard.btnSize
            height: width
            bgColor: Style.touchControlSection.touchKeyboard.btnBG
            border.width: helpBtn.border.width
            onButtonClicked: panelController.posKeyEvent(Qt.Key_6, "6");
            font.pixelSize: helpBtn.font.pixelSize

        }
        ICIMMGrowBigButtion{
            id:fnBtn
            text: "Fn"
            width: Style.touchControlSection.touchKeyboard.btnSize
            height: width
            bgColor: Style.touchControlSection.touchKeyboard.btnBG
            border.width: helpBtn.border.width
            font.pixelSize: helpBtn.font.pixelSize

        }
        ICIMMGrowBigButtion{
            id:btn1
            text: "1"
            width: Style.touchControlSection.touchKeyboard.btnSize
            height: width
            bgColor: Style.touchControlSection.touchKeyboard.btnBG
            border.width: helpBtn.border.width
            onButtonClicked: panelController.posKeyEvent(Qt.Key_1, "1");
            font.pixelSize: helpBtn.font.pixelSize

        }
        ICIMMGrowBigButtion{
            id:btn2
            text: "2"
            width: Style.touchControlSection.touchKeyboard.btnSize
            height: width
            bgColor: Style.touchControlSection.touchKeyboard.btnBG
            border.width: helpBtn.border.width
            onButtonClicked: panelController.posKeyEvent(Qt.Key_2, "2");
            font.pixelSize: helpBtn.font.pixelSize

        }
        ICIMMGrowBigButtion{
            id:btn3
            text: "3"
            width: Style.touchControlSection.touchKeyboard.btnSize
            height: width
            bgColor: Style.touchControlSection.touchKeyboard.btnBG
            border.width: helpBtn.border.width
            onButtonClicked: panelController.posKeyEvent(Qt.Key_3, "3");
            font.pixelSize: helpBtn.font.pixelSize

        }
        ICIMMGrowBigButtion{
            id:printBtn
            text: "Print"
            width: Style.touchControlSection.touchKeyboard.btnSize
            height: width
            bgColor: Style.touchControlSection.touchKeyboard.btnBG
            border.width: helpBtn.border.width
            font.pixelSize: helpBtn.font.pixelSize

        }
        ICIMMGrowBigButtion{
            id:btn0
            text: "0"
            width: Style.touchControlSection.touchKeyboard.btnSize
            height: width
            bgColor: Style.touchControlSection.touchKeyboard.btnBG
            border.width: helpBtn.border.width
            onButtonClicked: panelController.posKeyEvent(Qt.Key_0, "0");
            font.pixelSize: helpBtn.font.pixelSize

        }
        ICIMMGrowBigButtion{
            id:btnDot
            text: "."
            width: Style.touchControlSection.touchKeyboard.btnSize
            height: width
            bgColor: Style.touchControlSection.touchKeyboard.btnBG
            border.width: helpBtn.border.width
            onButtonClicked: panelController.posKeyEvent(Qt.Key_Period, ".");
            font.pixelSize: helpBtn.font.pixelSize

        }
        ICIMMGrowBigButtion{
            id:btnEnt
            text: "←┘"
            width: Style.touchControlSection.touchKeyboard.btnSize
            height: width
            bgColor: Style.touchControlSection.touchKeyboard.btnBG
            border.width: helpBtn.border.width
            onButtonClicked: panelController.posKeyEvent(Qt.Key_Return, "");
            font.pixelSize: helpBtn.font.pixelSize

        }
    }

    Item{
        id:touchNavKeyboard
        width: navLeft.width + navRight.width + navRight.anchors.leftMargin
        height: navUp.height + navDown.height + (navLeft.anchors.topMargin << 1) + navLeft.height
        anchors.verticalCenter: touchKeyboard.verticalCenter
        anchors.left: touchKeyboard.right
        anchors.leftMargin: 8 * Style.wRatio

        Image {
            id: navUp
            source: "images/nav-Up.png"
            width: sourceSize.width * Style.wRatio
            height: sourceSize.height * Style.hRatio
            anchors.horizontalCenter: parent.horizontalCenter
            smooth: true
        }

        Image{
            id:navLeft
            source: "images/nav-Left.png"
            width: sourceSize.width * Style.wRatio
            height: sourceSize.height * Style.hRatio
            smooth: true
            anchors.top: navUp.bottom
            anchors.topMargin: 20 * Style.hRatio

        }
        Image{
            id:navRight
            source: "images/nav-Right.png"
            width: sourceSize.width * Style.wRatio
            height: sourceSize.height * Style.hRatio
            smooth: true
            y:navLeft.y
            anchors.left: navLeft.right
            anchors.leftMargin: 24 * Style.wRatio
        }

        Image {
            id: navDown
            source: "images/nav-Down.png"
            width: sourceSize.width * Style.wRatio
            height: sourceSize.height * Style.hRatio
            anchors.horizontalCenter: parent.horizontalCenter
            smooth: true
            anchors.top: navLeft.bottom
            anchors.topMargin: navLeft.anchors.topMargin
        }

        MouseArea{
            anchors.fill: parent
            function pointsInItem(item, mX, mY){
                var dx = mX - item.x;
                var dy = mY - item.y;
                return (dx >= 0 && dx <= item.width) && (dy >=0 && dy <= item.height);
            }

            onClicked: {
                if(pointsInItem(navUp, mouseX, mouseY))
                    panelController.posKeyEvent(Qt.Key_Up,"");
                else if(pointsInItem(navDown, mouseX, mouseY))
                    panelController.posKeyEvent(Qt.Key_Down, "");
                else if(pointsInItem(navLeft, mouseX, mouseY))
                    panelController.posKeyEvent(Qt.Key_Left, "");
                else if(pointsInItem(navRight, mouseX, mouseY))
                    panelController.posKeyEvent(Qt.Key_Right, "");
            }
        }
    }

    Grid{
        id:manageKeyboard
        rows: 3
        columns: 5
        spacing: Style.touchControlSection.manageKeyboard.spacing
        anchors.bottom: parent.bottom
        ICIMMFunctionMenuItem{
            id:generalSpecifications
            text: qsTr("Main\nSpec")
            bindingPageComponent: "ICPanelFuncPage.qml"
            monitorComponent: "ICMoldMonitorPage.qml"
        }
        ICIMMFunctionMenuItem{
            id:generalSettings
            text: qsTr("Gen\nConf")
            bindingPageComponent: "ICGenConfigFuncPage.qml"
            monitorComponent: "ICMoldMonitorPage.qml"
        }
        ICIMMFunctionMenuItem{
            id:recordBtn
            text: qsTr("Record")
        }
        ICIMMFunctionMenuItem{
            id:ioSettingsIMM
            text: qsTr("I/O\nFunc")
            bindingPageComponent: "ICIOFuncPage.qml"
            monitorComponent: "ICMoldMonitorPage.qml"
        }
        ICIMMFunctionMenuItem{
            id:maintenance
            text: qsTr("maintain")
            bindingPageComponent: "ICMaintainFuncPage.qml"
            monitorComponent: "ICMoldMonitorPage.qml"
        }
        ICIMMFunctionMenuItem{
            id:actionMonitor
            text: qsTr("Act\nMon")
            bindingPageComponent: "ICActionMonitorFuncPage.qml"
            monitorComponent: "ICActionMonitorPage.qml"
            isChecked: true

        }
        ICIMMFunctionMenuItem{
            id:produceMonitor
            text: qsTr("Pro\nMon")
        }
        ICIMMFunctionMenuItem{
            id:qualityControl
            text: qsTr("Qual\nCtrl")
            bindingPageComponent: "ICQualityControlFuncPage.qml"
            monitorComponent: "ICActionMonitorPage.qml"
        }
        ICIMMFunctionMenuItem{
            id:curveMonitor
            text: qsTr("Curves\nMon")
        }
        ICIMMFunctionMenuItem{
            id:oscilloscope
            text: qsTr("Oscil-\nloscope")
        }
        ICIMMFunctionMenuItem{
            id:ioMonitor
            text: qsTr("IO\nMon")
        }
        ICIMMFunctionMenuItem{
            id:servoAlarm
            text: qsTr("Servo\nAlarm")
        }
        ICIMMFunctionMenuItem{
            id:alarmHistory
            text: qsTr("Alarm\nHistory")
        }
        ICIMMButton{
            id:clearAlarm
            text: qsTr("Alarm\nClear")
            width: alarmHistory.width
            height: alarmHistory.height
            onButtonClicked: {
                panelController.posKeyEvent(Qt.Key_F6, "");
            }
        }
        ICIMMButton{
            id:showAlarm
            text: qsTr("Show\nAlarm")
            width: alarmHistory.width
            height: alarmHistory.height
            property bool isDebug: false
            onButtonClicked: {
                isDebug = !isDebug;
                panelController.setCommunicateDebug(isDebug);
                panelController.setEth0Enable(isDebug, 0, "192.168.10.201", "192.168.10.197", 9999);
            }
        }
    }

    Row{
        id:modeSwicherContainer
        anchors.left: immModeBG.left
        anchors.top: immModeBG.bottom
        spacing: 1
        state: "manual"
        states: [
            State {
                name: "manual"
                PropertyChanges { target: modeManualBtn;color:"lime";}
            },
            State {
                name: "semiAuto"
                PropertyChanges { target: modeSemiAutoBtn;color:"lime";}
            },
            State {
                name: "auto"
                PropertyChanges { target: modeAuto;color:"lime";}
            },
            State {
                name: "autoRun"
                PropertyChanges { target: modeAuto;color:"lime";}
                PropertyChanges { target: modeAutoRun;color:"lime";}
            }
        ]

        ICIMMLabel{
            id:modeCloseBtn
            text: qsTr("Motor off")
            width: Style.touchControlSection.modeSwicherContainer.btnWidth
            height: Style.touchControlSection.modeSwicherContainer.btnHeight + 1
            color: "red"
            states: [
                State {
                    name: "on"
                    PropertyChanges {
                        target: modeCloseBtn
                        text:qsTr("Motor On")
                        color:"lime"
                    }
                }
            ]
        }
        ICIMMLabel{
            id:modePrepareBtn
            text: qsTr("Heat Off")
            width: Style.touchControlSection.modeSwicherContainer.btnWidth
            height: Style.touchControlSection.modeSwicherContainer.btnHeight
            color: Style.touchControlSection.modeSwicherContainer.btnBG
            state: "off"
            states: [
                State {
                    name: "on"
                    PropertyChanges {
                        target: modePrepareBtn
                        text:qsTr("Heat On")
                        color:"gold"
                    }
                }
            ]
        }
        ICIMMLabel{
            id:modeManualBtn
            text: qsTr("Manual")
            width: Style.touchControlSection.modeSwicherContainer.btnWidth
            height: Style.touchControlSection.modeSwicherContainer.btnHeight
            color: Style.touchControlSection.modeSwicherContainer.btnBG
        }
        ICIMMLabel{
            id:modeSemiAutoBtn
            text: qsTr("Semi A")
            width: Style.touchControlSection.modeSwicherContainer.btnWidth
            height: Style.touchControlSection.modeSwicherContainer.btnHeight
            color: Style.touchControlSection.modeSwicherContainer.btnBG
        }
        ICIMMLabel{
            id:modeAuto
            text: qsTr("Auto")
            width: Style.touchControlSection.modeSwicherContainer.btnWidth
            height: Style.touchControlSection.modeSwicherContainer.btnHeight
            color: Style.touchControlSection.modeSwicherContainer.btnBG
        }
        ICIMMLabel{
            id:modeAutoRun
            text: qsTr("Auto R")
            width: Style.touchControlSection.modeSwicherContainer.btnWidth
            height: Style.touchControlSection.modeSwicherContainer.btnHeight
            color: Style.touchControlSection.modeSwicherContainer.btnBG
        }
    }

    Row{
        id: optionalKeyboard
        anchors.bottom: parent.bottom
        anchors.bottomMargin: touchKeyboard.anchors.bottomMargin
        anchors.horizontalCenter: modeSwicherContainer.horizontalCenter
//        anchors.right: parent.right
//        anchors.rightMargin: Style.touchControlSection.optionalKeyboard.rightMargin
        spacing: Style.touchControlSection.optionalKeyboard.groupSpacing
//        visible: false
        Column{
            spacing: Style.touchControlSection.optionalKeyboard.btnSpacing
            ICLabel{
                id:securityDoorLabel
                width: Style.touchControlSection.optionalKeyboard.btnSize * 2 +
                       Style.touchControlSection.optionalKeyboard.btnSpacing
                height: Style.touchControlSection.optionalKeyboard.labelHeight
                text: qsTr("SE Door")
                color: Style.touchControlSection.optionalKeyboard.labelBG
                font.pixelSize: Style.touchControlSection.functionMenuItem.font.pixelSize
            }
            Row{
                spacing: Style.touchControlSection.optionalKeyboard.btnSpacing
                ICButton{
                    id:securityDoorOpenBtn
                    text: qsTr("Open")
                    width: Style.touchControlSection.optionalKeyboard.btnSize
                    height: width
                    border.width: 0
                    bgColor: Style.touchControlSection.optionalKeyboard.btnBG
                    font.pixelSize: securityDoorLabel.font.pixelSize
                }
                ICButton{
                    id:securityDoorCloseBtn
                    text: qsTr("Close", "SE DOOR")
                    width: Style.touchControlSection.optionalKeyboard.btnSize
                    height: width
                    border.width: 0
                    bgColor: securityDoorOpenBtn.bgColor
                    font.pixelSize: securityDoorLabel.font.pixelSize
                }
            }
        }
        Column{
            spacing: Style.touchControlSection.optionalKeyboard.btnSpacing
            ICLabel{
                id:coreLabel
                width: Style.touchControlSection.optionalKeyboard.btnSize * 2 +
                       Style.touchControlSection.optionalKeyboard.btnSpacing
                height: Style.touchControlSection.optionalKeyboard.labelHeight
                text: qsTr("Core")
                color: Style.touchControlSection.optionalKeyboard.labelBG
                font.pixelSize: securityDoorLabel.font.pixelSize
            }
            Row{
                spacing: Style.touchControlSection.optionalKeyboard.btnSpacing
                ICButton{
                    id:coreInBtn
                    text: qsTr("In")
                    width: Style.touchControlSection.optionalKeyboard.btnSize
                    height: width
                    border.width: 0
                    bgColor: securityDoorOpenBtn.bgColor
                    font.pixelSize: securityDoorLabel.font.pixelSize

                }
                ICButton{
                    id:coreOutBtn
                    text: qsTr("Out")
                    width: Style.touchControlSection.optionalKeyboard.btnSize
                    height: width
                    border.width: 0
                    bgColor: securityDoorOpenBtn.bgColor
                    font.pixelSize: securityDoorLabel.font.pixelSize

                }
            }
        }

        Column{
            spacing: Style.touchControlSection.optionalKeyboard.btnSpacing
            ICLabel{
                text: qsTr("Blow")
                width: Style.touchControlSection.optionalKeyboard.btnSize +
                       Style.touchControlSection.optionalKeyboard.btnSpacing
                height: Style.touchControlSection.optionalKeyboard.labelHeight
                color: Style.touchControlSection.optionalKeyboard.labelBG
                font.pixelSize: securityDoorLabel.font.pixelSize
            }
            ICButton{
                id:blowBtn
                text: qsTr("Blow")
                width: Style.touchControlSection.optionalKeyboard.btnSize
                height: width
                border.width: 0
                bgColor: securityDoorOpenBtn.bgColor
                font.pixelSize: securityDoorLabel.font.pixelSize
            }
        }
    }

    Component.onCompleted: {
        //        console.log(btn0.width);
        var c = manageKeyboard.children;
        for(var i = 0, len = c.length; i < len; ++i){
            if(c[i].hasOwnProperty("isChecked"))
                funcMenuItemGroup.addButton(c[i]);
        }
    }
    Timer{
        id:refreshTimer
        running: true
        repeat: true
        interval: 50
        onTriggered: {
            modeCloseBtn.state = panelController.statusValue("c_ro_25_1_0_1537") ? "on" : "" ;
            modePrepareBtn.state = panelController.statusValue("c_ro_15_1_0_1537") ? "on" : "";
            var mode = panelController.statusValue("c_ro_0_4_0_1537");
            if(PData.oldMode !== mode){
                PData.oldMode = mode;
                if(mode == MacroDefine.RunningMode.kMode_Manual)
                    modeSwicherContainer.state = "manual";
                else if(mode == MacroDefine.RunningMode.kMode_SemiAuto)
                    modeSwicherContainer.state = "semiAuto";
                else if(mode == MacroDefine.RunningMode.kMode_Auto){
                    if(panelController.statusValue("c_ro_12_1_0_1537"))
                        modeSwicherContainer.state = "autoRun";
                    else
                        modeSwicherContainer.state = "auto";
                }
            }


        }
    }
}

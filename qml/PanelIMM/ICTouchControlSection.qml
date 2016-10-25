import QtQuick 1.1
import "../styles/style.js" as Style
import "../ICCustomElement"
import "immcustomitems"

Rectangle {
    id:instance
    width: Style.touchControlSection.rect.width
    height: Style.touchControlSection.rect.height
    color: Style.touchControlSection.bg
    signal funcMenuItemTriggered(variant menuItem)
    signal recordMenuItemTriggered(variant menuItem)
    signal alarmHistoryMenuItemTriggered(variant menuItem)
    signal ioMonitorMenuItemTriggered(variant menuItem)
    function init(){
        funcMenuItemTriggered(actionMonitor);
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
                else
                    funcMenuItemTriggered(checkedItem);
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
                ICIMMText{text: "-->"}
                ICIMMLedTextLabel{
                    id:actNOZADVLed
                    text: qsTr("NOZ.ADV")
                }
                ICIMMText{text: "-->"}
                ICIMMLedTextLabel{
                    id:actBCHARLed
                    text: qsTr("B.CHAR")
                }
                ICIMMText{text: "-->"}
                ICIMMLedTextLabel{
                    id:actINJLed
                    text: qsTr("INJ")
                }
                ICIMMText{text: "-->"}
                ICIMMLedTextLabel{
                    id:actHPLed
                    text: qsTr("H.P")
                }
            }
            Item{
                id:ledCol1
                y:actHPLed.y + actHPLed.height / 2
                x:actHPLed.x
                Rectangle{
                    id:bgContainer
                    color: "green"
                    anchors.left: actCOOLLed.left
                    anchors.right: actNOZRETLed.right
                    anchors.top: r2.top
                    anchors.bottom: actCOOLLed.bottom
                }
                ICIMMText{id:r3;text: "↓"}
                ICIMMText{id:r1;text: "________";anchors.horizontalCenter: r3.horizontalCenter}
                ICIMMText{id:r2;text: "↓      ↓";y:r1.height / 2;anchors.horizontalCenter: r1.horizontalCenter}
                ICIMMLedTextLabel{
                    id:actBCCOOLLed
                    text: qsTr("BC.COOL")
                    anchors.top:r2.bottom
                    anchors.topMargin: -4 * Style.hRatio
                    anchors.right: r3.left
                }
                ICIMMLedTextLabel{
                    id:actNOZRETLed
                    text: qsTr("NOZ.RET")
                    y:actBCCOOLLed.y
                    anchors.left: actBCCOOLLed.right
                    anchors.leftMargin: 10 * Style.wRatio
                }
                ICIMMText{id:r4;text: "↓      ↓";y:actBCCOOLLed.height / 2 + actBCCOOLLed.y;x:r2.x}
                ICIMMText{id:r5;text: "________";x:r1.x;y:r4.y}
                ICIMMText{id:r6;text: "↓";x:r3.x;y:r5.y + r5.height / 2}
                ICIMMLedTextLabel{
                    id:actCHARLed
                    text: qsTr("CHAR")
                    anchors.top: r6.bottom
                    anchors.topMargin: -4 * Style.hRatio
                    anchors.horizontalCenter: r6.horizontalCenter
                }
                ICIMMText{id:r7;text: "↓";x:r3.x;y:actCHARLed.y + actCHARLed.height / 2}
                ICIMMLedTextLabel{
                    id:actNOZRET2Led
                    text: qsTr("NOZ.RET")
                    anchors.top: r7.bottom
                    anchors.topMargin: -4 * Style.hRatio
                    anchors.horizontalCenter: r7.horizontalCenter
                }
                ICIMMText{id:r8;text: "←";anchors.right: actNOZRET2Led.left;y:actNOZRET2Led.y}
                ICIMMLedTextLabel{
                    id:actCOOLLed
                    text: qsTr("COOL")
                    y:actNOZRET2Led.y
                    anchors.right: r8.left
                }
            }
            Row{
                id:ledRow2
                x:4 * Style.wRatio
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 10
                ICIMMText{text: "___________"}
                ICIMMLedTextLabel{
                    id:actEJELed
                    text: qsTr("EJE")
                }
                ICIMMText{text: "←"}
                ICIMMLedTextLabel{
                    id:actOMLed
                    text: qsTr("O.M")
                }
                ICIMMText{text: "←"}
            }
            ICIMMText{id:l1;text: "|";anchors.bottom: ledRow2.top;anchors.bottomMargin: -height;x:4 * Style.wRatio}
            ICIMMText{id:l2;text: "↑";anchors.bottom: l1.top;anchors.bottomMargin: -5}
            ICIMMLedTextLabel{
                id:actRecycleLed
                text: qsTr("RECYCLE")
                anchors.bottom: l2.top;
                anchors.bottomMargin: -5
            }
            ICIMMText{id:l3;text: "|";anchors.bottom: actRecycleLed.top;x:l1.x;anchors.bottomMargin: -3}
            ICIMMText{id:l4;text: "|";anchors.bottom: l3.top;anchors.bottomMargin: -5;x:4 * Style.wRatio}
            ICIMMText{id:l5;text: "↑";anchors.bottom: l4.top;anchors.bottomMargin: -5}

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
        ICButton{
            id:helpBtn
            text: "?"
            width: Style.touchControlSection.touchKeyboard.btnSize
            height: width
            bgColor: Style.touchControlSection.touchKeyboard.btnBG
            border.width: 0
            font.pixelSize: Style.touchControlSection.touchKeyboard.font.pixelSize
        }
        ICButton{
            id:btn7
            text: "7"
            width: Style.touchControlSection.touchKeyboard.btnSize
            height: width
            bgColor: Style.touchControlSection.touchKeyboard.btnBG
            border.width: helpBtn.border.width
            onButtonClicked: panelController.posKeyEvent(Qt.Key_7, "7");
            font.pixelSize: helpBtn.font.pixelSize
        }
        ICButton{
            id:btn8
            text: "8"
            width: Style.touchControlSection.touchKeyboard.btnSize
            height: width
            bgColor: Style.touchControlSection.touchKeyboard.btnBG
            border.width: helpBtn.border.width
            onButtonClicked: panelController.posKeyEvent(Qt.Key_8, "8");
            font.pixelSize: helpBtn.font.pixelSize

        }
        ICButton{
            id:btn9
            text: "9"
            width: Style.touchControlSection.touchKeyboard.btnSize
            height: width
            bgColor: Style.touchControlSection.touchKeyboard.btnBG
            border.width: helpBtn.border.width
            onButtonClicked: panelController.posKeyEvent(Qt.Key_9, "9");
            font.pixelSize: helpBtn.font.pixelSize

        }
        ICButton{
            id:clkBtn
            text: "CLK"
            width: Style.touchControlSection.touchKeyboard.btnSize
            height: width
            bgColor: Style.touchControlSection.touchKeyboard.btnBG
            border.width: helpBtn.border.width
            onButtonClicked: panelController.posKeyEvent(Qt.Key_Backspace, "");
            font.pixelSize: helpBtn.font.pixelSize

        }
        ICButton{
            id:btn4
            text: "4"
            width: Style.touchControlSection.touchKeyboard.btnSize
            height: width
            bgColor: Style.touchControlSection.touchKeyboard.btnBG
            border.width: helpBtn.border.width
            onButtonClicked: panelController.posKeyEvent(Qt.Key_4, "4");
            font.pixelSize: helpBtn.font.pixelSize

        }
        ICButton{
            id:btn5
            text: "5"
            width: Style.touchControlSection.touchKeyboard.btnSize
            height: width
            bgColor: Style.touchControlSection.touchKeyboard.btnBG
            border.width: helpBtn.border.width
            onButtonClicked: panelController.posKeyEvent(Qt.Key_5, "5");
            font.pixelSize: helpBtn.font.pixelSize

        }
        ICButton{
            id:btn6
            text: "6"
            width: Style.touchControlSection.touchKeyboard.btnSize
            height: width
            bgColor: Style.touchControlSection.touchKeyboard.btnBG
            border.width: helpBtn.border.width
            onButtonClicked: panelController.posKeyEvent(Qt.Key_6, "6");
            font.pixelSize: helpBtn.font.pixelSize

        }
        ICButton{
            id:fnBtn
            text: "Fn"
            width: Style.touchControlSection.touchKeyboard.btnSize
            height: width
            bgColor: Style.touchControlSection.touchKeyboard.btnBG
            border.width: helpBtn.border.width
            font.pixelSize: helpBtn.font.pixelSize

        }
        ICButton{
            id:btn1
            text: "1"
            width: Style.touchControlSection.touchKeyboard.btnSize
            height: width
            bgColor: Style.touchControlSection.touchKeyboard.btnBG
            border.width: helpBtn.border.width
            onButtonClicked: panelController.posKeyEvent(Qt.Key_1, "1");
            font.pixelSize: helpBtn.font.pixelSize

        }
        ICButton{
            id:btn2
            text: "2"
            width: Style.touchControlSection.touchKeyboard.btnSize
            height: width
            bgColor: Style.touchControlSection.touchKeyboard.btnBG
            border.width: helpBtn.border.width
            onButtonClicked: panelController.posKeyEvent(Qt.Key_2, "2");
            font.pixelSize: helpBtn.font.pixelSize

        }
        ICButton{
            id:btn3
            text: "3"
            width: Style.touchControlSection.touchKeyboard.btnSize
            height: width
            bgColor: Style.touchControlSection.touchKeyboard.btnBG
            border.width: helpBtn.border.width
            onButtonClicked: panelController.posKeyEvent(Qt.Key_3, "3");
            font.pixelSize: helpBtn.font.pixelSize

        }
        ICButton{
            id:printBtn
            text: "Print"
            width: Style.touchControlSection.touchKeyboard.btnSize
            height: width
            bgColor: Style.touchControlSection.touchKeyboard.btnBG
            border.width: helpBtn.border.width
            font.pixelSize: helpBtn.font.pixelSize

        }
        ICButton{
            id:btn0
            text: "0"
            width: Style.touchControlSection.touchKeyboard.btnSize
            height: width
            bgColor: Style.touchControlSection.touchKeyboard.btnBG
            border.width: helpBtn.border.width
            onButtonClicked: panelController.posKeyEvent(Qt.Key_0, "0");
            font.pixelSize: helpBtn.font.pixelSize

        }
        ICButton{
            id:btnDot
            text: "."
            width: Style.touchControlSection.touchKeyboard.btnSize
            height: width
            bgColor: Style.touchControlSection.touchKeyboard.btnBG
            border.width: helpBtn.border.width
            onButtonClicked: panelController.posKeyEvent(Qt.Key_Period, ".");
            font.pixelSize: helpBtn.font.pixelSize

        }
        ICButton{
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

        }
        ICIMMFunctionMenuItem{
            id:recordBtn
            text: qsTr("Record")
        }
        ICIMMFunctionMenuItem{
            id:prepareIMM
            text: qsTr("Prepare")
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
        }
        ICIMMButton{
            id:showAlarm
            text: qsTr("Show\nAlarm")
            width: alarmHistory.width
            height: alarmHistory.height
        }
    }

    ICButtonGroup{
        id:modeSwicherContainer
        anchors.left: immModeBG.left
        anchors.top: immModeBG.bottom
        mustChecked: true
        checkedIndex: 0
        spacing: 0
        ICCheckableButton{
            id:modeCloseBtn
            text: qsTr("Close")
            width: Style.touchControlSection.modeSwicherContainer.btnWidth
            height: Style.touchControlSection.modeSwicherContainer.btnHeight
            bgColor: Style.touchControlSection.modeSwicherContainer.btnBG
            isChecked: true

        }
        ICCheckableButton{
            id:modePrepareBtn
            text: qsTr("Prepare")
            width: Style.touchControlSection.modeSwicherContainer.btnWidth
            height: Style.touchControlSection.modeSwicherContainer.btnHeight
            bgColor: Style.touchControlSection.modeSwicherContainer.btnBG
        }
        ICCheckableButton{
            id:modeManualBtn
            text: qsTr("Manual")
            width: Style.touchControlSection.modeSwicherContainer.btnWidth
            height: Style.touchControlSection.modeSwicherContainer.btnHeight
            bgColor: Style.touchControlSection.modeSwicherContainer.btnBG
        }
        ICCheckableButton{
            id:modeSemiAutoBtn
            text: qsTr("Semi A")
            width: Style.touchControlSection.modeSwicherContainer.btnWidth
            height: Style.touchControlSection.modeSwicherContainer.btnHeight
            bgColor: Style.touchControlSection.modeSwicherContainer.btnBG
        }
        ICCheckableButton{
            id:modeAuto
            text: qsTr("Auto")
            width: Style.touchControlSection.modeSwicherContainer.btnWidth
            height: Style.touchControlSection.modeSwicherContainer.btnHeight
            bgColor: Style.touchControlSection.modeSwicherContainer.btnBG
        }
        ICCheckableButton{
            id:modeAutoRun
            text: qsTr("Auto R")
            width: Style.touchControlSection.modeSwicherContainer.btnWidth
            height: Style.touchControlSection.modeSwicherContainer.btnHeight
            bgColor: Style.touchControlSection.modeSwicherContainer.btnBG
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

                }
                ICButton{
                    id:securityDoorCloseBtn
                    text: qsTr("Close")
                    width: Style.touchControlSection.optionalKeyboard.btnSize
                    height: width
                    border.width: 0
                    bgColor: securityDoorOpenBtn.bgColor
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

                }
                ICButton{
                    id:coreOutBtn
                    text: qsTr("Out")
                    width: Style.touchControlSection.optionalKeyboard.btnSize
                    height: width
                    border.width: 0
                    bgColor: securityDoorOpenBtn.bgColor

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
            }
            ICButton{
                id:blowBtn
                text: qsTr("Blow")
                width: Style.touchControlSection.optionalKeyboard.btnSize
                height: width
                border.width: 0
                bgColor: securityDoorOpenBtn.bgColor
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
}

import QtQuick 1.1
import "style.js" as Style
import "../ICCustomElement"
import "immcustomitems"

Rectangle {
    id:instance
    width: Style.touchControlSection.rect.width
    height: Style.touchControlSection.rect.height
    color: Style.touchControlSection.bg
    signal funcMenuItemTriggered(variant menuItem)
    Image {
        id: immModeBG
        source: "images/immModeBg.png"
        anchors.right: parent.right
        anchors.rightMargin: Style.touchControlSection.immModeBG.rightMargin
        anchors.top: parent.top
        anchors.topMargin: Style.touchControlSection.immModeBG.topMargin
        width: sourceSize.width * Style.wRatio
        height: sourceSize.height * Style.hRatio
        ICButtonGroup{
            isAutoSize: false
            anchors.fill: parent
            layoutMode: 2
            onCheckedItemChanged: {
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
                monitorComponent: "ICWorkReadyMonitorPage.qml"
            }
            ICIMMFunctionMenuItem{
                id:mold
                text: qsTr("Mold")
                y: workReady.y
                anchors.left: workReady.right
                anchors.leftMargin: 8 * Style.wRatio
            }

            ICIMMFunctionMenuItem{
                id:core
                text: qsTr("Core")
                y:workReady.y
                x:extentTemp.x
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
            }

            ICIMMFunctionMenuItem{
                id:inject
                text: qsTr("Inject")
                y:workReady.y
                anchors.left: temperature.right
                anchors.leftMargin: 12 * Style.wRatio
            }

            ICIMMFunctionMenuItem{
                id:nozzle
                text: qsTr("Nozzle")
                anchors.top: opDevice.bottom
                anchors.topMargin: 12 * Style.hRatio
                x:opDevice.x
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
        ICButton{
            id:helpBtn
            text: "?"
            width: Style.touchControlSection.touchKeyboard.btnSize
            height: width
            bgColor: Style.touchControlSection.touchKeyboard.btnBG
            border.width: 0
        }
        ICButton{
            id:btn7
            text: "7"
            width: Style.touchControlSection.touchKeyboard.btnSize
            height: width
            bgColor: Style.touchControlSection.touchKeyboard.btnBG
            border.width: helpBtn.border.width
            onButtonClicked: panelController.posKeyEvent(Qt.Key_7, "7");

        }
        ICButton{
            id:btn8
            text: "8"
            width: Style.touchControlSection.touchKeyboard.btnSize
            height: width
            bgColor: Style.touchControlSection.touchKeyboard.btnBG
            border.width: helpBtn.border.width
            onButtonClicked: panelController.posKeyEvent(Qt.Key_8, "8");
        }
        ICButton{
            id:btn9
            text: "9"
            width: Style.touchControlSection.touchKeyboard.btnSize
            height: width
            bgColor: Style.touchControlSection.touchKeyboard.btnBG
            border.width: helpBtn.border.width
            onButtonClicked: panelController.posKeyEvent(Qt.Key_9, "9");
        }
        ICButton{
            id:clkBtn
            text: "CLK"
            width: Style.touchControlSection.touchKeyboard.btnSize
            height: width
            bgColor: Style.touchControlSection.touchKeyboard.btnBG
            border.width: helpBtn.border.width
            onButtonClicked: panelController.posKeyEvent(Qt.Key_Backspace, "");

        }
        ICButton{
            id:btn4
            text: "4"
            width: Style.touchControlSection.touchKeyboard.btnSize
            height: width
            bgColor: Style.touchControlSection.touchKeyboard.btnBG
            border.width: helpBtn.border.width
            onButtonClicked: panelController.posKeyEvent(Qt.Key_4, "4");

        }
        ICButton{
            id:btn5
            text: "5"
            width: Style.touchControlSection.touchKeyboard.btnSize
            height: width
            bgColor: Style.touchControlSection.touchKeyboard.btnBG
            border.width: helpBtn.border.width
            onButtonClicked: panelController.posKeyEvent(Qt.Key_5, "5");

        }
        ICButton{
            id:btn6
            text: "6"
            width: Style.touchControlSection.touchKeyboard.btnSize
            height: width
            bgColor: Style.touchControlSection.touchKeyboard.btnBG
            border.width: helpBtn.border.width
            onButtonClicked: panelController.posKeyEvent(Qt.Key_6, "6");
        }
        ICButton{
            id:fnBtn
            text: "Fn"
            width: Style.touchControlSection.touchKeyboard.btnSize
            height: width
            bgColor: Style.touchControlSection.touchKeyboard.btnBG
            border.width: helpBtn.border.width
        }
        ICButton{
            id:btn1
            text: "1"
            width: Style.touchControlSection.touchKeyboard.btnSize
            height: width
            bgColor: Style.touchControlSection.touchKeyboard.btnBG
            border.width: helpBtn.border.width
            onButtonClicked: panelController.posKeyEvent(Qt.Key_1, "1");
        }
        ICButton{
            id:btn2
            text: "2"
            width: Style.touchControlSection.touchKeyboard.btnSize
            height: width
            bgColor: Style.touchControlSection.touchKeyboard.btnBG
            border.width: helpBtn.border.width
            onButtonClicked: panelController.posKeyEvent(Qt.Key_2, "2");
        }
        ICButton{
            id:btn3
            text: "3"
            width: Style.touchControlSection.touchKeyboard.btnSize
            height: width
            bgColor: Style.touchControlSection.touchKeyboard.btnBG
            border.width: helpBtn.border.width
            onButtonClicked: panelController.posKeyEvent(Qt.Key_3, "3");

        }
        ICButton{
            id:printBtn
            text: "Print"
            width: Style.touchControlSection.touchKeyboard.btnSize
            height: width
            bgColor: Style.touchControlSection.touchKeyboard.btnBG
            border.width: helpBtn.border.width
        }
        ICButton{
            id:btn0
            text: "0"
            width: Style.touchControlSection.touchKeyboard.btnSize
            height: width
            bgColor: Style.touchControlSection.touchKeyboard.btnBG
            border.width: helpBtn.border.width
            onButtonClicked: panelController.posKeyEvent(Qt.Key_0, "0");

        }
        ICButton{
            id:btnDot
            text: "."
            width: Style.touchControlSection.touchKeyboard.btnSize
            height: width
            bgColor: Style.touchControlSection.touchKeyboard.btnBG
            border.width: helpBtn.border.width
            onButtonClicked: panelController.posKeyEvent(Qt.Key_Period, ".");
        }
        ICButton{
            id:btnEnt
            text: "←┘"
            width: Style.touchControlSection.touchKeyboard.btnSize
            height: width
            bgColor: Style.touchControlSection.touchKeyboard.btnBG
            border.width: helpBtn.border.width
            onButtonClicked: panelController.posKeyEvent(Qt.Key_Return, "");
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

    Row{
        id: optionalKeyboard
        anchors.bottom: parent.bottom
        anchors.bottomMargin: touchKeyboard.anchors.bottomMargin
        anchors.left: parent.left
        anchors.leftMargin: Style.touchControlSection.optionalKeyboard.leftMargin
        spacing: Style.touchControlSection.optionalKeyboard.groupSpacing
        Column{
            spacing: Style.touchControlSection.optionalKeyboard.btnSpacing
            ICLabel{
                id:securityDoorLabel
                width: Style.touchControlSection.optionalKeyboard.btnSize * 2 +
                       Style.touchControlSection.optionalKeyboard.btnSpacing
                height: Style.touchControlSection.optionalKeyboard.labelHeight
                text: qsTr("SE Door")
            }
            Row{
                spacing: Style.touchControlSection.optionalKeyboard.btnSpacing
                ICButton{
                    id:securityDoorOpenBtn
                    text: qsTr("Open")
                    width: Style.touchControlSection.optionalKeyboard.btnSize
                    height: width
                    border.width: 0

                }
                ICButton{
                    id:securityDoorCloseBtn
                    text: qsTr("Close")
                    width: Style.touchControlSection.optionalKeyboard.btnSize
                    height: width
                    border.width: 0
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
            }
            Row{
                spacing: Style.touchControlSection.optionalKeyboard.btnSpacing
                ICButton{
                    id:coreInBtn
                    text: qsTr("In")
                    width: Style.touchControlSection.optionalKeyboard.btnSize
                    height: width
                    border.width: 0

                }
                ICButton{
                    id:coreOutBtn
                    text: qsTr("Out")
                    width: Style.touchControlSection.optionalKeyboard.btnSize
                    height: width
                    border.width: 0
                }
            }
        }

        Column{
            spacing: Style.touchControlSection.optionalKeyboard.btnSpacing
            ICLabel{
                text: qsTr("Blow")
            }
        }
    }

    Component.onCompleted: {
        //        console.log(btn0.width);
    }
}

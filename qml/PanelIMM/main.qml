import QtQuick 1.1
import "../ICCustomElement"
import "../utils/utils.js" as Utils

Rectangle {
    id:mainWindow
    width: 768
    height: 1024
    Column{
        Row{
            spacing: 6
            ICLineEdit{
                id:l1
                text: "1"
            }
            ICLineEdit{
                id:l2
                text: "2"

            }
            ICLineEdit{
                id:l3
                text: "3"

            }
            ICLineEdit{
                id:l4
                text: "4"
            }
        }
        Row{
            spacing: 6
            ICLineEdit{
                id:l5
                text: "1"
            }
            ICLineEdit{
                id:l6
                text: "2"

            }
            ICLineEdit{
                id:l7
                text: "3"

            }
        }
    }

    Component.onCompleted: {
        Utils.generatePageKeyNav(mainWindow);
    }
}


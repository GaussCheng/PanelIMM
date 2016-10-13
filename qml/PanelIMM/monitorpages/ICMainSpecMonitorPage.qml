import QtQuick 1.1
import "../../ICCustomElement"
import "../immcustomitems"
Item {
    Grid{
        columns: 2
        y:2
        x:4
        ICIMMText {
            text: qsTr("HMI Version:")
        }
        ICIMMText{
            id:hmiVersion
            text: "IMM-1.0"
        }
        ICIMMText{
            text: qsTr("Host Version:")
        }
        ICIMMText{
            id:hostVersion
            text: "Host-1.0"
            color: "yellow"
        }
        ICIMMText{
            text: qsTr("Machine Code:")
        }
        ICIMMText{
            id:machineCode
//            text: panelController
        }
        ICIMMText{
            text: qsTr("SC")
        }
        ICIMMText{
            id:sc
        }
        ICIMMText{
            text: qsTr("MN")
        }
        ICIMMText{
            id:mn
        }
        ICIMMText{
            text: qsTr("MD")
        }
        ICIMMText{
            id:md
        }
    }
}

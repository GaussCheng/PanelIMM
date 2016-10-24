import QtQuick 1.1
import "../../ICCustomElement"
import "../immcustomitems"
Item {
    ICStatusScope{
        Grid{
            x:4
            y:2
            columns: 7
            rows:6
            ICIMMText{text: qsTr("DM.POSN")}
            ICIMMStatusWidget{
                id:c_ro_0_32_2_1541
                bindStatus: "c_ro_0_32_2_1541"
            }
            ICIMMText{text: qsTr("mm")}
            ICIMMText{text: "    "}
            ICIMMText{text: qsTr("EJE.POSN")}
            ICIMMStatusWidget{
                id:c_ro_0_32_2_1544
                bindStatus: "c_ro_0_32_2_1544"
            }
            ICIMMText{text: qsTr("mm")}

            ICIMMText{text: qsTr("DM.PRES")}
            ICIMMStatusWidget{
//                id:c_ro_0_16_1_1579
//                bindStatus: "c_ro_0_16_1_1579"
            }
            ICIMMText{text: qsTr("bar")}
            ICIMMText{text: "    "}
            ICIMMText{text: qsTr("EJE.PRES")}
            ICIMMStatusWidget{
//                id:c_ro_0_32_2_1541
//                bindStatus: "c_ro_0_32_2_1541"
            }
            ICIMMText{text: qsTr("bar")}

            ICIMMText{text: qsTr("DM.SPE")}
            ICIMMStatusWidget{
            }
            ICIMMText{text: qsTr("%")}
            ICIMMText{text: "    "}
            ICIMMText{text: qsTr("EJE.SPE")}
            ICIMMStatusWidget{
//                id:c_ro_0_32_2_1544
//                bindStatus: "c_ro_0_32_2_1544"
            }
            ICIMMText{text: qsTr("%")}

            ICIMMText{text: qsTr("INJ.POSN")}
            ICIMMStatusWidget{
                id:c_ro_0_32_2_1542
                bindStatus: "c_ro_0_32_2_1542"
            }
            ICIMMText{text: qsTr("mm")}
            ICIMMText{text: "    "}
            ICIMMText{text: qsTr("NOZ.POSN")}
            ICIMMStatusWidget{
                id:c_ro_0_32_2_1543
                bindStatus: "c_ro_0_32_2_1543"
            }
            ICIMMText{text: qsTr("mm")}

            ICIMMText{text: qsTr("INJ.PRES")}
            ICIMMStatusWidget{
            }
            ICIMMText{text: qsTr("bar")}
            ICIMMText{text: "    "}
            ICIMMText{text: qsTr("NOZ.PRES")}
            ICIMMStatusWidget{

            }
            ICIMMText{text: qsTr("bar")}

            ICIMMText{text: qsTr("INJ.SPE")}
            ICIMMStatusWidget{

            }
            ICIMMText{text: qsTr("%")}
            ICIMMText{text: "    "}
            ICIMMText{text: qsTr("NOZ.SPE")}
            ICIMMStatusWidget{
            }
            ICIMMText{text: qsTr("%")}
        }
    }
}

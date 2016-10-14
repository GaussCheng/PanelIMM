import QtQuick 1.1
import "../../ICCustomElement"
import "../immcustomitems"
Item {
    ICStatusScope{
        Grid{
            x:4
            y:2
            columns: 7
            ICIMMText{text: qsTr("C.C")}
            ICIMMStatusWidget{
                id:c_ro_0_32_1_1569
                bindStatus: "c_ro_0_32_1_1569"
            }
            ICIMMText{text: qsTr("s")}
            ICIMMText{text: "    "}
            ICIMMText{text: qsTr("INJ.POSN")}
            ICIMMStatusWidget{
                id:c_ro_0_32_2_1542
                bindStatus: "c_ro_0_32_2_1542"
            }
            ICIMMText{text: qsTr("mm")}

            ICIMMText{text: qsTr("INJ.TIME")}
            ICIMMStatusWidget{
                id:c_ro_0_16_1_1579
                bindStatus: "c_ro_0_16_1_1579"
            }
            ICIMMText{text: qsTr("s")}
            ICIMMText{text: "    "}
            ICIMMText{text: qsTr("DM.POSN")}
            ICIMMStatusWidget{
                id:c_ro_0_32_2_1541
                bindStatus: "c_ro_0_32_2_1541"
            }
            ICIMMText{text: qsTr("mm")}

            ICIMMText{text: qsTr("Feed.TIME")}
            ICIMMStatusWidget{
            }
            ICIMMText{text: qsTr("s")}
            ICIMMText{text: "    "}
            ICIMMText{text: qsTr("EJE.POSN")}
            ICIMMStatusWidget{
                id:c_ro_0_32_2_1544
                bindStatus: "c_ro_0_32_2_1544"
            }
            ICIMMText{text: qsTr("mm")}

            ICIMMText{text: qsTr("INJ.MPRES")}
            ICIMMStatusWidget{
            }
            ICIMMText{text: qsTr("bar")}
            ICIMMText{text: "    "}
            ICIMMText{text: qsTr("HOLD.POSN")}
            ICIMMStatusWidget{
                id:c_ro_16_16_1_1578
                bindStatus: "c_ro_16_16_1_1578"
            }
            ICIMMText{text: qsTr("mm")}

            ICIMMText{text: qsTr("B.P.MPRES")}
            ICIMMStatusWidget{
            }
            ICIMMText{text: qsTr("bar")}
            ICIMMText{text: "    "}
            ICIMMText{text: qsTr("Feed.SPE")}
            ICIMMStatusWidget{
                id:c_ro_0_32_0_1570
                bindStatus: "c_ro_0_32_0_1570"
            }
            ICIMMText{text: qsTr("rpm")}

            ICIMMText{text: qsTr("INJ.E.POSN")}
            ICIMMStatusWidget{
                id:c_ro_0_16_1_1578
                bindStatus: "c_ro_0_16_1_1578"
            }
            ICIMMText{text: qsTr("mm")}
            ICIMMText{text: "    "}
            ICIMMText{text: qsTr("Feed.E.POSN")}
            ICIMMStatusWidget{
                id:c_ro_16_16_1_1579
                bindStatus: "c_ro_16_16_1_1579"
            }
            ICIMMText{text: qsTr("mm")}
        }
    }
}

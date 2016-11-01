import QtQuick 1.1
import "../../ICCustomElement"
import "../immcustomitems"
import "../../styles/style.js" as Style
ICIMMFunctionPageBase {
    id:instance
    ICSettingPageBase{
        id:page1
        width: parent.width
        height: parent.height
        onEditorFocusChanged: {
            instance.editorFocusChanged(now);
        }
        Row{
            ICIMMLabelLineEdit{
                id:addr
                isNumberOnly: false
                configName: qsTr("Addr")
                softkeyboardEn: true
            }

            ICIMMLabelLineEdit{
                id:val
                configName: qsTr("name")
                configAddr: addr.configValue
                onEditFinished: {
                    panelController.setConfigValue(addr.configValue, configValue);
                    panelController.syncConfigs();
                }
            }
        }

    }

}

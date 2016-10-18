import QtQuick 1.1
import "../../ICCustomElement"
import "../monitorpages/ICOperationLog.js" as ICOperationLog

ICSettingConfigsScope {
    onConfigValueChanged: {
//        console.log(addr, newV, oldV)
        ICOperationLog.appendNumberConfigOperationLog(addr, newV, oldV);
    }
}

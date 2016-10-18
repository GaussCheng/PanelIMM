TRANSLATIONS += translations/IMM_zh_CN.ts translations/IMM_en_US.ts
lupdate_only{
SOURCES = *.qml \
          *.js \
../ICCustomElement/* \
immcustomitems/* \
settingpages/* \
monitorpages/* \
configs/* \
../styles/*
}

OTHER_FILES += \
    monitorpages/ICBlowCVMonitorPage.qml \
    settingpages/ICInjectFuncPage.qml \
    settingpages/ICTemperatureFuncPage.qml \
    monitorpages/ICTemperatureMonitorPage.qml \
    immcustomitems/ICIMMTimeLineEdit.qml \
    monitorpages/ICTemperaturePIDCVMonitorPage.qml \
    monitorpages/ICTemperatureAidCVMonitorPage.qml \
    monitorpages/ICTemperatureBlowCVMonitorPage.qml \
    settingpages/ICCoreFuncPage.qml \
    monitorpages/ICCoreAidCVMonitorPage.qml \
    settingpages/ICCarrFuncPage.qml \
    immcustomitems/ICIMMSettingConfigsScope.qml






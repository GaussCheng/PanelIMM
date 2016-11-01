QT       += script
#TEMPLATE = app
VERSION = 1.0.0
VERSTR = '\\"$${VERSION}\\"'
DEFINES += UART_COMM
DEFINES += SW_VER=\"$${VERSTR}\"

QMAKE_CXX = ccache $${QMAKE_CXX}

#DEFINES += COMM_DEBUG
suffix = $${VERSION}
CONFIG(debug, debug|release) {
suffix = $${suffix}_debug
DEFINES += TTYPORT='\\"/dev/ttyUSB1\\"'
}
else{
suffix = $${suffix}_release
DEFINES += TTYPORT='\\"/dev/ttySZHC0\\"'
}
DESTDIR = bin_$${suffix}
OBJECTS_DIR = temp_$${suffix}
UI_DIR = temp_$${suffix}
MOC_DIR = temp_$${suffix}
RCC_DIR = temp_$${suffix}

INCLUDEPATH += vendor/protocol/

SK_SIZE = 15


# Add more folders to ship with the application, here
#folder_01.source = qml/PanelIMM
#folder_01.target = qml
#DEPLOYMENTFOLDERS = folder_01

ICCustomElement.source = qml/ICCustomElement
ICCustomElement.target = qml
utils.source = qml/utils
utils.target = qml
init.source = Init
init.target = .
styles.source = qml/styles
styles.target = qml
DEPLOYMENTFOLDERS =  ICCustomElement utils init styles

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =


include(vendor/IndustrialSystemFramework/ICCore/ICCore.pri)
include(vendor/IndustrialSystemFramework/ICUtility/ICUtility.pri)
include(vendor/IndustrialSystemFramework/ICAlgorithm/ICAlgorithm.pri)
include(vendor/IndustrialSystemFramework/QJson/QJson.pri)
include(controller/controller.pri)
include(common/common.pri)
include(datamanerger/datamanerger.pri)
include(virtualhost/virtualhost.pri)
include(extentuis/extentuis.pri)
# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp

# Installation path
# target.path =

# Please do not modify the following two lines. Required for deployment.
include(qtquick1applicationviewer/qtquick1applicationviewer.pri)
qtcAddDeployment()


configAddrTarget.target = .genAddr
configAddrTarget.commands = python3 tools/addrgen_new_plat.py ./vendor/protocol/hccommparagenericdef.h vendor/IndustrialSystemFramework/ICCore/icaddrwrapper.h ./vendor/protocol/icdefaultconfig.csv common $${RCC_DIR}
buildDB.target = .buildDB
buildDB.commands = sqlite3 $${DESTDIR}/RobotDatabase < $${RCC_DIR}/db.sql
buildDB.depends = configAddrTarget
QMAKE_EXTRA_TARGETS += buildDB
QMAKE_EXTRA_TARGETS += configAddrTarget
PRE_TARGETDEPS += .genAddr


reinstallDir = tools/Reinstall/
updateDir = tools/Update

target.path = /opt/Qt/apps



#db.path = /opt/Qt/apps/
#db.files += $${reinstallDir}/RobotDatabase
qmap.path = /home/root
qmap.files += $${reinstallDir}/$${SK_SIZE}-inch-qmap/*
usr_bin_scripts.path = /usr/bin
#usr_bin_scripts.files += $${reinstallDir}/usr_bin_scripts/*
usr_bin_scripts.files += $${reinstallDir}/$${SK_SIZE}RunApp/*
#usr_sbin_scripts.path = /usr/sbin
#usr_sbin_scripts.files += $${reinstallDir}/usr_sbin_scripts/*
configs.path = /opt/Qt/apps/sysconfig
configs.files += $${reinstallDir}/configs/PanelRobot.ini
testapp.path = /opt/Qt/apps
#testapp.files += $${reinstallDir}/3a8HardwareTest*

qmls.path = $${target.path}/qml
qmls.files += qml/PanelIMM*

CONFIG(release, debug|release) {
message("in release")
db.path = /opt/Qt/apps/
db.files += $${reinstallDir}/RobotDatabase
}
CONFIG(Reinstall, debug|release|Reinstall){
message("in Reinstall")
INSTALLS += db configs
}

INSTALLS += qmap qmls usr_bin_scripts

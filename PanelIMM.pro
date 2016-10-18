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
}
else{
suffix = $${suffix}_release
}
DESTDIR = bin_$${suffix}
OBJECTS_DIR = temp_$${suffix}
UI_DIR = temp_$${suffix}
MOC_DIR = temp_$${suffix}
RCC_DIR = temp_$${suffix}

INCLUDEPATH += vendor/protocol/




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
DEPLOYMENTFOLDERS =  ICCustomElement utils init

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

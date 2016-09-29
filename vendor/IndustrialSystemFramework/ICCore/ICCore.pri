#-------------------------------------------------
#
# Project created by QtCreator 2011-07-22T09:45:09
#
#-------------------------------------------------
INCLUDEPATH += $$PWD

#include("$$PWD/ICPeripherals/icperipherals.pri")
include("$$PWD/ICCommunication/iccommunication.pri")
include("$$PWD/ICLogSystem/iclogsystem.pri")
include("$$PWD/ICLevelManager/ICLevelManager.pri")

SOURCES += \
    $$PWD/icaddrwrapper.cpp \
    $$PWD/icparameterscache.cpp \
    $$PWD/icpanelcontroller.cpp \
    vendor/IndustrialSystemFramework/ICCore/icmoldbase.cpp

HEADERS +=\
        $$PWD/ICCore_global.h \
    $$PWD/icaddrwrapper.h \
    $$PWD/icparameterscache.h \
    $$PWD/icpanelcontroller.h \
    vendor/IndustrialSystemFramework/ICCore/icmoldbase.h

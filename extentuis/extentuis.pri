include(../vendor/qwt/qwtconfig.pri)
include(../vendor/qwt/qwt.pri)
include(icplots/icplots.pri)
INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

HEADERS += \
    extentuis/icaxis.h \
    extentuis/ictemperaturecurve.h \
    extentuis/icinjectcurve.h

SOURCES += \
    extentuis/icaxis.cpp \
    extentuis/ictemperaturecurve.cpp \
    extentuis/icinjectcurve.cpp

FORMS +=


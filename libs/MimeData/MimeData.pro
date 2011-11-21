#-------------------------------------------------
#
# Project created by QtCreator 2011-11-21T20:09:09
#
#-------------------------------------------------

QT       += script

QT       -= gui

TARGET = MimeData
TEMPLATE = lib

DEFINES += MIMEDATA_LIBRARY

SOURCES += mimedata.cpp
unix{
    OBJECTS_DIR = ./obj/
    MOC_DIR = ./obj/
    DESTDIR = ../../bin/
    UI_DIR = ./obj/
}
HEADERS += mimedata.h\
        MimeData_global.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE7FA561B
    TARGET.CAPABILITY =
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = MimeData.dll
    addFiles.path = !:/sys/bin
    DEPLOYMENT += addFiles
}

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

RESOURCES += \
    mimetypes.qrc




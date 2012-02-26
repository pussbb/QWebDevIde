#-------------------------------------------------
#
# Project created by QtCreator 2012-02-26T18:35:41
#
#-------------------------------------------------

QT       += core gui
TARGET = PluginManager
TEMPLATE = lib

DEFINES += PLUGINMANAGER_LIBRARY

SOURCES += pluginmanager.cpp

HEADERS += pluginmanager.h\
        PluginManager_global.h \
    iplugin.h

unix{
    OBJECTS_DIR = ./obj/
    MOC_DIR = ./obj/
    DESTDIR = ../../bin/
    UI_DIR = ./obj/
}
symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xEC776B8C
    TARGET.CAPABILITY =
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = PluginManager.dll
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

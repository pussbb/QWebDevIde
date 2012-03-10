QT += core gui
TARGET = FileBrowser
TEMPLATE = lib
CONFIG += plugin
include("../commonplugin.pri")
INCLUDEPATH += $$PWD/

DEPENDPATH += $$PWD/

SOURCES += filebrowser.cpp \
    filesystembrowser.cpp

HEADERS += filebrowser.h \
    filesystembrowser.h

unix{
    OBJECTS_DIR = ./obj/
    MOC_DIR = ./obj/
    DESTDIR = ../../bin/plugins/
    UI_DIR = ./obj/
}





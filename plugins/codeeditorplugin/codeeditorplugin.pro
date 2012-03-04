QT += core gui
TEMPLATE = lib
TARGET = CodeEditor
CONFIG += plugin

INCLUDEPATH += ./

SOURCES += codeeditorplugin.cpp

HEADERS += codeeditorplugin.h

unix{
    OBJECTS_DIR = ./obj/
    MOC_DIR = ./obj/
    DESTDIR = ../../bin/plugins/
    UI_DIR = ./obj/
}

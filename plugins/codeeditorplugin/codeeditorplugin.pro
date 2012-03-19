QT += core gui
TEMPLATE = lib
TARGET = CodeEditor
CONFIG += plugin

include("../commonplugin.pri")
include("../json.pri")
include("./codeeditor_dependencies.pri")

SOURCES += codeeditorplugin.cpp \
    codeeditor/codeeditor.cpp \
    codeeditor/textblockdata.cpp

unix{
    OBJECTS_DIR = ./obj/
    MOC_DIR = ./obj/
    DESTDIR = ../../bin/plugins/
    UI_DIR = ./obj/
}

HEADERS += \
    global.h













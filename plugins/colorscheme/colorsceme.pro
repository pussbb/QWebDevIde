QT += core
TARGET = ColorScheme
TEMPLATE = lib
CONFIG += plugin

include ("../json.pri")
include("../codeeditorplugin/codeeditor_dependencies.pri")
SOURCES += colorscheme.cpp

HEADERS += colorscheme.h

unix{
    OBJECTS_DIR = ./obj/
    MOC_DIR = ./obj/
    DESTDIR = ../../bin/plugins/
    UI_DIR = ./obj/
}



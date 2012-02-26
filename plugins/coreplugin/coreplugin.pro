QT += core gui
TARGET = Core
TEMPLATE = lib
CONFIG += plugin

INCLUDEPATH += ./

SOURCES += coreplugin.cpp

HEADERS += coreplugin.h

unix{
    OBJECTS_DIR = ./obj/
    MOC_DIR = ./obj/
    DESTDIR = ../../bin/plugins/
    UI_DIR = ./obj/
}

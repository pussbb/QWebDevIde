QT += core
TARGET = SyntaxHighlighter
TEMPLATE = lib
CONFIG += plugin

include ("../json.pri")
include("../codeeditorplugin/codeeditor_dependencies.pri")

SOURCES += syntaxhighlighter.cpp \
    highlighter.cpp \
    abstractsyntaxhighlight.cpp \
    highlightmanager.cpp

HEADERS += syntaxhighlighter.h \
    highlighter.h \
    abstractsyntaxhighlight.h \
    highlightmanager.h


unix{
    OBJECTS_DIR = ./obj/
    MOC_DIR = ./obj/
    DESTDIR = ../../bin/plugins/
    UI_DIR = ./obj/
}







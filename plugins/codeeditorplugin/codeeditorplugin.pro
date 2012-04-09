QT += core gui
TEMPLATE = lib
TARGET = CodeEditor
CONFIG += plugin

include("../commonplugin.pri")
include("../json.pri")
include("./codeeditor_dependencies.pri")
include("../../3rdparty/qtcreator/fancywidgets.pri")
SOURCES += codeeditorplugin.cpp \
    codeeditor/codeeditor.cpp \
    codeeditor/textblockdata.cpp \
    findwidget.cpp
INCLUDEPATH += $$PWD

DEPENDPATH += $$PWD/

unix{
    OBJECTS_DIR = ./obj/
    MOC_DIR = ./obj/
    DESTDIR = ../../bin/plugins/
    UI_DIR = ./obj/
}

HEADERS += \
    global.h \
    findwidget.h

FORMS += \
    findwidget.ui













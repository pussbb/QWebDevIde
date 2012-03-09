QT += core gui script
TARGET = ProjectManager
TEMPLATE = lib
CONFIG += plugin
include("../commonplugin.pri")

include("../../qwebdevide/qwebdevide.pri")
include(../../3rdparty/qtjsonsettings/qtjsonsettings.pri)
INCLUDEPATH += $$PWD/ \
    $$PWD/../../libs/MimeData/

DEPENDPATH += $$PWD/ \
    $$PWD/../../libs/MimeData/

SOURCES += projectmanager.cpp \
    projectexplorer/projectexplorer.cpp \
    projectexplorer/filetemplates.cpp \
    projects.cpp \
    abstractproject.cpp

HEADERS += projectmanager.h \
    projectexplorer/projectexplorer.h \
    projectexplorer/filetemplates.h \
    projects.h \
    abstractproject.h

unix{
    OBJECTS_DIR = ./obj/
    MOC_DIR = ./obj/
    DESTDIR = ../../bin/plugins/
    UI_DIR = ./obj/
}

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../bin/release/ -lMimeData
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../bin/debug/ -lMimeData
else:symbian: LIBS += -lMimeData
else:unix: LIBS += -L$$PWD/../../bin/ -lMimeData

FORMS += \
    projectexplorer/projectexplorer.ui










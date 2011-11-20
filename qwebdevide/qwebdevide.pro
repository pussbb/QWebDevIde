#-------------------------------------------------
#
# Project created by QtCreator 2011-10-09T11:21:49
#core gui sql
#-------------------------------------------------
QT       += core gui
include(../3rdparty/qtcreator/fancywidgets.pri)
TARGET = qwebdevide
INCLUDEPATH += $$PWD/codeeditor \
                $$PWD/wizard
TEMPLATE = app
unix{
    OBJECTS_DIR = ./obj/
    MOC_DIR = ./obj/
    DESTDIR = ../bin/
    UI_DIR = ./obj/
}
TRANSLATIONS = ../lang/qwebdevide_ru.ts \
                ../lang/qwebdevide_def.ts \
                ../lang/qwebdevide_en.ts
SOURCES += main.cpp\
        qwebdevide.cpp \
        qcorewindow.cpp \
    rightpane/rightpane.cpp \
    rightpane/filesystembrowser.cpp \
    projectmanager.cpp \
    bookmarkmanager.cpp \
    editorsmanager.cpp \
    codeeditor/codeeditor.cpp \
    codeeditor/highlighter.cpp \
    wizard/wizard.cpp \
    wizard/startpage.cpp \
    wizard/commonsettings.cpp


HEADERS  += qwebdevide.h \
            qcorewindow.h \
    rightpane/rightpane.h \
    rightpane/filesystembrowser.h \
    projectmanager.h \
    bookmarkmanager.h \
    editorsmanager.h \
    codeeditor/codeeditor.h \
    codeeditor/highlighter.h \
    wizard/wizard.h \
    wizard/startpage.h \
    wizard/commonsettings.h \
    wizard/pagedata.h

FORMS    += qwebdevide.ui \
    rightpane/rightpane.ui \
    wizard/wizard.ui \
    wizard/startpage.ui \
    wizard/commonsettings.ui

RESOURCES += \
    resource/app.qrc \
    resource/lang.qrc


#-------------------------------------------------
#
# Project created by QtCreator 2011-10-09T11:21:49
#core gui sql
#-------------------------------------------------
QT       += core gui
include(../3rdparty/qtcreator/fancywidgets.pri)
TARGET = qwebdevide

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
    rightpane/filesystembrowser.cpp


HEADERS  += qwebdevide.h \
            qcorewindow.h \
    rightpane/rightpane.h \
    rightpane/filesystembrowser.h

FORMS    += qwebdevide.ui \
    rightpane/rightpane.ui
RESOURCES += \
    resource/app.qrc \
    resource/lang.qrc

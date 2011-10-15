#-------------------------------------------------
#
# Project created by QtCreator 2011-10-09T11:21:49
#core gui sql
#-------------------------------------------------
QT       += core gui
include(../3rdparty/qtcreator/fancywidgets.pri)
TARGET = qwebdevide
DEFINES += QT_SQL_LIB CORE_LIBRARY QTCREATOR_UTILS_LIB
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
        qcorewindow.cpp


HEADERS  += qwebdevide.h \
            qcorewindow.h

FORMS    += qwebdevide.ui
RESOURCES += \
    resource/app.qrc \
    resource/lang.qrc





























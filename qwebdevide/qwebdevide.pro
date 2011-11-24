#-------------------------------------------------
#
# Project created by QtCreator 2011-10-09T11:21:49
#core gui sql
#-------------------------------------------------
QT       += core gui script
include(../3rdparty/qtcreator/fancywidgets.pri)
include(../3rdparty/qtjsonsettings/qtjsonsettings.pri)

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
    wizard/commonsettings.cpp \
    abstractproject.cpp \
    rightpane/projectexplorer.cpp \
    rightpane/filetemplates.cpp


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
    wizard/pagedata.h \
    abstractproject.h \
    rightpane/projectexplorer.h \
    rightpane/filetemplates.h

FORMS    += qwebdevide.ui \
    rightpane/rightpane.ui \
    wizard/wizard.ui \
    wizard/startpage.ui \
    wizard/commonsettings.ui \
    rightpane/projectexplorer.ui

RESOURCES += \
    resource/app.qrc \
    resource/lang.qrc


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../bin/release/ -lMimeData
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../bin/debug/ -lMimeData
else:symbian: LIBS += -lMimeData
else:unix: LIBS += -L$$PWD/../bin/ -lMimeData

INCLUDEPATH += $$PWD/../libs/MimeData
DEPENDPATH += $$PWD/../libs/MimeData






#-------------------------------------------------
#
# Project created by QtCreator 2011-10-09T11:21:49
#core gui sql
#-------------------------------------------------
QT       += core gui script
include(../3rdparty/qtcreator/fancywidgets.pri)
include(../3rdparty/qtjsonsettings/qtjsonsettings.pri)

TARGET = qwebdevide
INCLUDEPATH += $$PWD/wizard
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
    bookmarkmanager.cpp \
    editorsmanager.cpp \
    wizard/wizard.cpp \
    wizard/startpage.cpp \
    wizard/commonsettings.cpp \
    editingwidget.cpp \
    editedfiles.cpp

HEADERS  += qwebdevide.h \
            qcorewindow.h \
    rightpane/rightpane.h \
    bookmarkmanager.h \
    editorsmanager.h \
    wizard/wizard.h \
    wizard/startpage.h \
    wizard/commonsettings.h \
    wizard/pagedata.h \
    editingwidget.h \
    editedfiles.h


FORMS    += qwebdevide.ui \
    rightpane/rightpane.ui \
    wizard/wizard.ui \
    wizard/startpage.ui \
    wizard/commonsettings.ui \
    editingwidget.ui

RESOURCES += \
    resource/app.qrc \
    resource/lang.qrc


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../bin/release/ -lMimeData
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../bin/debug/ -lMimeData
else:symbian: LIBS += -lMimeData
else:unix: LIBS += -L$$PWD/../bin/ -lMimeData

INCLUDEPATH += $$PWD/../libs/MimeData
DEPENDPATH += $$PWD/../libs/MimeData

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../bin/ -lPluginManager
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../bin/ -lPluginManagerd
else:symbian: LIBS += -lPluginManager
else:unix: LIBS += -L$$PWD/../bin/ -lPluginManager

INCLUDEPATH += $$PWD/../libs/PluginManager
DEPENDPATH += $$PWD/../libs/PluginManager


unix:{
  QMAKE_LFLAGS += -Wl,--rpath=../bin/
  QMAKE_LFLAGS_RPATH=
}


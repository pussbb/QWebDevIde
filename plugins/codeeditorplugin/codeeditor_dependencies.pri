
include("../commonplugin.pri")
INCLUDEPATH += $$PWD/ \
    $$PWD/codeeditor/

DEPENDPATH += $$PWD/codeeditor/

HEADERS += $$PWD/codeeditorplugin.h \
    $$PWD/codeeditor/codeeditor.h \
    $$PWD/codeeditor/textblockdata.h

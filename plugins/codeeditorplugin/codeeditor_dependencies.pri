
include("../commonplugin.pri")
INCLUDEPATH += $$PWD/ \
    $$PWD/codeeditor/

DEPENDPATH += $$PWD/codeeditor/

HEADERS += codeeditorplugin.h \
    codeeditor/codeeditor.h \
    codeeditor/textblockdata.h

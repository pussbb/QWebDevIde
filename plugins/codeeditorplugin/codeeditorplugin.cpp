#include "codeeditorplugin.h"
#include "QDebug"

QStringList CodeEditorPlugin::dependencies() const
{
    return QStringList() << "Core";
}


void CodeEditorPlugin::init(QMap<QString, QObject *> dependencies)
{
    CorePlugin *cp = static_cast<CorePlugin *>(dependencies.value("Core"));
    qDebug()<< cp->menuBar;
}

Q_EXPORT_PLUGIN2(CodeEditor, CodeEditorPlugin);



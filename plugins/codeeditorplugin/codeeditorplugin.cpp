#include "codeeditorplugin.h"


QStringList CodeEditorPlugin::dependencies() const
{
    return QStringList() << "Core";
}


void CodeEditorPlugin::init()
{

}

Q_EXPORT_PLUGIN2(CodeEditor, CodeEditorPlugin);



#include "codeeditorplugin.h"
#include "QDebug"

QStringList CodeEditorPlugin::dependencies() const
{
    return QStringList() << "Core";
}


void CodeEditorPlugin::init(QMap<QString, QObject *> dependencies, QObject *parent)
{
    Q_UNUSED(dependencies);
    //CorePlugin *cp = static_cast<CorePlugin *>(dependencies.value("Core"));
    //qDebug()<< cp->menuBar;

}
QWidget * CodeEditorPlugin::open(const QString &file)
{
    CodeEditor *editor = new CodeEditor();
    editor->openFile(file);
    QFileInfo fi(file);
    openedFiles.insert(fi.fileName(), editor);
    emit(editorCreated(editor));
    return editor;
}

bool CodeEditorPlugin::save(const QString &fileName)
{
    CodeEditor *editor = openedFiles.value(fileName);
    editor->saveFile();
    return true;
}

void CodeEditorPlugin::close(const QString &fileName)
{

}

QStringList CodeEditorPlugin::mimeTypes()
{
    return QStringList() << "unknown"
                         << "default"
                         << "application/x-php"
                         << "application/javascript"
                         << "text/css"
                         << "text/html"
                         << "text/plain";
}



Q_EXPORT_PLUGIN2(CodeEditor, CodeEditorPlugin);







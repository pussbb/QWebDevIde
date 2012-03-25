#include "codeeditorplugin.h"
#include "QDebug"

QStringList CodeEditorPlugin::dependencies() const
{
    return QStringList();
}

void CodeEditorPlugin::init(QMap<QString, QObject *> dependencies, QObject *parent)
{
    Q_UNUSED(dependencies);
    Q_UNUSED(parent);
}

QWidget * CodeEditorPlugin::open(const QString &file, const QString &fileId)
{
    CodeEditor *editor = new CodeEditor();
    editor->openFile(file);
    QFileInfo fi(file);
    openedFiles.insert(fileId, editor);
    emit(editorCreated(editor,fileId));
    return editor;
}

bool CodeEditorPlugin::save(const QString &fileId)
{
;
    openedFiles.value(fileId)->saveFile();
    return true;
}

void CodeEditorPlugin::close(const QString &fileId)
{
    openedFiles.value(fileId)->deleteLater();
    openedFiles.remove(fileId);
    emit(aboutToClose(fileId));
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







#include "editorsmanager.h"

EditorsManager::EditorsManager(QObject *parent) :
    QObject(parent)
{
    m_editingWidget = new EditingWidget(0);
    connect(m_editingWidget,SIGNAL(closeFile(QString)),
            this,SLOT(closeFile(QString)));
}

void EditorsManager::openFile(QString file)
{
    QFileInfo fi(file);
    QString mimeType = mime.getMimeType(fi.fileName());

    if ( fi.isDir())
        mimeType = "folder";

    IEditors *editor = editors.value(mime.getMimeType(file));
    if ( editor == NULL) {
        editor = editors.value("default");
        if ( editor == NULL)
            return;
    }

    if (mimeType == "folder" || mimeType == "application/web.dev.ide") {
        editor->open(file);
        return;
    }

    m_openedFiles.insert(fi.fileName(), editor);
    openedFiles.insert(fi.fileName(),editor->open(file));
    m_editingWidget->refreshFileList(openedFiles);
    m_editingWidget->setCurrent(fi.fileName());

}

void EditorsManager::closeFile(QString file)
{
    QWidget *editorWidget = openedFiles.value(file);
    IEditors *editor =m_openedFiles.value(file);
    if( editor != NULL) {
        editor->close(file);
        editorWidget->deleteLater();
        openedFiles.remove(file);
        m_openedFiles.remove(file);
        m_editingWidget->refreshFileList(openedFiles);
    }
}

void EditorsManager::saveCurrent()
{

    IEditors *editor = m_openedFiles.value(m_editingWidget->currentFileName);
    if (editor == NULL)
        return;
    editor->save(m_editingWidget->currentFileName);
}

void EditorsManager::initPlugins(QMap<QString, QObject *> list)
{
    foreach(QString name, list.keys()) {
        IEditors *iEditor = qobject_cast<IEditors *>(list.value(name));
        if (iEditor)
        {
            foreach(const QString &mime, iEditor->mimeTypes()) {
                editors.insert(mime, iEditor);
            }
        }
    }
}

void EditorsManager::saveAll()
{
}



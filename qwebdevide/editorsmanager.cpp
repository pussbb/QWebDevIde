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

    QString fileId = fi.fileName();
    QString hashId = QCryptographicHash::hash(fi.absoluteFilePath().toLatin1(), QCryptographicHash::Md5).toHex();

    if ( openedFiles.contains(fileId) ) {
        if ( isOpened(fileId, fi) || isOpened(hashId, fi))
            return;
        fileId = hashId;
    }

    if ( fi.isDir())
        mimeType = "folder";

    IEditors *editor = editors.value(mime.getMimeType(file));
    if ( editor == NULL) {
        editor = editors.value("default");
        if ( editor == NULL)
            return;
    }

    if (mimeType == "folder" || mimeType == "application/web.dev.ide") {
        editor->open(file, fileId);
        return;
    }

    EditedFile editedFile;
    editedFile.fi = fi;
    editedFile.widget = editor->open(file, fileId);
    editedFile.editorInterface = editor;

    openedFiles.insert(fileId,editedFile);

    m_editingWidget->refreshFileList(openedFiles);
    m_editingWidget->setCurrent(fileId);

}

void EditorsManager::closeFile(QString fileId)
{
    EditedFile editedFile = openedFiles.value(fileId);
    if( editedFile.editorInterface != NULL) {
        editedFile.editorInterface->close(fileId);
        editedFile.widget->deleteLater();
        openedFiles.remove(fileId);
        m_editingWidget->refreshFileList(openedFiles);
    }
}

void EditorsManager::saveCurrent()
{

    IEditors *editor = openedFiles.value(m_editingWidget->currentFileId).editorInterface;
    if (editor == NULL)
        return;
    editor->save(m_editingWidget->currentFileId);
}

void EditorsManager::initPlugins(QMap<QString, QObject *> list)
{
    foreach(QString name, list.keys()) {
        IEditors *editor = qobject_cast<IEditors *>(list.value(name));
        if (editor)
        {
            foreach(const QString &mime, editor->mimeTypes()) {
                editors.insert(mime, editor);
            }
        }
    }
}

void EditorsManager::saveAll()
{
    foreach (const QString &fileId, openedFiles.keys()) {
        IEditors *editor = openedFiles.value(fileId).editorInterface;
        if ( editor)
            editor->save(fileId);
    }
}

bool EditorsManager::isOpened(const QString &fileId, const QFileInfo &fi)
{
    if ( openedFiles.contains(fileId) ) {
        EditedFile esixting = openedFiles.value(fileId);
        if ( fi.absoluteFilePath() == esixting.fi.absoluteFilePath()) {
            m_editingWidget->setCurrent(fileId);
            return true;
        }
    }
    return false;
}



#include "editorsmanager.h"

EditorsManager::EditorsManager(QObject *parent) :
    QObject(parent)
{
    editedFiles = new EditedFiles(this);
    m_editingWidget = new EditingWidget(NULL,editedFiles);
}

void EditorsManager::openFile(QString file)
{
    QFileInfo fi(file);
    QString mimeType = mime.getMimeType(fi.fileName());

    QString fileId = fi.fileName();
    QString hashId = QCryptographicHash::hash(fi.absoluteFilePath().toLatin1(), QCryptographicHash::Md5).toHex();

    if ( editedFiles->openedFiles.contains(fileId) ) {
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
    editedFile.changed = false;

    editedFiles->openedFiles.insert(fileId,editedFile);

    m_editingWidget->refreshFileList();
    m_editingWidget->setCurrent(fileId);

}

void EditorsManager::closeFile(QString fileId)
{
     editedFiles->closeFile(fileId);
}

void EditorsManager::saveCurrent()
{

    IEditors *editor = editedFiles->openedFiles.value(m_editingWidget->currentFileId).editorInterface;
    if (editor == NULL)
        return;
    if ( editor->save(m_editingWidget->currentFileId))
    {
        editedFiles->changeState(m_editingWidget->currentFileId,false);
        m_editingWidget->markAsSaved(m_editingWidget->currentFileId);
    }

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
    foreach (const QString &fileId, editedFiles->openedFiles.keys()) {
        IEditors *editor = editedFiles->openedFiles.value(fileId).editorInterface;
        if ( editor) {
            if (editor->save(fileId)) {
                editedFiles->changeState(fileId,false);
                m_editingWidget->markAsSaved(fileId);
            }

        }
    }
}

bool EditorsManager::isOpened(const QString &fileId, const QFileInfo &fi)
{
    if ( editedFiles->openedFiles.contains(fileId) ) {
        EditedFile esixting = editedFiles->openedFiles.value(fileId);
        if ( fi.absoluteFilePath() == esixting.fi.absoluteFilePath()) {
            m_editingWidget->setCurrent(fileId);
            return true;
        }
    }
    return false;
}


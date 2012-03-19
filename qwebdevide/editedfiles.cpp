#include <editedfiles.h>

EditedFiles::EditedFiles(QObject *parent):
    QObject(parent)
{

}

EditedFiles::~EditedFiles()
{
    foreach(const QString &fileId, openedFiles.keys()) {
        deleteItem(fileId);
    }
}

void EditedFiles::changeState(QString fileId, bool state)
{
    EditedFile editedFile = openedFiles.value(fileId);
    editedFile.changed = state;
    openedFiles.insert(fileId, editedFile);
    ( state) ? ++changedCount : --changedCount;
}

bool EditedFiles::closeFile(const QString &fileId, bool autoSave )
{
    EditedFile editedFile = openedFiles.value(fileId);
    if ( editedFile.changed && ! autoSave) {
        QMessageBox msgBox;
        msgBox.setText("Do you realy whant to close file without saving.");
        msgBox.setInformativeText("It will discart all your changes that you made");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::No | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Cancel);
        int state = msgBox.exec();
        if( state == QMessageBox::Save) {
            editedFile.editorInterface->save(fileId);
        }
        else if (state == QMessageBox::Cancel){
            return false;
        }
    }
    else if (editedFile.changed && autoSave) {
        editedFile.editorInterface->save(fileId);
    }
    editedFile.editorInterface->close(fileId);
    editedFile.widget->deleteLater();
    editedFile.fi.~QFileInfo();
    openedFiles.remove(fileId);
    return true;
}

bool EditedFiles::closeAllFiles()
{
    int state = QMessageBox::YesToAll;
    if (changedCount > 0) {
        QMessageBox msgBox;
        msgBox.setText("Do you realy whant to close files without saving.");
        msgBox.setInformativeText("It will discart all your changes that you made");
        msgBox.setStandardButtons(QMessageBox::YesToAll | QMessageBox::NoToAll | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Cancel);
        state = msgBox.exec();
    }
    if ( state == QMessageBox::Cancel)
        return false;

    foreach(const QString &fileId, openedFiles.keys()) {
        if ( state == QMessageBox::YesToAll) {
            closeFile(fileId, true);
        }
        else {
            deleteItem(fileId);
        }
    }
    return true;
}

void EditedFiles::deleteItem(const QString &fileId)
{
    EditedFile editedFile = openedFiles.value(fileId);
    if( editedFile.editorInterface != NULL) {
        editedFile.editorInterface->close(fileId);
        editedFile.widget->deleteLater();
        openedFiles.remove(fileId);
    }
}



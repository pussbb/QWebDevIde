#include <editedfiles.h>

EditedFiles::EditedFiles(QObject *parent):
    QObject(parent)
{

}

void EditedFiles::changeState(QString fileId, bool state)
{
    EditedFile editedFile = openedFiles.value(fileId);
    editedFile.changed = true;
    openedFiles.insert(fileId, editedFile);
}



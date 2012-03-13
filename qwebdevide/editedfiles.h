#ifndef EDITORS_GLOBAL_H
#define EDITORS_GLOBAL_H

#include "../plugins/ifaces.h"
#include <QObject>
#include <QMessageBox>

struct EditedFile {
    QFileInfo fi;
    QWidget *widget;
    IEditors *editorInterface;
    bool changed;
};

class EditedFiles : public QObject
{
    Q_OBJECT
public:
    explicit EditedFiles(QObject *parent = 0);
    ~EditedFiles();
    QMap<QString, EditedFile> openedFiles;
    void changeState(QString fileId, bool state);
    bool closeFile(const QString &fileId, bool autoSave = false);
    bool closeAllFiles();
signals:

public slots:

private:
    int changedCount;
    void deleteItem(const QString &fileId);
};
#endif // EDITORS_GLOBAL_H

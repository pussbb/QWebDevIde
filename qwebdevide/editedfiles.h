#ifndef EDITORS_GLOBAL_H
#define EDITORS_GLOBAL_H

#include "../plugins/ifaces.h"
#include <QObject>

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
    QMap<QString, EditedFile> openedFiles;
    void changeState(QString fileId, bool state);
signals:

public slots:

};
#endif // EDITORS_GLOBAL_H

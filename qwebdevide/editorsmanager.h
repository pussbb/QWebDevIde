#ifndef EDITORMANAGER_H
#define EDITORMANAGER_H

#include <QObject>
#include <codeeditor.h>
#include <QDebug>
#include <QFile>
class EditorsManager : public QObject
{
    Q_OBJECT
public:
    explicit EditorsManager(QObject *parent = 0);
    CodeEditor *editor;
    void openProject(QString fileName);
signals:

public slots:
    void openFile(QString );
};

#endif // EDITORMANAGER_H

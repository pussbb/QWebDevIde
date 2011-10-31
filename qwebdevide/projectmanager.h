#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H

#include <QObject>
#include <QVariantMap>
#include <QDebug>
#include <codeeditor.h>
class ProjectManager : public QObject
{
    Q_OBJECT
public:
    explicit ProjectManager(QObject *parent = 0);
    QVariantMap openedFiles;
    QVariantMap bookmarks;
    CodeEditor *editor;
signals:

public slots:
    void openFile(QString );
};

#endif // PROJECTMANAGER_H

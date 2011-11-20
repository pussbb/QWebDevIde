#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H

#include <QObject>
#include <QVariantMap>
#include <QDebug>
#include <abstractproject.h>
#include <QFileInfo>
class ProjectManager : public QObject
{
    Q_OBJECT
public:
    explicit ProjectManager(QObject *parent = 0);
    QVariantMap openedFiles;
    QVariantMap bookmarks;

    void openProject(QString fileName);
    AbstractProject *current;
    QMap<QString,AbstractProject*> projects;
signals:
    void projectAdd();

};

#endif // PROJECTMANAGER_H

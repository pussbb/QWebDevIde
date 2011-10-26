#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H

#include <QObject>
#include <QVariantMap>
#include <QDebug>

class ProjectManager : public QObject
{
    Q_OBJECT
public:
    explicit ProjectManager(QObject *parent = 0);
    QVariantMap openedFiles;
    QVariantMap bookmarks;
signals:

public slots:
    void openFile(QString );
};

#endif // PROJECTMANAGER_H

#ifndef PROJECTS_H
#define PROJECTS_H

#include <QObject>
#include <QVariantMap>
#include <QDebug>
#include <abstractproject.h>
#include <QFileInfo>

class Projects : public QObject
{
    Q_OBJECT
public:
    explicit Projects(QObject *parent = 0);
    void openProject(QString fileName);
    void closeProject(QString projectName);
    AbstractProject *current;
    QMap<QString,AbstractProject*> projects;

signals:
    void projectAdded();

public slots:

};

#endif // PROJECTS_H

#include "projectmanager.h"

ProjectManager::ProjectManager(QObject *parent) :
    QObject(parent)
{
}

void ProjectManager::openFile(QString file)
{
    qDebug()<<"open file"<< file;
}

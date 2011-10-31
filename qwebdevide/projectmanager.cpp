#include "projectmanager.h"

ProjectManager::ProjectManager(QObject *parent) :
    QObject(parent)
{
}

#include <QFile>
void ProjectManager::openFile(QString file)
{
    qDebug()<<"open file"<< file;

    QFile f(file);
           if (f.open(QFile::ReadOnly | QFile::Text))
               editor->setPlainText(f.readAll());

}

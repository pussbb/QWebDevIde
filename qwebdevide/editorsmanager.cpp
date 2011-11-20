#include "editorsmanager.h"

EditorsManager::EditorsManager(QObject *parent) :
    QObject(parent)
{
}

void EditorsManager::openFile(QString file)
{
  qDebug()<<"open file"<< file;

    QFile f(file);
           if (f.open(QFile::ReadOnly | QFile::Text))
               editor->setPlainText(f.readAll());

}

#include "abstractproject.h"

AbstractProject::AbstractProject(QObject *parent) :
    QObject(parent)
{

}
#include <QDebug>
void AbstractProject::init()
{//qDebug()<<fileName;
 //  QSettings settings(fileName, QSettings::IniFormat,this);
   //// m_projectSettings.setUserIniPath();
 ///   qDebug()<<settings.fileName();
}

QVariant AbstractProject::getProperty(QString property)
{
   return m_projectSettings.value(property);
}
#include <QFileInfo>
QString AbstractProject::projectPath()
{
    QFileInfo fi(fileName);
    return fi.absolutePath();
}

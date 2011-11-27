#include "abstractproject.h"

AbstractProject::AbstractProject(QObject *parent) :
    QObject(parent)
{

}
void AbstractProject::setProjectFile(QString file)
{
  m_projectSettings = new QSettings(file,QtJsonSettings::webpro_format);
  QFileInfo fi(file);
  m_projectName = fi.baseName();
  m_projectPath = fi.absolutePath();
}

QVariant AbstractProject::getProperty(QString property)
{
   return m_projectSettings->value(property);
}

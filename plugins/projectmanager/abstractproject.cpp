#include "abstractproject.h"

AbstractProject::AbstractProject(QObject *parent) :
    QObject(parent)
{

}

void AbstractProject::setProjectFile(QString file)
{
    QFileInfo fi(file);
    if ( ! fi.isDir())
        m_projectSettings = new QSettings(file,QtJsonSettings::webpro_format);

    m_projectName = fi.baseName();
    m_projectPath = fi.absolutePath();
}

QVariant AbstractProject::getProperty(QString property)
{
   return m_projectSettings->value(property);
}

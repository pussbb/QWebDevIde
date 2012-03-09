#include "projectmanager.h"
#include "QDebug"

ProjectManager::ProjectManager()
{
    projects = new Projects();
}

QStringList ProjectManager::dependencies() const
{
    return QStringList();
}

void ProjectManager::init(QMap<QString, QObject *> dependencies, QObject *parent)
{
    Q_UNUSED(dependencies);
    qDebug()<< parent->metaObject();
    qDebug()<< parent->metaObject()->className();
    m_parent = parent;
}

QWidget * ProjectManager::open(const QString &file)
{
    Q_UNUSED(file);
    qDebug()<< "project request";
    projects->openProject(file);
    return NULL;
}

bool ProjectManager::save(const QString &fileName)
{
    Q_UNUSED(fileName);
    return true;
}

void ProjectManager::close(const QString &fileName)
{
    Q_UNUSED(fileName);
}

QStringList ProjectManager::mimeTypes()
{
    return QStringList()<< "folder"
                        << "application/web.dev.ide";
}

QWidget * ProjectManager::getWidget()
{
    if(projectExplorer != NULL)
           return projectExplorer;

    projectExplorer = new ProjectExplorer(NULL,projects);
    connect(projects,SIGNAL(projectAdd()),projectExplorer, SLOT(refresh()));
    connect(projectExplorer,SIGNAL(openFile(QString)), m_parent ,SLOT(openFile(QString)));
    return projectExplorer;
}

Q_EXPORT_PLUGIN2(ProjectManager, ProjectManager)













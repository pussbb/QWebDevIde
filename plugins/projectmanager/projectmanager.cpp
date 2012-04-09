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
    m_parent = parent;
}

QWidget * ProjectManager::open(const QString &file,const QString &fileId)
{
    Q_UNUSED(fileId);
    projects->openProject(file);
    return NULL;
}

bool ProjectManager::save(const QString &fileId)
{
    Q_UNUSED(fileId);
    return true;
}

void ProjectManager::close(const QString &fileId)
{
    Q_UNUSED(fileId);
}

QStringList ProjectManager::mimeTypes()
{
    return QStringList()<< "folder"
                        << "application/web.dev.ide";
}

QWidget *ProjectManager::searchReplace()
{
    return NULL;
}

QWidget * ProjectManager::getWidget()
{
    if(projectExplorer != NULL)
           return projectExplorer;

    projectExplorer = new ProjectExplorer(NULL,projects);
    connect(projects,SIGNAL(projectAdded()),projectExplorer, SLOT(refresh()));
    connect(projectExplorer,SIGNAL(openFile(QString)), m_parent ,SLOT(openFile(QString)));
    return projectExplorer;
}

Q_EXPORT_PLUGIN2(ProjectManager, ProjectManager)













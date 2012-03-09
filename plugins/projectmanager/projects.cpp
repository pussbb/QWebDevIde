#include "projects.h"

Projects::Projects(QObject *parent) :
    QObject(parent)
{
}

void Projects::openProject(QString fileName)
{
    QFileInfo fi(fileName);
    if(projects.value(fi.baseName(),NULL) == NULL){
        AbstractProject *pro = new AbstractProject(this);
        pro->setProjectFile(fileName);
        projects.insert(fi.baseName(),pro);
        current = pro;
        emit(projectAdd());
    }
    else{
        current = projects.value(fi.baseName());
    }
}

void Projects::closeProject(QString projectName)
{
    projects.remove(projectName);
    current = NULL;
    if(projects.count() > 0)
        current = projects.operator [](0);
}

#include "projectmanager.h"

ProjectManager::ProjectManager(QObject *parent) :
    QObject(parent)
{
}



void ProjectManager::openProject(QString fileName)
{
    QFileInfo fi(fileName);
    if(projects.value(fi.baseName(),NULL) == NULL){
        AbstractProject *pro = new AbstractProject(this);
        pro->fileName = fileName;
        pro->projectName = fi.baseName();
        pro->init();
        projects.insert(fi.baseName(),pro);
        current = pro;
        emit(projectAdd());
    }
    else{
        current = projects.value(fi.baseName());
    }

}

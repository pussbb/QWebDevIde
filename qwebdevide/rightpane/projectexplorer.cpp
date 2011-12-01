#include "projectexplorer.h"
#include "ui_projectexplorer.h"
#include "filetemplates.h"
ProjectExplorer::ProjectExplorer(QWidget *parent,ProjectManager *prman) :
    QWidget(parent),
    ui(new Ui::ProjectExplorer),
    m_projecManager(prman)
{
    ui->setupUi(this);
    if(m_projecManager->projects.count() > 0)
        refresh();
    fileTemplates = new FileTemplates;
    fileSystemWatcher = new QFileSystemWatcher(this);
    connect(fileSystemWatcher,SIGNAL(directoryChanged(QString)),
            this,SLOT(directoryChanged(QString)));
   /* connect(fileSystemWatcher,SIGNAL(fileChanged(QString)),
            this,SLOT(filesChanged(QString)));
*/
}

ProjectExplorer::~ProjectExplorer()
{
    delete ui;
}

void ProjectExplorer::refresh()
{
    foreach(const QString &proName,m_projecManager->projects.keys()){
         AbstractProject *pro = m_projecManager->projects.value(proName);
         QList<QTreeWidgetItem*> items = ui->projectTree->findItems(proName,Qt::MatchExactly,0);
         if(items.isEmpty()){
             QTreeWidgetItem *parent = new QTreeWidgetItem(ui->projectTree);
             parent->setText(0,proName);
             parent->setData(0,33,pro->projectPath());
             fileSystemWatcher->addPath(pro->projectPath());
             parent->setIcon(0,QIcon(":/applications-development-web.png"));
             directoryChanged(pro->projectPath());
         }
    }
}

void ProjectExplorer::createProjectTree(QTreeWidgetItem *parent,QString path)
{
    QDir dir(path);
    dir.setFilter(QDir::Files| QDir::Dirs| QDir::NoDotAndDotDot);
    dir.setSorting(QDir::DirsFirst);
    QFileInfoList list = dir.entryInfoList();
    for (int i = 0; i < list.size(); ++i) {
        QFileInfo fi = list.at(i);
        if(fi.suffix() == "webpro")
            continue;
        fileSystemWatcher->addPath(fi.absoluteFilePath());
        if(fi.isDir()){
            QTreeWidgetItem *item = new QTreeWidgetItem(parent);
            item->setText(0,fi.baseName());
            item->setData(0,33,fi.absoluteFilePath());
            item->setIcon(0,QIcon(":/fs-directory.png"));
            createProjectTree(item,fi.absoluteFilePath());
        }
        else{
            QTreeWidgetItem *item = new QTreeWidgetItem(parent);
            item->setText(0,fi.fileName());
            item->setIcon(0,QIcon(mime.getIconMimeType(fi.absoluteFilePath())));
            item->setData(0,32,fi.absoluteFilePath());
        }
    }
}

void ProjectExplorer::on_projectTree_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    if(!item->data(column,Qt::UserRole).isNull())
        emit(openFile(item->data(column,Qt::UserRole).toString()));
}

void ProjectExplorer::on_projectTree_customContextMenuRequested(const QPoint &pos)
{
    if(!ui->projectTree->currentIndex().isValid()
            && !ui->projectTree->currentItem()->isSelected())
        return;

    QMenu *m=new QMenu();
    if(!ui->projectTree->currentItem()->data(0,33).isNull()){
        fileTemplates->folder = ui->projectTree->currentItem()->data(0,33).toString();
        m->addMenu(fileTemplates->getTemplatesMenu());
    }

    if(ui->projectTree->currentItem()->parent() == NULL)
        m->addAction(ui->actionClose_Project);

    m->addAction(ui->actionDelete);
    m->exec(ui->projectTree->mapToGlobal(pos));
}

void ProjectExplorer::on_actionClose_Project_triggered()
{
    QString projectName = ui->projectTree->currentItem()->text(0);
    m_projecManager->closeProject(projectName);
    delete ui->projectTree->currentItem();
}

void ProjectExplorer::directoryChanged(const QString &path)
{
    QFileInfo fi(path);
    QModelIndexList items = ui->projectTree->model()->match(ui->projectTree->model()->index(0, 0),
                                    33,path,1,Qt::MatchExactly | Qt::MatchRecursive);
    foreach(QModelIndex index,items){
        ui->projectTree->setCurrentIndex(index);
        if(!fi.exists()){
            fileSystemWatcher->removePath(path);
            delete ui->projectTree->currentItem();
        }
        else{
             updateTreeItem(ui->projectTree->currentItem(),path);
        }
    }
}

void ProjectExplorer::filesChanged(const QString &path)
{
    Q_UNUSED(path);
    //Nothing for now
}

void ProjectExplorer::updateTreeItem(QTreeWidgetItem *parent, QString path)
{;
    QDir dir(path);
    dir.setFilter(QDir::Files| QDir::Dirs| QDir::NoDotAndDotDot);
    dir.setSorting(QDir::DirsFirst);
    QStringList dirList = dir.entryList();
    for(int i = 0; i < parent->childCount();i++){
        QTreeWidgetItem *item = parent->child(i);
        if(!dirList.contains(item->text(0))){
            if(!item->data(0,32).isNull())
                fileSystemWatcher->removePath(item->data(0,32).toString());
            else if(!item->data(0,33).isNull())
                    fileSystemWatcher->removePath(item->data(0,33).toString());
            delete item;
        }
        else
            dirList.removeAt(dirList.indexOf(item->text(0)));
    }
    foreach(const QString &file,dirList){
        QFileInfo fi = path + QDir::toNativeSeparators("/") + file;
        if(fi.suffix() == "webpro")
            continue;
        fileSystemWatcher->addPath(fi.absoluteFilePath());
        if(fi.isDir()){
            QTreeWidgetItem *item = new QTreeWidgetItem(parent);
            item->setText(0,fi.baseName());
            item->setData(0,33,fi.absoluteFilePath());
            item->setIcon(0,QIcon(":/fs-directory.png"));
            createProjectTree(item,fi.absoluteFilePath());
        }
        else{
            QTreeWidgetItem *item = new QTreeWidgetItem(parent);
            item->setText(0,fi.fileName());
            item->setIcon(0,QIcon(mime.getIconMimeType(fi.absoluteFilePath())));
            item->setData(0,32,fi.absoluteFilePath());
        }
    }
}

void ProjectExplorer::on_actionDelete_triggered()
{
    if(!ui->projectTree->currentItem()->data(0,33).isNull()){
         QMessageBox msgBox;
         msgBox.setText("Do you realy whant to delete folder.");
         msgBox.setInformativeText("It will delete everething in this this folder");
         msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
         msgBox.setDefaultButton(QMessageBox::Cancel);
         int ret = msgBox.exec();
         if(ret == QMessageBox::Yes)
             removeDir(ui->projectTree->currentItem()->data(0,33).toString());
    }
    if(!ui->projectTree->currentItem()->data(0,32).isNull()){
        QMessageBox msgBox;
        msgBox.setText("Do you realy whant to file.");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Cancel);
        int ret = msgBox.exec();
        if(ret == QMessageBox::Yes){
            QFile file(ui->projectTree->currentItem()->data(0,32).toString());
            file.remove();
        }

    }
}
bool ProjectExplorer::removeDir(const QString &dirName)
{
    bool result = true;
    QDir dir(dirName);

    if (dir.exists(dirName)) {
        Q_FOREACH(QFileInfo info, dir.entryInfoList(QDir::NoDotAndDotDot | QDir::System | QDir::Hidden
                                                    | QDir::AllDirs | QDir::Files, QDir::DirsFirst)) {
            if (info.isDir()) {
                result = removeDir(info.absoluteFilePath());
            }
            else {
                result = QFile::remove(info.absoluteFilePath());
            }

            if (!result) {
                return result;
            }
        }
        result = dir.rmdir(dirName);
    }

    return result;
}

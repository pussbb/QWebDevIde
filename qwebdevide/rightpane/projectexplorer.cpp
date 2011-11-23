#include "projectexplorer.h"
#include "ui_projectexplorer.h"

ProjectExplorer::ProjectExplorer(QWidget *parent,ProjectManager *prman) :
    QWidget(parent),
    ui(new Ui::ProjectExplorer),
    m_projecManager(prman)
{
    ui->setupUi(this);
    if(m_projecManager->projects.count() > 0)
        refresh();
}

ProjectExplorer::~ProjectExplorer()
{
    delete ui;
}

void ProjectExplorer::refresh()
{
    foreach(QString proName,m_projecManager->projects.keys()){
        AbstractProject *pro = m_projecManager->projects.value(proName);
         QList<QTreeWidgetItem*> items = ui->projectTree->findItems(proName,Qt::MatchExactly,0);
         if(items.count() > 0){
             qDebug()<<"update";
         }
         else{
             QTreeWidgetItem *parent = new QTreeWidgetItem(ui->projectTree);
             parent->setText(0,proName);
             parent->setData(0,Qt::UserRole,pro->projectPath());
             parent->setIcon(0,QIcon(":/applications-development-web.png"));
             createProjectTree(parent,pro->projectPath());
         }
    }
}

void ProjectExplorer::createProjectTree(QTreeWidgetItem *parent, QString path)
{
    QDir dir(path);
    dir.setFilter(QDir::Files| QDir::Dirs| QDir::NoDotAndDotDot);
    dir.setSorting(QDir::DirsFirst);
    QFileInfoList list = dir.entryInfoList();
         for (int i = 0; i < list.size(); ++i) {
              QFileInfo fi = list.at(i);
              if(fi.isDir()){
                  QTreeWidgetItem *item = new QTreeWidgetItem(parent);
                  item->setText(0,fi.baseName());
                  item->setIcon(0,QIcon(":/fs-directory.png"));
                  createProjectTree(item,fi.absoluteFilePath());
              }
              else{
                  QTreeWidgetItem *item = new QTreeWidgetItem(parent);
                  item->setText(0,fi.fileName());
                  item->setIcon(0,QIcon(mime.getIconMimeType(fi.absoluteFilePath())));
                  item->setData(0,Qt::UserRole,fi.absoluteFilePath());
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
    QMenu *m=new QMenu();
    ///m->addAction(ui->actionHelp_Doc);
    if(ui->projectTree->currentIndex().isValid()
            && ui->projectTree->currentItem()->isSelected()){
       // pos.setX(pos.x()+5);
       /// pos.setY(pos.y()+10);
        if(ui->projectTree->currentItem()->parent() == NULL)
            m->addAction(ui->actionClose_Project);
    }
    m->exec(ui->projectTree->mapToGlobal(pos));
}

void ProjectExplorer::on_actionClose_Project_triggered()
{
    QString projectName = ui->projectTree->currentItem()->text(0);
    m_projecManager->closeProject(projectName);
    delete ui->projectTree->currentItem();
}

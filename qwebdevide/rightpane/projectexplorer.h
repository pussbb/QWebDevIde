#ifndef PROJECTEXPLORER_H
#define PROJECTEXPLORER_H

#include <QWidget>
#include "../projectmanager.h"
#include <QTreeWidgetItem>
#include <QDir>
#include "mimedata.h"
#include <QMenu>
#include "filetemplates.h"
#include <QFileSystemWatcher>
namespace Ui {
    class ProjectExplorer;
}

class ProjectExplorer : public QWidget
{
    Q_OBJECT

public:
    explicit ProjectExplorer(QWidget *parent = 0,ProjectManager *prman = 0);
    ~ProjectExplorer();
    void refresh();
private slots:
    void on_projectTree_itemDoubleClicked(QTreeWidgetItem *item, int column);
    void on_projectTree_customContextMenuRequested(const QPoint &pos);
    void on_actionClose_Project_triggered();
    void directoryChanged(const QString & path);
    void filesChanged(const QString & path);
    void updateTreeItem(QTreeWidgetItem *parent,QString path);
    void on_actionDelete_triggered();

signals:
    void openFile(QString);
private:
    QFileSystemWatcher *fileSystemWatcher;
    Ui::ProjectExplorer *ui;
    ProjectManager *m_projecManager;
    MimeData mime;
    FileTemplates *fileTemplates;
    void createProjectTree(QTreeWidgetItem *parent,QString path);
    bool removeDir(const QString &dirName);
};

#endif // PROJECTEXPLORER_H

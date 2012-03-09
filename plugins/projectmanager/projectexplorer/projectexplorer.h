#ifndef PROJECTEXPLORER_H
#define PROJECTEXPLORER_H

#include <QWidget>
#include <projects.h>
#include <QTreeWidgetItem>
#include <QDir>
#include <mimedata.h>
#include <QtCore>
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
    explicit ProjectExplorer(QWidget *parent = 0, Projects *projects = 0);
    ~ProjectExplorer();

    bool removeDir(const QString &dirName);
public slots:
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
    QFileSystemWatcher fileSystemWatcher;
    Ui::ProjectExplorer *ui;
    Projects *m_projectManager;
    MimeData mime;
    FileTemplates *fileTemplates;
    void createProjectTree(QTreeWidgetItem *parent,QString path);

    void removeWatchedFiles(const QString &path);
};

#endif // PROJECTEXPLORER_H

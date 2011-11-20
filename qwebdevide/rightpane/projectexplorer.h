#ifndef PROJECTEXPLORER_H
#define PROJECTEXPLORER_H

#include <QWidget>
#include "../projectmanager.h"
#include <QTreeWidgetItem>
#include <QDir>
#include "../mimetypes.h"

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

signals:
    void openFile(QString);
private:
    Ui::ProjectExplorer *ui;
    ProjectManager *m_projecManager;
    MimeTypes mime;
    void createProjectTree(QTreeWidgetItem *parent, QString path);
};

#endif // PROJECTEXPLORER_H

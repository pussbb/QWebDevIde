#ifndef RIGHTPANE_H
#define RIGHTPANE_H
#include <styledbar.h>
#include <QWidget>
#include <QPointer>

#include "filesystembrowser.h"
#include "../projectmanager.h"
#include "../bookmarkmanager.h"
#include "../editorsmanager.h"

namespace Ui {
    class RightPane;
}

class RightPane : public QWidget
{
    Q_OBJECT

public:
    explicit RightPane(QWidget *parent = 0,ProjectManager *prman = 0,EditorsManager *eman = 0,BookmarkManager *bman = 0);
    ~RightPane();
    QPointer<QWidget> currentWidget;
    QPointer<FileSystemBrowser> sysFileBrowser;
private slots:
    QWidget* getFileBrowserWidget();
    void on_rightPaneClose_clicked();

    void on_rightPaneSplit_clicked();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::RightPane *ui;
    ProjectManager *m_projecManager;
    EditorsManager *m_editorsManager;
    BookmarkManager *m_bookmarkManager;

};

#endif // RIGHTPANE_H

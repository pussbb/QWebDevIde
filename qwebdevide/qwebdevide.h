#ifndef QWEBDEVIDE_H
#define QWEBDEVIDE_H

#include <qcorewindow.h>
#include <fancytabwidget.h>
#include <manhattanstyle.h>
#include <styledbar.h>
#include <minisplitter.h>
#include <QtGui>
#include "rightpane/rightpane.h"
#include "projectmanager.h"
#include "bookmarkmanager.h"
#include "editorsmanager.h"
#include "editingwidget.h"
using namespace Core;
using namespace Core::Internal;

namespace Ui {
    class QWebDevIde;
}

class QWebDevIde : public QCoreWindow
{
    Q_OBJECT

public:
    explicit QWebDevIde(QWidget *parent = 0);
    ~QWebDevIde();
    void changeEvent(QEvent *e);
    ProjectManager *projectManager;
    BookmarkManager *bookmarkManager;
    EditorsManager *editorsManager;
    FancyTabWidget* ptab;
    void openFile(QString fileName);
private slots:
    void on_actionNewProject_triggered();

    void on_actionOpen_triggered();

private:
    Ui::QWebDevIde *ui;
    void initUI();
    MiniSplitter *rightPaneSplitter;
    EditingWidget *m_editingWidget;
};
#endif // QWEBDEVIDE_H

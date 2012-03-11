#ifndef QWEBDEVIDE_H
#define QWEBDEVIDE_H

#include <qcorewindow.h>
#include <fancytabwidget.h>
#include <manhattanstyle.h>
#include <styledbar.h>
#include <minisplitter.h>
#include <QtGui>
#include "rightpane/rightpane.h"

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
    BookmarkManager *bookmarkManager;
    EditorsManager *editorsManager;
    FancyTabWidget* ptab;

public slots:
    void openFile(QString );
    void currentTabWidgetChanged(int );
private slots:
    void on_actionNewProject_triggered();
    void on_actionOpen_triggered();
    void on_actionFull_screen_triggered();
    void on_actionShow_Hide_Editor_Right_pane_triggered();
    void on_actionSave_file_triggered();
    void on_actionSave_all_triggered();

private:
    Ui::QWebDevIde *ui;
    void initUI();
    RightPane *rightPane;
    MiniSplitter *rightPaneSplitter;
    EditingWidget *m_editingWidget;
    QToolButton *rightPaneControl;
    MiniSplitter *editingSplitter;
};
#endif // QWEBDEVIDE_H

#ifndef QWEBDEVIDE_H
#define QWEBDEVIDE_H

#include <qcorewindow.h>
#include <fancytabwidget.h>
#include <manhattanstyle.h>
#include <styledbar.h>
#include <minisplitter.h>
#include <QtGui>
#include "rightpane/rightpane.h"

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
private:
    Ui::QWebDevIde *ui;
    void initUI();
    MiniSplitter *rightPaneSplitter;
};
#endif // QWEBDEVIDE_H

#ifndef QWEBDEVIDE_H
#define QWEBDEVIDE_H

#include <qcorewindow.h>

namespace Ui {
    class QWebDevIde;
}

class QWebDevIde : public QCoreWindow
{
    Q_OBJECT

public:
    explicit QWebDevIde(QWidget *parent = 0);
    ~QWebDevIde();

private:
    Ui::QWebDevIde *ui;
};

#endif // QWEBDEVIDE_H

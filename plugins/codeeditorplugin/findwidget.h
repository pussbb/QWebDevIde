#ifndef FINDWIDGET_H
#define FINDWIDGET_H

#include <QWidget>

namespace Ui {
class FindWidget;
}

class FindWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit FindWidget(QWidget *parent = 0);
    ~FindWidget();
    
private:
    Ui::FindWidget *ui;
};

#endif // FINDWIDGET_H

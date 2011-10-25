#ifndef RIGHTPANE_H
#define RIGHTPANE_H
#include <styledbar.h>
#include <QWidget>
namespace Ui {
    class RightPane;
}

class RightPane : public QWidget
{
    Q_OBJECT

public:
    explicit RightPane(QWidget *parent = 0);
    ~RightPane();

private slots:
    void on_rightPaneClose_clicked();

    void on_rightPaneSplit_clicked();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::RightPane *ui;
};

#endif // RIGHTPANE_H

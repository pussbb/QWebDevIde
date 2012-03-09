#ifndef RIGHTPANE_H
#define RIGHTPANE_H
#include <styledbar.h>
#include <QWidget>
#include <QPointer>

#include "filesystembrowser.h"
#include "../../plugins/ifaces.h"

namespace Ui {
    class RightPane;
}

class RightPane : public QWidget
{
    Q_OBJECT

public:
    explicit RightPane(QWidget *parent = 0);
    ~RightPane();
    QPointer<QWidget> currentWidget;
    void initPlugins(QMap<QString, QObject *> list);
private slots:
    void on_rightPaneClose_clicked();
    void on_rightPaneSplit_clicked();
    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::RightPane *ui;
    QMap<QString, IRightPane *> widgets;
};

#endif // RIGHTPANE_H

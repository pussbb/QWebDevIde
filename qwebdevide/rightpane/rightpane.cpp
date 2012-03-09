#include "rightpane.h"
#include "ui_rightpane.h"
#include <QtGui>
RightPane::RightPane(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RightPane)
{
    ui->setupUi(this);
    ui->rightPaneSplit->setVisible(false);
    if ( ui->comboBox->count() > 0) {
        ui->comboBox->setCurrentIndex(-1);
        ui->comboBox->setCurrentIndex(0);
    }

}

RightPane::~RightPane()
{
    delete ui;
}

void RightPane::on_rightPaneClose_clicked()
{
   //deleteLater();
    hide();
}

void RightPane::on_rightPaneSplit_clicked()
{
    /*
        for RightPane(0xdf1940, name = "RightPane") attached one QSplitterHandle(0xdf7130, name = "qt_splithandle_")
      */
    if(parentWidget()->children().count()/2 < 4)
        new RightPane(parentWidget());
}

void RightPane::on_comboBox_currentIndexChanged(int index)
{
    if( index == -1 || widgets.count() == 0)
        return;

    if( currentWidget != NULL ){
       currentWidget->hide();
       currentWidget->setParent(0);
       currentWidget = 0;
    }
    QString name = ui->comboBox->itemData(index).toString();
    currentWidget = widgets.value(name)->getWidget();
    currentWidget->setParent(this);
    ui->rightPaneContainer->layout()->addWidget(currentWidget);
    setFocusProxy(currentWidget);
    currentWidget->show();
}

void RightPane::initPlugins(QMap<QString, QObject *> list)
{
    foreach(QString name, list.keys()) {
        IRightPane *pane = qobject_cast<IRightPane *>(list.value(name));
        if (pane)
        {
            ui->comboBox->addItem(pane->widgetTitle(), name);
            widgets.insert(name, pane);
        }
    }
    if ( ui->comboBox->count() > 0) {
        ui->comboBox->setCurrentIndex(-1);
        ui->comboBox->setCurrentIndex(0);
    }
}

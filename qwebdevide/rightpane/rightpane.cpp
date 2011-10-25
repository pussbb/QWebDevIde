#include "rightpane.h"
#include "ui_rightpane.h"
#include <QtGui>
RightPane::RightPane(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RightPane)
{
    ui->setupUi(this);
   // QGridLayout *layout = new QGridLayout(ui->rightPaneContainer);
    ///layout->setAlignment(Qt::AlignJustify);
   /// layout->setMargin(0);
}

RightPane::~RightPane()
{
    delete ui;
}

void RightPane::on_rightPaneClose_clicked()
{
   deleteLater();
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
    switch(index){
        case 0:
            break;
    case 1:
        break;
    case 2:{
        /// file system view
        QFileSystemModel *model = new QFileSystemModel;
        model->setRootPath(QDir::currentPath());
        QListView *list = new QListView();
        list->setModel(model);
        list->setRootIndex(model->index(QDir::currentPath()));
        ui->rightPaneContainer->layout()->addWidget(list);
        ///ui->rightPaneContainer->layout()->removeWidget();
        ///tree->show();
        break;
    }
    case 3:
        break;
    }
}

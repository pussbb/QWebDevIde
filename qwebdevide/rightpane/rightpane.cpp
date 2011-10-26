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
    if(currentWidget != NULL)
        delete currentWidget;//ui->rightPaneContainer->layout()->removeWidget(currentWidget);

    switch(index){
        case 0:
            currentWidget = new QWidget();
            break;
        case 1:
            currentWidget = new QWidget();
            break;
        case 2:
            /// file system view
            currentWidget = getFileBrowserWidget();
            break;
        case 3:
            currentWidget = new QWidget();
            break;
    }
    ui->rightPaneContainer->layout()->addWidget(currentWidget);
}

QWidget * RightPane::getFileBrowserWidget()
{
    if(sysFileBrowser != NULL)
        return sysFileBrowser;

    sysFileBrowser = new FileSystemBrowser;
    return new FileSystemBrowser;
}

#include "rightpane.h"
#include "ui_rightpane.h"
#include <QtGui>
RightPane::RightPane(QWidget *parent,ProjectManager *prman,EditorsManager *eman,BookmarkManager *bman ) :
    QWidget(parent),
    ui(new Ui::RightPane),
    m_projecManager(prman),
    m_editorsManager(eman),
    m_bookmarkManager(bman)
{
    ui->setupUi(this);
    connect( m_projecManager,SIGNAL(projectAdd()),this,SLOT(refreshProject()));
    ui->comboBox->setCurrentIndex(-1);
    ui->comboBox->setCurrentIndex(0);
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
        new RightPane(parentWidget(),
                        m_projecManager,
                            m_editorsManager,
                                m_bookmarkManager);
}

void RightPane::on_comboBox_currentIndexChanged(int index)
{
    if(index == -1)
        return;

    if(currentWidget != NULL){
       currentWidget->hide();
       currentWidget->setParent(0);
       currentWidget = 0;
    }

    switch(index){
        case 0:
            currentWidget = getProjectExplorer();
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
    currentWidget->setParent(this);
    ui->rightPaneContainer->layout()->addWidget(currentWidget);
    setFocusProxy(currentWidget);
    currentWidget->show();
}

QWidget * RightPane::getFileBrowserWidget()
{
    if(sysFileBrowser != NULL)
        return sysFileBrowser;

    sysFileBrowser = new FileSystemBrowser;
    connect(sysFileBrowser,SIGNAL(openFile(QString)),m_editorsManager,SLOT(openFile(QString)));
    return sysFileBrowser;
}

void RightPane::refreshProject()
{
   if(projectExplorer != NULL)
       projectExplorer->refresh();
}

QWidget * RightPane::getProjectExplorer()
{
    if(projectExplorer != NULL)
        return projectExplorer;

    projectExplorer = new ProjectExplorer(NULL,m_projecManager);
    connect(projectExplorer,SIGNAL(openFile(QString)),m_editorsManager,SLOT(openFile(QString)));
    return projectExplorer;
}
#include "editingwidget.h"
#include "ui_editingwidget.h"

EditingWidget::EditingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditingWidget)
{
    ui->setupUi(this);
  //// ui->widget_2->setProperty("panelwidget_singlerow",false);
    ui->closeFile->setEnabled(false);
}

EditingWidget::~EditingWidget()
{
    delete ui;
}

void EditingWidget::setCentralWidget(QWidget *widget)
{
    if(currentWidget != NULL){
       currentWidget->hide();
       currentWidget->setParent(0);
       currentWidget = 0;
    }
    currentWidget = widget;
    currentWidget->setParent(this);
    ui->editorContainer->layout()->addWidget(currentWidget);
    setFocusProxy(currentWidget);
    currentWidget->show();
}

void EditingWidget::refreshFileList(QMap<QString, AbstractEditor*> openedFiles)
{
    m_openedFiles = openedFiles;
    for(int i = 0 ; i < ui->openedFilesList->count(); i++){
        QString item = ui->openedFilesList->itemData(i).toString();
        if(openedFiles.value(item) == NULL)
            ui->openedFilesList->removeItem(i);
        else
            openedFiles.remove(item);
    }
    foreach(QString file,openedFiles.keys()){
        ui->openedFilesList->addItem(file,file);
    }
}

void EditingWidget::on_openedFilesList_currentIndexChanged(int index)
{
    QString file = ui->openedFilesList->itemData(index).toString();
    AbstractEditor *editor = m_openedFiles.value(file);
    if(editor != NULL){
        setCentralWidget(editor->getEditorWidget());
        ui->closeFile->setEnabled(true);
    }
}

void EditingWidget::setCurrent(QString file)
{
    int index = ui->openedFilesList->findData(file);
    if(index != -1){
        ui->openedFilesList->setCurrentIndex(index);
    }
}

void EditingWidget::on_closeFile_clicked()
{
    int index = ui->openedFilesList->currentIndex();
    QString file = ui->openedFilesList->itemData(index).toString();
    emit(closeFile(file));
    --index;
    if(index >= 0 && ui->openedFilesList->count() > 0){
        ui->openedFilesList->setCurrentIndex(index);
    }
    else if(ui->openedFilesList->count() > 0){
            ui->openedFilesList->setCurrentIndex(0);
    }
    else{
        ui->closeFile->setEnabled(false);
        currentWidget->hide();
        currentWidget->setParent(0);
        currentWidget = 0;
    }
}

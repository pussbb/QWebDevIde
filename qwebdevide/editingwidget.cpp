#include "editingwidget.h"
#include "ui_editingwidget.h"

EditingWidget::EditingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditingWidget)
{
    ui->setupUi(this);
    ui->closeFile->setEnabled(false);
    m_openedFiles.clear();
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

void EditingWidget::refreshFileList(QMap<QString, EditedFile> openedFiles)
{
    m_openedFiles = openedFiles;
    for(int i = 0 ; i < ui->openedFilesList->count(); i++) {
        QString item = ui->openedFilesList->itemData(i).toString();
        if( ! openedFiles.contains(item))
            ui->openedFilesList->removeItem(i);
        else
            openedFiles.remove(item);
    }

    foreach(QString fileId, openedFiles.keys()){
        EditedFile editedFile= openedFiles.value(fileId);
        ui->openedFilesList->addItem(editedFile.fi.fileName(),fileId);
    }
}

void EditingWidget::on_openedFilesList_currentIndexChanged(int index)
{
    QString fileId = ui->openedFilesList->itemData(index).toString();
    QWidget *editor = m_openedFiles.value(fileId).widget;
    if(editor != NULL){
        setCentralWidget(editor);
        ui->closeFile->setEnabled(true);
    }
}

void EditingWidget::setCurrent(QString fileId)
{
    int index = ui->openedFilesList->findData(fileId);
    if(index != -1){
        ui->openedFilesList->setCurrentIndex(index);
        currentFileId = fileId;
    }
}

void EditingWidget::on_closeFile_clicked()
{
    int index = ui->openedFilesList->currentIndex();
    QString fileId = ui->openedFilesList->itemData(index).toString();
    emit(closeFile(fileId));
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

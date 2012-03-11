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
    ui->openedFilesList->clear();
    /*for(int i = 0 ; i < ui->openedFilesList->count(); i++) {
        QString item = ui->openedFilesList->itemData(i).toString();
        if( ! openedFiles.contains(item))
            ui->openedFilesList->removeItem(i);
        else
            openedFiles.remove(item);
    }*/

    foreach(QString fileId, openedFiles.keys()){
        EditedFile editedFile= openedFiles.value(fileId);
        ui->openedFilesList->addItem(editedFile.fi.fileName(),fileId);
    }

    qDebug()<<  ui->openedFilesList->currentIndex();
}

void EditingWidget::on_openedFilesList_currentIndexChanged(int index)
{
    QString fileId = ui->openedFilesList->itemData(index).toString();
    EditedFile editedFile = m_openedFiles.value(fileId);
    if(editedFile.widget != NULL){
        setCentralWidget(editedFile.widget);
        ui->filePath->setText(editedFile.fi.absolutePath());
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
    ui->closeFile->setEnabled(false);
    ui->filePath->setText("");
    currentWidget->hide();
    currentWidget->setParent(0);
    currentWidget = 0;

    emit(closeFile(fileId));
}

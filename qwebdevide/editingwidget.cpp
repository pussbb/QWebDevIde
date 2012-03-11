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
    foreach(QString fileId, openedFiles.keys()){
        EditedFile editedFile= openedFiles.value(fileId);
        ui->openedFilesList->addItem(editedFile.fi.fileName(),fileId);
    }
}

void EditingWidget::on_openedFilesList_currentIndexChanged(int index)
{
    QString fileId = ui->openedFilesList->itemData(index).toString();
    EditedFile editedFile = m_openedFiles.value(fileId);
    if(editedFile.widget != NULL){
        setCentralWidget(editedFile.widget);
        ui->filePath->setText(editedFile.fi.absolutePath());
        if (editedFile.fi.isWritable()) {
            ui->fileAccess->setToolTip(tr("Read+Write access"));
            ui->fileAccess->setStatusTip(tr("Read+Write access"));
            ui->fileAccess->setPixmap(QPixmap(":/core/images/unlocked.png"));
        }
        else {
            ui->fileAccess->setToolTip(tr("Read only access"));
            ui->fileAccess->setStatusTip(tr("Read only access"));
            ui->fileAccess->setPixmap(QPixmap(":/core/images/locked.png"));
        }
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

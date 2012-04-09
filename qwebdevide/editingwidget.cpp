#include "editingwidget.h"
#include "ui_editingwidget.h"

EditingWidget::EditingWidget(QWidget *parent, EditedFiles *ef ) :
    QWidget(parent),
    ui(new Ui::EditingWidget),
    editedFiles(ef)
{
    ui->setupUi(this);
    ui->closeFile->setEnabled(false);
    ui->searchWidget->setVisible(false);
    ui->searchWidget->setProperty("panelwidget_singlerow",false);
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
    QObject::connect(widget,SIGNAL(contentChanged()),this,SLOT(contentChanged()));
    currentWidget = widget;
    currentWidget->setParent(this);
    ui->editorContainer->layout()->addWidget(currentWidget);
    setFocusProxy(currentWidget);
    currentWidget->show();
}

void EditingWidget::refreshFileList()
{
    ui->openedFilesList->clear();
    foreach(QString fileId, editedFiles->openedFiles.keys()){
        EditedFile editedFile= editedFiles->openedFiles.value(fileId);
        QString text = editedFile.fi.fileName();
        qDebug()<<"is has not saved data"<<editedFile.changed;
        if ( editedFile.changed)
            text = "*" + text;
        ui->openedFilesList->addItem(text,fileId);
    }
}

void EditingWidget::on_openedFilesList_currentIndexChanged(int index)
{
    QString fileId = ui->openedFilesList->itemData(index).toString();
    EditedFile editedFile = editedFiles->openedFiles.value(fileId);
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
    if (editedFiles->closeFile(fileId)) {
        ui->closeFile->setEnabled(false);
        ui->filePath->setText("");
        currentWidget->hide();
        currentWidget->setParent(0);
        currentWidget = 0;
    }
    refreshFileList();
}

void EditingWidget::keyPressEvent(QKeyEvent *e)
{
    qDebug()<<"protected event";
    qDebug()<< e->key();
    if ( (e->key() == Qt::Key_F && e->modifiers() == Qt::ControlModifier)
         || ( e->key() == Qt::Key_R && e->modifiers() == Qt::ControlModifier)) {
        IEditors *editor = editedFiles->openedFiles.value(currentFileId).editorInterface;
        QPointer<QWidget> sr = editor->searchReplace();
        qDebug()<<"searchWidget"<<sr;
        if ( ! sr.isNull()) {qDebug()<<"searchWidget"<<sr;
            sr->setParent(ui->searchWidget);
            ui->searchWidget->layout()->addWidget(sr);
            setFocusProxy(sr);
            ui->searchWidget->setVisible(true);
        }
    }
    QWidget::keyPressEvent(e);
}

void EditingWidget::contentChanged()
{qDebug()<<"text changed";
    int index = ui->openedFilesList->currentIndex();
    QString text = ui->openedFilesList->itemText(index);
    if ( text.at(0) != '*')
        ui->openedFilesList->setItemText(index, "*" + text);
    QString fileId = ui->openedFilesList->itemData(index).toString();
    editedFiles->changeState(fileId, true);
}

void EditingWidget::markAsSaved(const QString &fileId)
{
    int index = ui->openedFilesList->findData(fileId,Qt::UserRole);
    if ( index == -1)
        return;
    QString text = ui->openedFilesList->itemText(index);
    ui->openedFilesList->setItemText(index, text.remove(QRegExp("^\\*")));
}

#include "commonsettings.h"
#include "ui_commonsettings.h"

CommonSettings::CommonSettings(QWidget *parent,PageData *pageData) :
    QWizardPage(parent),
    ui(new Ui::CommonSettings),
    m_data(pageData)
{
    ui->setupUi(this);
    ui->errorLabel->setVisible(false);
    QRegExp nameExpr("[a-zA-Z]+");// latin chars only
    ui->name->setValidator(new QRegExpValidator(nameExpr ,this));
    registerField("CommonSettings.name*",ui->name);
    registerField("CommonSettings.folder*",ui->folder);
    QCompleter *completer = new QCompleter(this);
    completer->setModel(new QDirModel(completer));

    ui->folder->setCompleter(completer);
}

CommonSettings::~CommonSettings()
{
    delete ui;
}

void CommonSettings::on_chooseFolder_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Choose Directory"),
                                                    "",
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);
    if(!dir.isEmpty())
    {
        QFileInfo d(dir);
        if(d.isWritable())
            ui->folder->setText(dir);
        else
        {
            QMessageBox::warning(0,  QObject::tr("Directory write protected"),
                                 QObject::tr("%1\nPlease choose another directory.")
                                 .arg(dir));
        }
    }
}

bool CommonSettings::isComplete() const
{
    if(ui->folder->text().isEmpty() || ui->name->text().isEmpty())
        return false;
    if(!QDir(ui->folder->text()).exists())
        return false;
    QFileInfo info(ui->folder->text());
    if(info.isWritable()){
        m_data->itemMap.insert("name",ui->name->text());
        m_data->itemMap.insert("folder",ui->folder->text());
        ui->errorLabel->setVisible(false);
        return true;
    }
    ui->errorLabel->setText(tr("Folder must be writable.\nPlease choose another folder."));
    ui->errorLabel->setVisible(true);
    return false;
}

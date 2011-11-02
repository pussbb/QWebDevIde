#include "startpage.h"
#include "ui_startpage.h"

StartPage::StartPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::StartPage)
{
    ui->setupUi(this);
    QTreeWidgetItem *phpGroup = new QTreeWidgetItem(ui->itemsTree);
    phpGroup->setText(0,tr("PHP projects"));
    QTreeWidgetItem *simple = new QTreeWidgetItem(phpGroup);
    simple->setText(0,tr("Empty php project"));
}

StartPage::~StartPage()
{
    delete ui;
}

bool StartPage::isComplete() const
{
    if(ui->itemsTree->currentIndex().isValid()
            && ui->itemsTree->currentItem()->childCount()  == 0)
         return true;
    else
        return false;
}

void StartPage::on_itemsTree_itemSelectionChanged()
{
    isComplete();
    emit(completeChanged());
}

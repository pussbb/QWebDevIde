#include "startpage.h"
#include "ui_startpage.h"

StartPage::StartPage(QWidget *parent,PageData *pageData) :
    QWizardPage(parent),
    ui(new Ui::StartPage),
    m_data(pageData)
{
    ui->setupUi(this);
    ///d = new PageData();
    ///m_pageOptions.inse= pageOptions;
    QTreeWidgetItem *phpGroup = new QTreeWidgetItem(ui->itemsTree);
    phpGroup->setText(0,tr("PHP projects"));
    phpGroup->setData(0,Qt::UserRole,"php");
    QTreeWidgetItem *simple = new QTreeWidgetItem(phpGroup);
    simple->setText(0,tr("Empty php project"));
    ///simple->setData(0,Qt::UserRole,"");
}

StartPage::~StartPage()
{
    delete ui;
}

bool StartPage::isComplete() const
{
    if(ui->itemsTree->currentIndex().isValid()
            && ui->itemsTree->currentItem()->childCount()  == 0){
     m_data->itemMap.insert("type",ui->itemsTree->currentItem()->parent()->data(0,Qt::UserRole).toString());
         return true;
    }
    else{
        return false;
    }
}

void StartPage::on_itemsTree_itemSelectionChanged()
{
    isComplete();
    emit(completeChanged());
}

#include "wizard.h"
#include "ui_wizard.h"
#include "startpage.h"
#include "commonsettings.h"
Wizard::Wizard(QWidget *parent) :
    QWizard(parent),
    ui(new Ui::Wizard)
{
    d = new PageData();
    ui->setupUi(this);
    setPage(0,new StartPage(this,d));
    setPage(1,new CommonSettings(this,d));
    connect(this,SIGNAL(accepted()),this,SLOT(saveResult()));
}

Wizard::~Wizard()
{
    delete ui;
}

void Wizard::saveResult()
{
    QString path = d->itemMap.value("folder").toString();
    QString type = d->itemMap.value("type").toString();
    QString name = d->itemMap.value("name","poject").toString();
    QSettings settings(path+"/"+name+".webpro",QSettings::IniFormat);
    foreach(QString key,d->itemMap.keys()){
        settings.setValue(key,d->itemMap.value(key));
    }
    settings.sync();
}

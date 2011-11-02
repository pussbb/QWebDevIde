#include "wizard.h"
#include "ui_wizard.h"
#include "startpage.h"
#include "commonsettings.h"
Wizard::Wizard(QWidget *parent) :
    QWizard(parent),
    ui(new Ui::Wizard)
{
    ui->setupUi(this);
    setPage(0,new StartPage(this));
    setPage(1,new CommonSettings(this));
}

Wizard::~Wizard()
{
    delete ui;
}

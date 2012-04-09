#include "findwidget.h"
#include "ui_findwidget.h"

FindWidget::FindWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FindWidget)
{
    ui->setupUi(this);
}

FindWidget::~FindWidget()
{
    delete ui;
}

#include "qwebdevide.h"
#include "ui_qwebdevide.h"

QWebDevIde::QWebDevIde(QWidget *parent) :
    QCoreWindow(parent),
    ui(new Ui::QWebDevIde)
{
    qDebug()<<appDir;
    ui->setupUi(this);
}

QWebDevIde::~QWebDevIde()
{
    delete ui;
}

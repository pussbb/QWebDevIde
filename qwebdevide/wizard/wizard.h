#ifndef WIZARD_H
#define WIZARD_H

#include <QWizard>
#include <pagedata.h>
#include <QDebug>
#include <QSettings>

namespace Ui {
    class Wizard;
}

class Wizard : public QWizard
{
    Q_OBJECT

public:
    explicit Wizard(QWidget *parent = 0);
    ~Wizard();
    ///QMap<QString, QVariant> pageOptions;

public slots:
    void saveResult();
private:
    Ui::Wizard *ui;
    PageData *d;
};

#endif // WIZARD_H

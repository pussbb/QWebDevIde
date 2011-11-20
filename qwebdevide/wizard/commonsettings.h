#ifndef COMMONSETTINGS_H
#define COMMONSETTINGS_H

#include <QWizardPage>
#include <QDir>
#include <QFileInfo>
#include <QMessageBox>
#include <QFileDialog>
#include <QCompleter>
#include <QDirModel>
#include <pagedata.h>
namespace Ui {
    class CommonSettings;
}

class CommonSettings : public QWizardPage
{
    Q_OBJECT

public:
    explicit CommonSettings(QWidget *parent = 0,PageData *pageData = 0);
    ~CommonSettings();
    QMap<QString,QVariant> pageOptions;
private slots:
    void on_chooseFolder_clicked();
protected:
    bool isComplete() const;
private:
    Ui::CommonSettings *ui;
    PageData *m_data;
};

#endif // COMMONSETTINGS_H

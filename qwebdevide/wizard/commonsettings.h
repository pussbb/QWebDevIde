#ifndef COMMONSETTINGS_H
#define COMMONSETTINGS_H

#include <QWizardPage>
#include <QDir>
#include <QFileInfo>
#include <QMessageBox>
#include <QFileDialog>
#include <QCompleter>
#include <QDirModel>

namespace Ui {
    class CommonSettings;
}

class CommonSettings : public QWizardPage
{
    Q_OBJECT

public:
    explicit CommonSettings(QWidget *parent = 0);
    ~CommonSettings();

private slots:
    void on_chooseFolder_clicked();
protected:
    bool isComplete() const;
private:
    Ui::CommonSettings *ui;
};

#endif // COMMONSETTINGS_H

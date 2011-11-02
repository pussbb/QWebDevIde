#ifndef STARTPAGE_H
#define STARTPAGE_H

#include <QWizardPage>
#include <QTreeWidgetItem>
#include <QDebug>
namespace Ui {
    class StartPage;
}

class StartPage : public QWizardPage
{
    Q_OBJECT

public:
    explicit StartPage(QWidget *parent = 0);
    ~StartPage();
protected:
    bool isComplete () const;
private slots:
   void on_itemsTree_itemSelectionChanged();

private:
    Ui::StartPage *ui;
};

#endif // STARTPAGE_H

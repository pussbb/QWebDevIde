#ifndef EDITINGWIDGET_H
#define EDITINGWIDGET_H

#include <QWidget>
#include <QPointer>
#include "abstracteditor.h"

namespace Ui {
    class EditingWidget;
}

class EditingWidget : public QWidget
{
    Q_OBJECT

public:
    explicit EditingWidget(QWidget *parent = 0);
    ~EditingWidget();
    void setCurrent(QString file);
    void refreshFileList(QMap<QString,AbstractEditor*> openedFiles);
private slots:
    void on_openedFilesList_currentIndexChanged(int index);
    void on_closeFile_clicked();

signals:
    void closeFile(QString fileName);
private:
    QPointer<QWidget> currentWidget;
    Ui::EditingWidget *ui;
    QString currentFileName;
    QMap<QString, AbstractEditor*> m_openedFiles;
    void setCentralWidget(QWidget *widget);
};

#endif // EDITINGWIDGET_H
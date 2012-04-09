#ifndef EDITINGWIDGET_H
#define EDITINGWIDGET_H

#include <QWidget>
#include <QPointer>
#include <QtCore>
#include <QKeyEvent>
#include <editedfiles.h>

namespace Ui {
    class EditingWidget;
}

class EditingWidget : public QWidget
{
    Q_OBJECT

public:
    explicit EditingWidget(QWidget *parent = 0, EditedFiles *ef = 0);
    ~EditingWidget();
    void setCurrent(QString file);
    void refreshFileList();
    QString currentFileId;
    void markAsSaved(const QString &fileId);
public slots:
    void contentChanged();

private slots:
    void on_openedFilesList_currentIndexChanged(int index);
    void on_closeFile_clicked();

protected:
    void keyPressEvent ( QKeyEvent * e );

signals:
    void closeFile(QString fileName);

private:
    Ui::EditingWidget *ui;
    EditedFiles *editedFiles;
    QPointer<QWidget> currentWidget;
    void setCentralWidget(QWidget *widget);
};

#endif // EDITINGWIDGET_H

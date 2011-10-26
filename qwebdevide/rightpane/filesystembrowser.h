#ifndef FILESYSTEMBROWSER_H
#define FILESYSTEMBROWSER_H

#include <QListView>
#include <QWidget>
#include <QFileSystemModel>
#include <QDir>
#include <QEvent>
#include <QMenu>
#include <QMouseEvent>
#include <QDebug>
class FileSystemBrowser : public QListView
{
    Q_OBJECT
public:
    explicit FileSystemBrowser(QWidget *parent = 0);
    QFileSystemModel *fileSysModel;
signals:

public slots:
    bool eventFilter( QObject* object, QEvent* event);
    void doubleClickedItem(QModelIndex);
    void customMenu(QPoint);

private:
    Q_DISABLE_COPY(FileSystemBrowser)
    QEvent *m_event;
};

#endif // FILESYSTEMBROWSER_H

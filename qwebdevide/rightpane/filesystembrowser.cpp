#include "filesystembrowser.h"

FileSystemBrowser::FileSystemBrowser(QWidget *parent) :
    QListView(parent)
{
    fileSysModel =  new QFileSystemModel;
    fileSysModel->setFilter(QDir::AllEntries);
    fileSysModel->setRootPath(QDir::currentPath());
    fileSysModel->sort(0,Qt::AscendingOrder);

    setModel(fileSysModel);
    setRootIndex(fileSysModel->index(QDir::currentPath()));

    viewport()->installEventFilter(this);
    setContextMenuPolicy(Qt::CustomContextMenu);

    connect(this,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(doubleClickedItem(QModelIndex)));
    connect(this,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(customMenu(QPoint)));
}

bool FileSystemBrowser::eventFilter(QObject *object, QEvent *event)
{
    m_event = event;
    return QListView::eventFilter( object, event );   // pass the event onwards
}

void FileSystemBrowser::doubleClickedItem(QModelIndex index)
{
    if (m_event->type() == QEvent::MouseButtonDblClick) {
      QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(m_event);
      if (mouseEvent->button() != Qt::LeftButton)
        return;
    }
    QFileInfo file = fileSysModel->fileInfo(index);
    if(file.isDir()){
       fileSysModel->setRootPath(file.absoluteFilePath());
       setRootIndex(fileSysModel->index(file.absoluteFilePath()));
    }
}

void FileSystemBrowser::customMenu(QPoint pos)
{
  /// QMenu *menu = new QMenu();
   QModelIndex index = indexAt(pos);
   qDebug()<< index;
    if(index.isValid()){
        qDebug()<< "delete remove";
    }
    else{
        qDebug()<<"create";
    }
    qDebug()<<pos;
}


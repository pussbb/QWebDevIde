#include "coreplugin.h"
#include "QDebug"
#include "QCoreApplication"
#include "QMainWindow"
#include "../../qwebdevide/bookmarkmanager.h"

#define qApp (static_cast<QApplication *>(QCoreApplication::instance()))

CorePlugin::CorePlugin()
{

}

QStringList CorePlugin::dependencies() const
{
    return QStringList();
}

void CorePlugin::init(QMap<QString, QObject *> dependencies, QObject *parent)
{
    BookmarkManager *bm =  static_cast<BookmarkManager *>(parent);
    qDebug()<<bm->test();
    qDebug()<<parent->objectName();
    Q_UNUSED(dependencies);
    foreach(QWidget *widget, qApp->topLevelWidgets()) {
      if(widget->inherits("QWebDevIde")){
          QMainWindow *mw = qobject_cast<QMainWindow *>(widget);
          menuBar =  mw->menuBar();
      }
    }

}

Q_EXPORT_PLUGIN2(core, CorePlugin);







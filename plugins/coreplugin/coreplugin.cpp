#include "coreplugin.h"
#include "QDebug"
#include "QCoreApplication"
#include "QMainWindow"
#define qApp (static_cast<QApplication *>(QCoreApplication::instance()))

void CorePlugin::init()
{
    qDebug()<<qApp;
    foreach(QWidget *widget, qApp->topLevelWidgets()) {
      if(widget->inherits("QWebDevIde")){
          QMainWindow *mw = qobject_cast<QMainWindow *>(widget);
          qDebug()<<mw->menuBar();
      }
    }
}

Q_EXPORT_PLUGIN2(core, CorePlugin);

#include "coreplugin.h"
#include "QDebug"
#include "QCoreApplication"
#include "QMainWindow"
#define qApp (static_cast<QApplication *>(QCoreApplication::instance()))

/*
QStringList CorePlugin::dependesis()
{
    return QStringList();
}*/
CorePlugin::CorePlugin()
{
}
QStringList CorePlugin::dependencies() const
{
    return QStringList();
}
void CorePlugin::init(QMap<QString, QObject *> dependencies)
{

    Q_UNUSED(dependencies);
    foreach(QWidget *widget, qApp->topLevelWidgets()) {
      if(widget->inherits("QWebDevIde")){
          QMainWindow *mw = qobject_cast<QMainWindow *>(widget);
          menuBar =  mw->menuBar();
      }
    }
}

Q_EXPORT_PLUGIN2(core, CorePlugin);







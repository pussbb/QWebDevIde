#include "pluginmanager.h"
#include "QCoreApplication"
#include "QMenuBar"
#include "editorsmanager.h"
#include "QMainWindow"

PluginManager::PluginManager(QObject *parent) :
    QObject(parent),
    pluginsDir(QCoreApplication::applicationDirPath() + QDir::toNativeSeparators("/plugins/"))

{
    qDebug()<<parent;
    QMainWindow *mw = qobject_cast<QMainWindow *>(parent);
    qDebug()<< mw->menuBar();
    qDebug()<<pluginsDir.entryList();
}

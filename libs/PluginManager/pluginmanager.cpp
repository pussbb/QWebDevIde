#include "pluginmanager.h"
#include "QDir"
#include "iplugin.h"

PluginManager::PluginManager(QObject *parent):
    QObject(parent)
{

    QString directory_path = QCoreApplication::applicationDirPath() + QDir::toNativeSeparators("/plugins/");
    QDirIterator directory_walker(directory_path, QDir::Files | QDir::NoSymLinks, QDirIterator::Subdirectories);

    while(directory_walker.hasNext())
    {
        directory_walker.next();
        QFileInfo fi = directory_walker.fileInfo();
        if(QLibrary::isLibrary(fi.fileName()))
            plugins.insert(fi.baseName(),fi);

    }
    loadPlugins();
}

void PluginManager::loadPlugins()
{
    foreach(const QString &file,plugins.keys())
    {
        QFileInfo fi = plugins.value(file);
        QPluginLoader pluginLoader(fi.absoluteFilePath());
            QObject *plugin = pluginLoader.instance();
            if (plugin) {
                qDebug()<<"loaded"+ fi.fileName();
                IPlugin *ip = qobject_cast<IPlugin *>(plugin);
                           ///plugins.insert(interface->dbDriverName(),interface);
                          ip->init();
            }
            else
            {
                qDebug()<< pluginLoader.errorString();
            }
    }
}

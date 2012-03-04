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
            plugins.insert(fi.baseName(), fi);

    }

    loadPlugins();
}

void PluginManager::loadPlugins()
{
    foreach(const QString &file,plugins.keys())
    {
        QFileInfo fi = plugins.value(file);
        loadPlugin(fi.absoluteFilePath(), fi.baseName());
    }
}

bool PluginManager::resolveDependecies(const QStringList &dependecies)
{
    if ( dependecies.empty())
        return true;

    foreach(const QString &file, dependecies) {
        QString baseName = "lib" + file;
        if ( ! initialized(baseName)) {
            QString filePath = plugins.value(baseName).absoluteFilePath();
            if ( filePath.isEmpty())
                return false;
            if ( ! loadPlugin(filePath, baseName))
                return false;
        }
    }
    return true;
}

bool PluginManager::loadPlugin(const QString &file, const QString &baseName)
{
    if ( initialized(baseName))
        return true;

    QPluginLoader pluginLoader(file);
    QObject *plugin = pluginLoader.instance();
    if (plugin) {
        IPlugin *ip = qobject_cast<IPlugin *>(plugin);
        if ( resolveDependecies(ip->dependencies())) {
            loadedPlugins.insert(baseName, plugin);
            ip->init();
            return true;
        }
        else {
            qDebug()<< "depencieses not resolve";
            return false;
        }
    }
    else
    {
        qDebug()<< pluginLoader.errorString();
        return false;
    }
    return false;
}

bool PluginManager::initialized(const QString &baseName)
{
    QObject *plugin = loadedPlugins.value(baseName);
    return plugin != NULL;
}

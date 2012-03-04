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
    m_dependecies.clear();
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
        m_dependecies.insert(file, m_loadedPlugins.value(baseName));
    }
    return true;
}

bool PluginManager::loadPlugin(const QString &file, const QString &baseName)
{
    if ( initialized(baseName))
        return true;

    QPluginLoader pluginLoader(file);
    pluginLoader.setLoadHints(QLibrary::ResolveAllSymbolsHint | QLibrary::ExportExternalSymbolsHint);
    QObject *plugin = pluginLoader.instance();
    if (plugin) {
        IPlugin *ip = qobject_cast<IPlugin *>(plugin);
        if ( resolveDependecies(ip->dependencies())) {
            m_loadedPlugins.insert(baseName, plugin);
            ip->init(m_dependecies);
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
    QObject *plugin = m_loadedPlugins.value(baseName);
    return plugin != NULL;
}

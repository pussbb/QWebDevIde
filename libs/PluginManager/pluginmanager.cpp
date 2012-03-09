#include "pluginmanager.h"
#include "QDir"
#include "iplugin.h"

PluginManager::PluginManager(QObject *parent, QString locale):
    QObject(parent),
    m_locale(locale),
    m_pluginPath(QCoreApplication::applicationDirPath() + QDir::toNativeSeparators("/plugins/"))
{
    QDirIterator directory_walker(m_pluginPath, QDir::Files | QDir::NoSymLinks, QDirIterator::Subdirectories);
    while(directory_walker.hasNext())
    {
        directory_walker.next();
        QFileInfo fi = directory_walker.fileInfo();
        if(QLibrary::isLibrary(fi.fileName()))
            plugins.insert(fi.baseName(), fi);
    }

    loadPlugins();
    loadTranslation();
}

void PluginManager::loadPlugins()
{
    foreach(const QString &file,plugins.keys())
    {
        QFileInfo fi = plugins.value(file);
        if ( ! loadPlugin(fi.absoluteFilePath(), fi.baseName()))
            plugins.remove(file);
    }
}

bool PluginManager::resolveDependecies(const QStringList &dependecies)
{qDebug()<<dependecies;
    m_dependecies.clear();
    if ( dependecies.empty())
        return true;

    foreach(const QString &file, dependecies) {
        QString baseName = "lib" + file;
        qDebug()<< file;
        qDebug()<<initialized(baseName);
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
            ip->init(m_dependecies, parent());
            return true;
        }
        else {
            qDebug()<< file;
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
// functions translate not tested
void PluginManager::loadTranslation(QString locale)
{
    if ( locale.isEmpty())
        locale = m_locale;

    foreach(const QString &file, m_loadedPlugins.keys())
    {
        QFileInfo fi = plugins.value(file);
        QTranslator *tr = new QTranslator();
        tr->load(m_pluginPath + fi.baseName() + "_" + locale);
        QCoreApplication::installTranslator(tr);
    }
}

void PluginManager::retranlsate(QString locale)
{
    loadTranslation(locale);
}

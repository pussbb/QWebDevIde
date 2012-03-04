#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include "PluginManager_global.h"
#include <QtCore>
#include <QList>

class PLUGINMANAGERSHARED_EXPORT PluginManager : public QObject {
    Q_OBJECT
public:
    explicit PluginManager(QObject *parent = 0);

private:
    QMap<QString, QFileInfo> plugins;
    bool resolveDependecies(const QStringList &dependecies);
    QMap<QString, QObject *> loadedPlugins;
    void loadPlugins();
    bool loadPlugin(const QString &file, const QString &baseName);
    bool initialized(const QString &baseName);
};
#endif // PLUGINMANAGER_H

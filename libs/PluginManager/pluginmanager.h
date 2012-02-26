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
    void loadPlugins();
};
#endif // PLUGINMANAGER_H

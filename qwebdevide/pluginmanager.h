#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include <QObject>
#include <QDir>
#include <QDebug>
class PluginManager : public QObject
{
    Q_OBJECT
public:
    explicit PluginManager(QObject *parent = 0);

signals:

public slots:

private:
    QDir pluginsDir;

};

#endif // PLUGINMANAGER_H

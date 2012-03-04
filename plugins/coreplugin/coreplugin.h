#ifndef COREPLUGIN_H
#define COREPLUGIN_H

#include <QtCore>
#include <QtGui>
#include <QObject>
#include "../../libs/PluginManager/iplugin.h"

class CorePlugin : public QObject, IPlugin
{
    Q_OBJECT
    Q_INTERFACES(IPlugin)

public:
    explicit CorePlugin();
    QStringList dependencies() const;
    void init(QMap<QString, QObject *> dependencies);
    QMenuBar *menuBar;
};

#endif // COREPLUGIN_H

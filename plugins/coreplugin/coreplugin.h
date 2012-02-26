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
    void init();
};

#endif // COREPLUGIN_H

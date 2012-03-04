#ifndef CODEEDITORPLUGIN_H
#define CODEEDITORPLUGIN_H

#include <QtCore>
#include <QtGui>
#include <QObject>
#include "../../libs/PluginManager/iplugin.h"
#include "../coreplugin/coreplugin.h"
class CodeEditorPlugin : public QObject, IPlugin
{
    Q_OBJECT
    Q_INTERFACES(IPlugin)

public:
    QStringList dependencies() const;
    void init(QMap<QString, QObject *> dependencies);
};

#endif // COREPLUGIN_H

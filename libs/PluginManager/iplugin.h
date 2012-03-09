#ifndef IPLUGIN_H
#define IPLUGIN_H
#include <QtCore>

class IPlugin
{
public:
    virtual ~IPlugin() {}
    virtual QStringList dependencies() const  = 0 ;
    virtual void init(QMap<QString, QObject *> dependencies, QObject *parent) = 0;
};

QT_BEGIN_NAMESPACE
Q_DECLARE_INTERFACE(IPlugin,
                    "com.pussbb.QWEBIDE.Plugin.IPlugin/0.1");
QT_END_NAMESPACE

#endif // IPLUGIN_H

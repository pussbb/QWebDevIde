#ifndef IPLUGIN_H
#define IPLUGIN_H

class IPlugin
{
public:
    virtual ~IPlugin() {}
    virtual void init() = 0;
};

QT_BEGIN_NAMESPACE
Q_DECLARE_INTERFACE(IPlugin,
                    "com.pussbb.QWEBIDE.Plugin.IPlugin/0.1");
QT_END_NAMESPACE

#endif // IPLUGIN_H

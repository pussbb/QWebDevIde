#ifndef IFACES_H
#define IFACES_H

#include <QtCore>

class IEditors
{
public:
    virtual ~IEditors() {}
    virtual QWidget * open(const QString &file) = 0;
    virtual bool save(const QString &fileName) = 0;
    virtual void close(const QString &fileName) = 0 ;
    virtual QStringList mimeTypes() = 0;

    QString errorString;
};

QT_BEGIN_NAMESPACE
Q_DECLARE_INTERFACE(IEditors,
                    "com.pussbb.QWEBIDE.Plugin.IEditors/0.1");
QT_END_NAMESPACE

class IRightPane
{
public:
    virtual ~IRightPane() {}
    virtual QWidget * getWidget() = 0;
    virtual QString widgetTitle() = 0 ;
};

QT_BEGIN_NAMESPACE
Q_DECLARE_INTERFACE(IRightPane,
                    "com.pussbb.QWEBIDE.Plugin.IRightPane/0.1");
QT_END_NAMESPACE


#endif // IFACES_H

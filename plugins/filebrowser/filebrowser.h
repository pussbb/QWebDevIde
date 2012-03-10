#ifndef FILEBROWSER_H
#define FILEBROWSER_H

#include <QtCore>
#include <QtGui>
#include <QObject>
#include <iplugin.h>
#include <ifaces.h>

#include <filesystembrowser.h>

class FileBrowser : public QObject, IPlugin, IRightPane
{
    Q_OBJECT
    Q_INTERFACES(IPlugin)
    Q_INTERFACES(IRightPane)

public:
    explicit FileBrowser();
    QStringList dependencies() const;
    void init(QMap<QString, QObject *> dependencies, QObject *parent);

    QWidget * getWidget();
    inline QString widgetTitle() { return tr("File browser");}

    QPointer<FileSystemBrowser> sysFileBrowser;

private:
    QObject *m_parent;
};

#endif // COREPLUGIN_H

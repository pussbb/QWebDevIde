#include "filebrowser.h"
#include "QDebug"

FileBrowser::FileBrowser()
{

}

QStringList FileBrowser::dependencies() const
{
    return QStringList();
}

void FileBrowser::init(QMap<QString, QObject *> dependencies, QObject *parent)
{
    Q_UNUSED(dependencies);
    m_parent = parent;
}

QWidget * FileBrowser::getWidget()
{
    if ( sysFileBrowser != NULL)
        return sysFileBrowser;

    sysFileBrowser = new FileSystemBrowser();
    connect(sysFileBrowser,SIGNAL(openFile(QString)), m_parent ,SLOT(openFile(QString)));
    return sysFileBrowser;

}

Q_EXPORT_PLUGIN2(FileBrowser, FileBrowser);









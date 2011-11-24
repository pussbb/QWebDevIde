#include "filetemplates.h"

FileTemplates::FileTemplates(QObject *parent) :
    QObject(parent)
{
    m_menu.setTitle(tr("New"));
    QString appDir = QCoreApplication::applicationDirPath()+QDir::toNativeSeparators("/");
    QFile file(appDir + "templates/file.json");
    file.open(QIODevice::ReadOnly);
    QTextStream stream ( &file );
    JsonReader reader;
    reader.parse(stream.readAll());
    ///QVariant v = reader.result();
        qDebug()<<reader.errorString();
        if(reader.errorString().isEmpty())
            buildMenu(reader.result());
}

void FileTemplates::buildMenu(QVariant v)
{
    foreach(QVariant rootIndex,v.toList()){
        QVariantMap root = rootIndex.toMap();
        QMenu *m = new QMenu();
        m->setTitle(root.value("catagory_name","Empty").toString());

        QVariantList childs = root.value("childs",QVariantList()).toList();
        if(childs.count() == 0)
            continue;
        foreach(QVariant child,childs){
            QVariantMap item = child.toMap();
            QAction *action = new QAction(this);
            action->setText(item.value("default_name").toString());
            action->setData(item);
            m->addAction(action);
            connect(action, SIGNAL(triggered()), this, SLOT(create()));
            qDebug()<<item.value("default_name");
        }
        m_menu.addMenu(m);
    }
}

QMenu * FileTemplates::getTemplatesMenu()
{
    return &m_menu;
}

void FileTemplates::create()
{
    QAction *action = qobject_cast<QAction *>(sender());
    qDebug()<<sender();
    if(action == NULL)
        return;
    qDebug()<<action->data();
}

#include "filetemplates.h"

FileTemplates::FileTemplates(QObject *parent) :
    QObject(parent)
{
    m_menu.setTitle(tr("New"));
    templateDir = QCoreApplication::applicationDirPath()+QDir::toNativeSeparators("/templates/");
    QFile file(templateDir + "file.json");
    file.open(QIODevice::ReadOnly);
    QTextStream stream ( &file );
    JsonReader reader;
    reader.parse(stream.readAll());
    if(reader.errorString().isEmpty())
        buildMenu(reader.result());

}

void FileTemplates::buildMenu(QVariant v)
{
    foreach(QVariant rootIndex,v.toList()){
        QVariantMap root = rootIndex.toMap();
        QMenu *m = new QMenu();
        m->setTitle(root.value("catagory_name","Empty").toString());

        QVariantList childs = root.value("items",QVariantList()).toList();
        if(childs.count() == 0)
            continue;
        foreach(QVariant child,childs){
            QVariantMap item = child.toMap();
            QAction *action = new QAction(this);
            action->setText(item.value("title").toString());
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
    QFileInfo fi(folder);

    if(!fi.isDir()){
        QMessageBox::critical(0, tr("QWebIde"),
                                        tr("Folder does not exists."),
                                        QMessageBox::Ok);
        return;
    }

    if(!fi.isWritable()){
        QMessageBox::critical(0, tr("QWebIde"),
                                        tr("Folder is not writable."),
                                        QMessageBox::Ok);
        return;
    }

    if(action == NULL)
        return;
    bool ok;
    QVariantMap templateData = action->data().toMap();
    QString fileName = QInputDialog::getText(0, tr("Create new file"),
                                             tr("File name"), QLineEdit::Normal,
                                             templateData.value("default_name","new").toString() + "." +
                                             templateData.value("file_ext","").toString(), &ok);
    if (ok && !fileName.isEmpty()){
        QFile file(templateDir + templateData.value("file","").toString());
        if(file.isReadable()){
            QMessageBox::critical(0, tr("QWebIde"),
                                            tr("Template file does not exists."),
                                            QMessageBox::Ok);
            return;
        }
        file.copy(folder +QDir::toNativeSeparators("/")+ fileName);
    }
}

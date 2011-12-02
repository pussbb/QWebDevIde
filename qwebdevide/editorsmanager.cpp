#include "editorsmanager.h"
#include <codeeditor.h>

EditorsManager::EditorsManager(QObject *parent) :
    QObject(parent)
{
    m_editingWidget = new EditingWidget(0);
    connect(m_editingWidget,SIGNAL(closeFile(QString)),
            this,SLOT(closeFile(QString)));
}

void EditorsManager::openFile(QString file)
{
  qDebug()<<"open file"<< file;
  AbstractEditor *editor = new AbstractEditor;
  editor->openFile(file);
  openedFiles.insert(editor->fileName(),editor);
  m_editingWidget->refreshFileList(openedFiles);
  m_editingWidget->setCurrent(editor->fileName());

}

void EditorsManager::closeFile(QString file)
{
    AbstractEditor *editor = openedFiles.value(file);
    if(editor != NULL){
        editor->deleteLater();
        openedFiles.remove(file);
        m_editingWidget->refreshFileList(openedFiles);
    }
}


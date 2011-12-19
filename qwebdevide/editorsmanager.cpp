#include "editorsmanager.h"
#include <codeeditor.h>

EditorsManager::EditorsManager(QObject *parent) :
    QObject(parent)
{
    m_editingWidget = new EditingWidget(0);
    connect(m_editingWidget,SIGNAL(closeFile(QString)),
            this,SLOT(closeFile(QString)));
    syntax = new HighlightManager(this);
}

void EditorsManager::openFile(QString file)
{
  qDebug()<<"open file"<< file;
  AbstractEditor *editor = new AbstractEditor;
  editor->openFile(file);
  CodeEditor *codeEditor = editor->getEditorWidget();
  if ( codeEditor != NULL) {
    QFileInfo *fi = editor->fileInfo();
    codeEditor->highlighter->highlightingRules.clear();
    codeEditor->setBackgroundColor(syntax->getEditorBackround());
    codeEditor->highlighter->highlightingRules = syntax->getHighlighting(fi->completeSuffix());
    codeEditor->highlighter->commentEndExpression = syntax->getEndMultiComments(fi->completeSuffix());
    codeEditor->highlighter->commentStartExpression = syntax->getStartMultiComments(fi->completeSuffix());
    codeEditor->highlighter->multiLineCommentFormat = syntax->getMultiCommentsFormart();
    emit(codeEditor->highlighter->rehighlight());
  }

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

void EditorsManager::saveCurrent()
{
    AbstractEditor *editor = openedFiles.value(m_editingWidget->currentFileName);
    if (editor == NULL)
        return;
    editor->saveFile();
}



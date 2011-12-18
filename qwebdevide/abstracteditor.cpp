#include "abstracteditor.h"

AbstractEditor::AbstractEditor(QObject *parent) :
    QObject(parent)
{
    m_editor = new CodeEditor;
}
void AbstractEditor::openFile(QString fileName)
{
       m_editor->openFile(fileName);
       m_fileInfo = new QFileInfo(fileName);
}

bool AbstractEditor::saveFile()
{
    return m_editor->saveFile(m_fileInfo->absoluteFilePath());
}


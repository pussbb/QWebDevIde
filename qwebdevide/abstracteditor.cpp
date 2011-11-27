#include "abstracteditor.h"

AbstractEditor::AbstractEditor(QObject *parent) :
    QObject(parent)
{
    m_editor = new CodeEditor;
}
void AbstractEditor::openFile(QString fileName)
{
        QFile f(fileName);
        if (f.open(QFile::ReadOnly | QFile::Text))
            m_editor->setPlainText(f.readAll());
        m_fileInfo = new QFileInfo(fileName);
}

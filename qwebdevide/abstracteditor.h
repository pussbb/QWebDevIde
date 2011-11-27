#ifndef ABSTRACTEDITOR_H
#define ABSTRACTEDITOR_H

#include <QObject>
#include <codeeditor.h>
#include <QDebug>
#include <QFile>
#include <QFileInfo>
class AbstractEditor : public QObject
{
    Q_OBJECT
public:
    explicit AbstractEditor(QObject *parent = 0);
    inline QString fileName(){return m_fileInfo->baseName();}
    inline CodeEditor * getEditorWidget(){return m_editor;}
    inline QFileInfo * fileInfo(){return m_fileInfo;}
    void openFile(QString fileName);
signals:

public slots:

private:
    QString  m_fileName;
    CodeEditor *m_editor;
    QFileInfo *m_fileInfo;

};

#endif // ABSTRACTEDITOR_H

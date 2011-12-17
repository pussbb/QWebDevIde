#ifndef EDITORMANAGER_H
#define EDITORMANAGER_H

#include <QObject>
#include <codeeditor.h>
#include <QDebug>
#include <QFile>
#include "mimedata.h"
#include <editingwidget.h>
#include <abstracteditor.h>
#include <highlightmanager.h>

class EditorsManager : public QObject
{
    Q_OBJECT
public:
    explicit EditorsManager(QObject *parent = 0);
    void openProject(QString fileName);
    inline QWidget * getMainEditorWidget(){return m_editingWidget;}
    QMap<QString,AbstractEditor*> openedFiles;
    void saveCurrent();
    HighlightManager *syntax;
signals:

public slots:
    void openFile(QString );
    void closeFile(QString );
private :
    MimeData mime;
    EditingWidget *m_editingWidget;
};

#endif // EDITORMANAGER_H

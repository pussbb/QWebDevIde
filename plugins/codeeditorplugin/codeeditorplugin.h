#ifndef CODEEDITORPLUGIN_H
#define CODEEDITORPLUGIN_H

#include <QtCore>
#include <QtGui>
#include <QObject>
#include <iplugin.h>
#include <ifaces.h>
#include "codeeditor/codeeditor.h"

class CodeEditorPlugin : public QObject, IPlugin, IEditors
{
    Q_OBJECT
    Q_INTERFACES(IPlugin)
    Q_INTERFACES(IEditors)

signals:
    void editorCreated(CodeEditor *);

public:
    QStringList dependencies() const;
    void init(QMap<QString, QObject *> dependencies, QObject *parent);
    QWidget * open(const QString &file);
    bool save(const QString &fileName);
    void close(const QString &fileName);
    QStringList mimeTypes();
    QString errorString;
    QMap<QString, CodeEditor *> openedFiles;
};

#endif // COREPLUGIN_H

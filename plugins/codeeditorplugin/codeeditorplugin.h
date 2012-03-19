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
    void editorCreated(CodeEditor *, const QString &);
    void aboutToClose(const QString &);

public:
    QStringList dependencies() const;
    void init(QMap<QString, QObject *> dependencies, QObject *parent);
    QWidget * open(const QString &file, const QString &fileId);
    bool save(const QString &fileId);
    void close(const QString &fileId);
    QStringList mimeTypes();
    QString errorString;
    QMap<QString, CodeEditor *> openedFiles;
};

#endif // COREPLUGIN_H

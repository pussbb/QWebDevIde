#ifndef COLORSCHEME_H
#define COLORSCHEME_H

#include <QtCore>
#include <QObject>
#include <QTextCharFormat>
#include <QFile>
#include "../../libs/PluginManager/iplugin.h"
#include <codeeditor.h>

class ColorScheme : public QObject, IPlugin
{
    Q_OBJECT
    Q_INTERFACES(IPlugin)

public:
    explicit ColorScheme();
    QStringList dependencies() const;
    void init(QMap<QString, QObject *> dependencies, QObject *parent);
    void initScheme(const QString & fileName = "default");
    QColor getEditorBackround();
    inline QMap<QString,QTextCharFormat> currentColorScheme() {return m_colorScheme;}

public slots:
    void setEditorColorScheme(CodeEditor *editor, const QString &);
private:
    QString appPath;
    QString schemesPath;
    QMap<QString,QTextCharFormat> m_colorScheme;
};

#endif // COREPLUGIN_H

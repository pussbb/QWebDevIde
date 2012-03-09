#ifndef SYNTAXHIGHLIGHTER_H
#define SYNTAXHIGHLIGHTER_H

#include <QtCore>
#include "../../libs/PluginManager/iplugin.h"
#include <codeeditor.h>
#include <highlightmanager.h>
class SyntaxHighlighter : public QObject, IPlugin
{
    Q_OBJECT
    Q_INTERFACES(IPlugin)

public:
    explicit SyntaxHighlighter();
    QStringList dependencies() const;
    void init(QMap<QString, QObject *> dependencies, QObject *parent);

    QMap<QString , AbstractSyntaxHighlight*> syntaxes;
    QVector<HighlightingRule> getHighlighting(QString syntax = "");
    QRegExp getStartMultiComments(QString syntax = "");
    QRegExp getEndMultiComments(QString syntax = "");
    QTextCharFormat getMultiCommentsFormart();
    QColor getEditorBackround();

public slots:
    void setEditorColorScheme(CodeEditor *editor);

private:
    HighlightManager *highlightManager;
    void initSyntaxes();
    QString syntaxesPath;
    QMap<QString,QTextCharFormat> m_colorScheme;
};

#endif

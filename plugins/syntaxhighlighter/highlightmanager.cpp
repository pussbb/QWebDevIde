#include "highlightmanager.h"

HighlightManager::HighlightManager(QObject *parent) :
    QObject(parent)
{
    QString appDir =  QDir::toNativeSeparators ( QCoreApplication::applicationDirPath()+QDir::toNativeSeparators("/"));
    syntaxesPath = appDir + QDir::toNativeSeparators("syntax/");
    initSyntaxes();
}

void HighlightManager::initSyntaxes()
{
    QDir dir(syntaxesPath);
    QStringList filters;
    filters << "*.json";
    dir.setNameFilters(filters);
    QFileInfoList files = dir.entryInfoList();

    foreach(const QFileInfo &file,files){
        if( ! file.isReadable())
            continue;
        QString fileName = file.baseName();
        AbstractSyntaxHighlight *syntax = new AbstractSyntaxHighlight(this);
        syntax->setColorScheme(m_colorScheme);
        bool ok = syntax->initSyntax(file.absoluteFilePath());

        if ( ok)
            syntaxes.insert(fileName,syntax);
    }

    foreach(const QString &file,syntaxes.keys()){
        AbstractSyntaxHighlight *syntax = syntaxes.value(file);
        if ( syntax == NULL)
            continue;
        syntax->dependenciesWalk(syntaxes);
        ///qDebug()<< syntax->sectionHighlightingRules;
    }
}

QVector<HighlightingRule> HighlightManager::getHighlighting(QString syntax)
{
    if( ! syntaxes.contains(syntax))
        syntax = "default";

    if( ! syntaxes.contains(syntax))
        return QVector<HighlightingRule> ();

    return syntaxes.value(syntax)->highlightingRules;
}

QRegExp HighlightManager::getStartMultiComments(QString syntax)
{
    if( ! syntaxes.contains(syntax))
        syntax = "default";

    if( ! syntaxes.contains(syntax))
        return QRegExp();

    return syntaxes.value(syntax)->commentStartExpression;
}

QRegExp HighlightManager::getEndMultiComments(QString syntax)
{
    if( ! syntaxes.contains(syntax))
        syntax = "default";

    if( ! syntaxes.contains(syntax))
        return QRegExp();

    return syntaxes.value(syntax)->commentEndExpression;
}

QTextCharFormat HighlightManager::getMultiCommentsFormart()
{
    return m_colorScheme.value("multiline_comment");
}

QVector<sectionHighlightingRule> HighlightManager::getSectionHighlighting(QString syntax)
{
    if( ! syntaxes.contains(syntax))
        syntax = "default";

    if( ! syntaxes.contains(syntax))
        return QVector<sectionHighlightingRule> ();

    return syntaxes.value(syntax)->sectionHighlightingRules;
}


#include "abstractsyntaxhighlight.h"

AbstractSyntaxHighlight::AbstractSyntaxHighlight(QObject *parent) :
    QObject(parent)
{
}

bool AbstractSyntaxHighlight::initSyntax(const QString &fileName)
{

    QFile f(fileName);
    if(!f.open(QIODevice::ReadOnly))
        return false;
    QTextStream stream(&f);
    stream.setCodec("UTF-8");
    JsonReader reader;
    reader.parse(stream.readAll());

    if( !reader.errorString().isEmpty())
        return false;
    QVariant v = reader.result();
    if(!v.canConvert(QVariant::Map))
        return false;

    QVariantMap syntax = v.toMap();
    description  = syntax.value("description",QVariantMap()).toMap();
    syntax.remove("description");
    dependencies = syntax.value("dependencies",QStringList()).toStringList();
    syntax.remove("dependencies");

    v = syntax.value("multiline_comment");
    if ( v.canConvert(QVariant::Map)){
        QVariantMap multiLine = v.toMap();qDebug()<<multiLine;
        commentStartExpression = QRegExp(multiLine.value("open","").toString());
        commentEndExpression  = QRegExp(multiLine.value("close","").toString());
        qDebug()<<commentStartExpression.pattern();
    }
    syntax.remove("multiline_comment");
    foreach(const QString &key,syntax.keys()){

        QVariant item = syntax.value(key);
        if( ! item.canConvert(QVariant::List))
            continue;
        QStringList rules = item.toStringList();
        QTextCharFormat colorScheme = m_colorScheme.value(key,QTextCharFormat());
        HighlightingRule rule;
        foreach (const QString &pattern,rules) {
            rule.pattern = QRegExp(pattern);
            rule.format = colorScheme;
            highlightingRules.append(rule);
        }
    }
    return true;
}

void AbstractSyntaxHighlight::dependenciesWalk(QMap<QString, AbstractSyntaxHighlight *> existing)
{
    if(dependencies.isEmpty())
        return;
    foreach(const QString &file,dependencies){
        AbstractSyntaxHighlight *syntax = existing.value(file);
        if ( syntax == NULL)
            continue;
        highlightingRules << syntax->highlightingRules;
        ///commentStartExpression
    }
}



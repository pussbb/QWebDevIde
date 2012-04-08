#include "abstractsyntaxhighlight.h"

AbstractSyntaxHighlight::AbstractSyntaxHighlight(QObject *parent) :
    QObject(parent)
{
    dependenciesResolved = false;
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
    f.close();
    if( !reader.errorString().isEmpty())
        return false;
    QVariant v = reader.result();
    reader.~JsonReader();
    if(!v.canConvert(QVariant::Map))
        return false;

    QVariantMap syntax = v.toMap();
    description  = syntax.value("description",QVariantMap()).toMap();

    syntax.remove("description");
    dependencies = syntax.value("dependencies",QStringList()).toMap();
    syntax.remove("dependencies");

    v = syntax.value("multiline_comment");
    if ( v.canConvert(QVariant::Map)){
        QVariantMap multiLine = v.toMap();
        commentStartExpression = QRegExp(multiLine.value("open","").toString());
        commentEndExpression = QRegExp(multiLine.value("close","").toString());
    }
    syntax.remove("multiline_comment");
    QVector<HighlightingRule> m_highlightingRules;
    foreach(const QString &key,syntax.keys()){

        QVariant item = syntax.value(key);
        if( ! item.canConvert(QVariant::List))
            continue;
        QStringList rules = item.toStringList();
        QTextCharFormat colorScheme = m_colorScheme.value(key,QTextCharFormat());
        HighlightingRule rule;
        foreach (const QString &pattern,rules) {
            rule.pattern.setPattern(pattern);
            rule.pattern.setPatternSyntax(QRegExp::RegExp2);
            rule.format = colorScheme;
            m_highlightingRules.append(rule);
        }
    }
    if ( description.contains("section"))
    {
        section =  description.value("section").toMap();
        sectionHighlightingRule sectionHighlighting;

        sectionHighlighting.start.setPattern(section.value("start").toString());
        sectionHighlighting.stop.setPattern(section.value("stop").toString());
        sectionHighlighting.opened = false;
        sectionHighlighting.count = 0;
        sectionHighlighting.auto_decrease = section.value("auto_decrease",true).toBool();
        sectionHighlighting.highlightingRules << m_highlightingRules;
        sectionHighlightingRules.append(sectionHighlighting);
    }
    else
    {
        highlightingRules << m_highlightingRules;
    }
    m_highlightingRules.clear();
    m_highlightingRules.squeeze();
    syntax.clear();
    return true;
}

void AbstractSyntaxHighlight::dependenciesWalk(QMap<QString, AbstractSyntaxHighlight *> existing)
{
    if(dependencies.isEmpty() || dependenciesResolved){
        dependenciesResolved = true;
        return;
    }
    foreach(const QString &file,dependencies.keys()){
        QVariantMap dependency = dependencies.value(file).toMap();
        AbstractSyntaxHighlight *syntax = existing.value(file);

        if ( syntax == NULL)
            continue;

        if ( ! syntax->dependenciesResolved)
            syntax->dependenciesWalk(existing);

        if ( dependency.contains("start")) {
            sectionHighlightingRule sectionHighlighting;
            sectionHighlighting.start.setPattern(dependency.value("start").toString());
            sectionHighlighting.stop.setPattern(dependency.value("stop").toString());
            sectionHighlighting.highlightingRules << syntax->highlightingRules;
            sectionHighlighting.count = 0;
            sectionHighlighting.opened = false;
            sectionHighlighting.auto_decrease = dependency.value("auto_decrease",true).toBool();
            sectionHighlightingRules.append(sectionHighlighting);
        }
        else {
            highlightingRules << syntax->highlightingRules;
        }

        if(commentStartExpression.isEmpty()) {
            commentStartExpression = syntax->commentStartExpression;
        }
        else {
            QString expression = commentStartExpression.pattern();
            expression.append("|" + syntax->commentStartExpression.pattern());
            commentStartExpression = QRegExp(expression);
        }

        if(commentEndExpression.isEmpty()){
            commentEndExpression = syntax->commentEndExpression;
        }
        else{
            QString expression = commentEndExpression.pattern();
            expression.append("|" + syntax->commentEndExpression.pattern());
            commentEndExpression = QRegExp(expression);
        }
    }
    dependenciesResolved = true;
}



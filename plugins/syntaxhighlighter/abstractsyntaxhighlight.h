#ifndef ABSTRACTSYNTAXHIGHLIGHT_H
#define ABSTRACTSYNTAXHIGHLIGHT_H



#include <QObject>
#include "json.h"
#include "QtCore"
#include "QRegExp"
#include "QTextCharFormat"
#include "global.h"

class AbstractSyntaxHighlight : public QObject
{
    Q_OBJECT
public:
    QVector<HighlightingRule> highlightingRules;
    QVector<sectionHighlightingRule> sectionHighlightingRules;
    explicit AbstractSyntaxHighlight(QObject *parent = 0);
    inline void setColorScheme(QMap<QString,QTextCharFormat> colorScheme)
                        { if ( ! colorScheme.isEmpty()) m_colorScheme = colorScheme;}
    bool initSyntax(const QString &fileName);
    void dependenciesWalk(QMap<QString ,AbstractSyntaxHighlight*> existing);
    QVariantMap description;
    QRegExp commentStartExpression;
    QRegExp commentEndExpression;
    bool dependenciesResolved;
    QVariantMap section;
private:
    QMap<QString,QTextCharFormat> m_colorScheme;
    QVariantMap dependencies;
};

#endif // ABSTRACTSYNTAXHIGHLIGHT_H

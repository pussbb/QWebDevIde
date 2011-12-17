#ifndef ABSTRACTSYNTAXHIGHLIGHT_H
#define ABSTRACTSYNTAXHIGHLIGHT_H



#include <QObject>
#include "json.h"
#include "QtCore"
#include "QRegExp"
#include "QTextCharFormat"

struct HighlightingRule {
    QRegExp pattern;
    QTextCharFormat format;
};
class AbstractSyntaxHighlight : public QObject
{
    Q_OBJECT
public:
    QVector<HighlightingRule> highlightingRules;
    explicit AbstractSyntaxHighlight(QObject *parent = 0);
    inline void setColorScheme(QMap<QString,QTextCharFormat> colorScheme)
                        { if ( ! colorScheme.isEmpty()) m_colorScheme = colorScheme;}
    bool initSyntax(const QString &fileName,QMap<QString ,AbstractSyntaxHighlight*> existing);
private:
    QMap<QString,QTextCharFormat> m_colorScheme;
};

#endif // ABSTRACTSYNTAXHIGHLIGHT_H

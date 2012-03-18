#ifndef HIGHLIGHTER_H
#define HIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include "../global.h"
#include <QHash>
#include <QTextCharFormat>
#include <textblockdata.h>

QT_BEGIN_NAMESPACE
class QTextDocument;
QT_END_NAMESPACE

class Highlighter : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    Highlighter(QTextDocument *parent = 0);
    QVector<HighlightingRule> highlightingRules;
    QVector<sectionHighlightingRule> sectionHighlightingRules;
    QRegExp commentStartExpression;
    QRegExp commentEndExpression;
    QTextCharFormat multiLineCommentFormat;
protected:
    void highlightBlock(const QString &text);

private:
};
#endif

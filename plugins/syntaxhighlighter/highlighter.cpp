
#include <QtGui>

#include "highlighter.h"


Highlighter::Highlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{

}

void Highlighter::highlightBlock(const QString &text)
{
    TextBlockData *data = new TextBlockData;

    QString m_matchBracketsList = "()[]{}<>";
    for ( int bracketIndex=0; bracketIndex<m_matchBracketsList.length(); bracketIndex++ )
    {
        QChar bracket       = m_matchBracketsList[bracketIndex];
        int bracketPosition = text.indexOf(bracket);

        while ( bracketPosition != -1 )
        {
            ParenthesisInfo *info = new ParenthesisInfo;
            info->character =  bracket;
            info->position = bracketPosition;

            data->insert(info);
            bracketPosition = text.indexOf(bracket, bracketPosition + 1);
        }
    }

    setCurrentBlockUserData(data);
    if(!highlightingRules.isEmpty()){
        foreach (const HighlightingRule &rule, highlightingRules) {
            QRegExp expression(rule.pattern);
            int index = expression.indexIn(text);
            while (index >= 0) {
                int length = expression.matchedLength();
                setFormat(index, length, rule.format);
                index = expression.indexIn(text, index + length);
            }
        }
    }
    setCurrentBlockState(0);

    if(commentStartExpression.isEmpty() || commentEndExpression.isEmpty())
        return;

    int startIndex = 0;
    if (previousBlockState() != 1)
        startIndex = commentStartExpression.indexIn(text);

    while (startIndex >= 0) {
        int endIndex = commentEndExpression.indexIn(text, startIndex);
        int commentLength;
        if (endIndex == -1) {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        } else {
            commentLength = endIndex - startIndex
                    + commentEndExpression.matchedLength();
        }
        setFormat(startIndex, commentLength, multiLineCommentFormat);
        startIndex = commentStartExpression.indexIn(text, startIndex + commentLength);
    }
}


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
    QVector<HighlightingRule> rules = highlightingRules;
    if ( ! sectionHighlightingRules.isEmpty()) {
        for (int i = 0; i < sectionHighlightingRules.size(); ++i) {
            sectionHighlightingRule section = sectionHighlightingRules[i];

            if (section.start.isEmpty() ||
                    section.stop.isEmpty())
                rules << section.highlightingRules;
            int index = currentBlock().position();
            int sectionStart = document()
                    ->find(section.start,currentBlock().position(),QTextDocument::FindBackward)
                    .position();
            int sectionEnd = document()
                    ->find(section.stop,currentBlock().position(),QTextDocument::FindBackward)
                    .position();
            bool inSection = ((sectionStart >= 0 && sectionEnd < 0)
                             || (sectionStart >= index && sectionEnd <= index ));
            if ( section.start.indexIn(text) >= 0
                 || inSection){
                setCurrentBlockState(i);
                section.opened = true;
            }

            if ( section.opened )
            {
                rules << section.highlightingRules;
            }

            if ( section.stop.indexIn(text) >= 0){
                section.opened = false;
                setCurrentBlockState(-1);
            }

            sectionHighlightingRules[i] = section;
        }
    }
    if( ! rules.isEmpty()){
        foreach (const HighlightingRule &rule, rules) {
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
    ///emit(rehighlight());
}

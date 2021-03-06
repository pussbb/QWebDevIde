
#include <QtGui>

#include "highlighter.h"


Highlighter::Highlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{

}

Highlighter::~Highlighter()
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

    highlight(highlightingRules, text);
    QVector<HighlightingRule> rules = highlightingRules;
    if ( ! sectionHighlightingRules.isEmpty()) {
        for (int i = 0; i < sectionHighlightingRules.size(); ++i) {
            sectionHighlightingRule section = sectionHighlightingRules[i];

            int index = currentBlock().position();

            if ( section.start.indexIn(text) >= 0) {
                section.opened = true;
                ++section.count;
            }
            if ( ! section.opened ) {
                int sectionStart = document()
                        ->find(section.start,currentBlock().position(),QTextDocument::FindBackward)
                        .position();

                int sectionEnd = document()
                        ->find(section.stop,sectionStart)
                        .position();

                if (sectionStart <= index && sectionEnd >= index) {
                    ++section.count;
                }
                else{
                    if (section.count > 0 && section.auto_decrease )
                        --section.count;
                }
            }

            if ( section.opened || section.count > 0)
            {
                highlight(section.highlightingRules, text);
                if ( section.stop.indexIn(text) >= 0) {
                    if (section.count > 0 )
                        --section.count;
                    section.opened = false;
                }
            }
            sectionHighlightingRules[i] = section;
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

void Highlighter::highlight(const QVector<HighlightingRule> &m_highlightingRules, const QString &text)
{

    if( m_highlightingRules.isEmpty() || text.isEmpty())
        return;

    foreach (const HighlightingRule &rule, m_highlightingRules ) {
        int index = rule.pattern.indexIn(text);
        int length = 0;
        while ((index = rule.pattern.indexIn(text, index + length)) != -1) {
            length = rule.pattern.matchedLength();
            setFormat(index, length, rule.format);
        }
    }

}



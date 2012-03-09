#include "textblockdata.h"

TextBlockData::TextBlockData()
{
    // Nothing to do
}

QVector<ParenthesisInfo *> TextBlockData::parentheses()
{
    return m_parentheses;
}

void TextBlockData::insert(ParenthesisInfo *info)
{
    int i = 0;
    while (i < m_parentheses.size() &&
           info->position > m_parentheses.at(i)->position)
        ++i;

    m_parentheses.insert(i, info);
}


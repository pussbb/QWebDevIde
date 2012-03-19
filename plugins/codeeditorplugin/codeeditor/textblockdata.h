#ifndef TEXTBLOCKDATA_H
#define TEXTBLOCKDATA_H

#include <QTextBlockUserData>
#include <QVector>
class QString;
class QTextDocument;

struct ParenthesisInfo
{
    QChar character;
    int position;
};

class TextBlockData : public QTextBlockUserData
{
public:
    TextBlockData();
    ~TextBlockData();
    QVector<ParenthesisInfo *> parentheses();
    void insert(ParenthesisInfo *info);

private:
    QVector<ParenthesisInfo *> m_parentheses;
};

#endif // TEXTBLOCKDATA_H

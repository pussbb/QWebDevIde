#ifndef GLOBAL_H
#define GLOBAL_H


struct HighlightingRule
{
    QRegExp pattern;
    QTextCharFormat format;
};

struct sectionHighlightingRule
{
    QRegExp start;
    QRegExp stop;
    QVector<HighlightingRule> highlightingRules;
    bool opened;
    bool auto_decrease;
    int count;
};

struct LineAreaStyle {
    QBrush backgroundBrush;
    QPen textPen;
    QColor lineColor;
};

#endif // GLOBAL_H

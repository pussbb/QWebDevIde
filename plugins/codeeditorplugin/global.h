#ifndef GLOBAL_H
#define GLOBAL_H
struct HighlightingRule
{
    QRegExp pattern;
    QTextCharFormat format;
};

struct LineAreaStyle {
    QBrush backgroundBrush;
    QPen textPen;
    QColor lineColor;
};

#endif // GLOBAL_H

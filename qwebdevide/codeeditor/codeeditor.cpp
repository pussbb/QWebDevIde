#include <QtGui>

#include "codeeditor.h"



CodeEditor::CodeEditor(QWidget *parent) : QPlainTextEdit(parent)
{
    lineNumberArea = new LineNumberArea(this);

    connect(this, SIGNAL(blockCountChanged(int)),
            this, SLOT(updateLineNumberAreaWidth(int)));
    connect(this, SIGNAL(updateRequest(QRect,int)),
            this, SLOT(updateLineNumberArea(QRect,int)));
    connect(this, SIGNAL(cursorPositionChanged()),
            this, SLOT(highlightCurrentLine()));

  ////  bool on= true;
    QTextOption option =  document()->defaultTextOption();
    ///if (on)
    option.setFlags(option.flags() |QTextOption::IncludeTrailingSpaces| QTextOption::ShowTabsAndSpaces  );
    // else
    //       option.setFlags(option.flags() & ~QTextOption::ShowTabsAndSpaces);
    QPalette p = palette();
    p.setColor(QPalette::Base, QColor(240, 240, 255));
    setPalette(p);

    document()->setDefaultTextOption(option);
    highlighter = new Highlighter(document());
    updateLineNumberAreaWidth(0);
    highlightCurrentLine();
}

int CodeEditor::lineNumberAreaWidth()
{
    int digits = 1;
    int max = qMax(1, blockCount());
    while (max >= 10) {
        max /= 10;
        ++digits;
    }

    int space = 30 + fontMetrics().width(QLatin1Char('9')) * digits;

    return space;
}


void CodeEditor::updateLineNumberAreaWidth(int /* newBlockCount */)
{
    setViewportMargins(lineNumberAreaWidth(), 0, 0, 0);
}

void CodeEditor::updateLineNumberArea(const QRect &rect, int dy)
{
    if (dy)
        lineNumberArea->scroll(0, dy);
    else
        lineNumberArea->update(0, rect.y(), lineNumberArea->width(), rect.height());

    if (rect.contains(viewport()->rect()))
        updateLineNumberAreaWidth(0);
}

void CodeEditor::resizeEvent(QResizeEvent *e)
{
    QPlainTextEdit::resizeEvent(e);

    QRect cr = contentsRect();
    lineNumberArea->setGeometry(QRect(cr.left(), cr.top(), lineNumberAreaWidth(), cr.height()));
}

void CodeEditor::highlightCurrentLine()
{
    QList<QTextEdit::ExtraSelection> extraSelections;

    if (!isReadOnly()) {
        QTextEdit::ExtraSelection selection;

        QColor lineColor = QColor(Qt::yellow).lighter(160);

        selection.format.setBackground(lineColor);
        selection.format.setProperty(QTextFormat::FullWidthSelection, true);

        selection.cursor = textCursor();
        selection.cursor.clearSelection();
        extraSelections.append(selection);
    }

    setExtraSelections(extraSelections);

    TextBlockData *data = static_cast<TextBlockData *>(textCursor().block().userData());
    QString m_matchBracketsList = "()[]{}<>";
    QTextBlock  block     =  textCursor().block();
    int blockPosition     = block.position();
    int cursorPosition    = textCursor().position();
    int relativePosition  = cursorPosition - blockPosition;
    QChar currentChar     = block.text()[relativePosition];

    if (data) {
        QVector<ParenthesisInfo *> infos = data->parentheses();

        int pos = textCursor().block().position();
        for (int i = 0; i < infos.size(); ++i) {
            ParenthesisInfo *info = infos.at(i);
            if (info->position != relativePosition)
                continue;

            int j = m_matchBracketsList.indexOf(currentChar);
            if (j==-1)
                continue;

            // lets find it's partner
            // in theory, no errors shuold not happen, but one can never be too sure
            if (m_matchBracketsList[j] != m_matchBracketsList[j+1])
                if (j %2 == 0)
                    j = findMatchingChar(m_matchBracketsList[j], m_matchBracketsList[j+1], true , block, cursorPosition );
                else
                    j = findMatchingChar(m_matchBracketsList[j], m_matchBracketsList[j-1], false, block, cursorPosition  );
            else
                j = findMatchingChar( m_matchBracketsList[j],m_matchBracketsList[j+1], true , block, cursorPosition );
            createParenthesisSelection(pos + info->position);

        }
    }
}

void CodeEditor::lineNumberAreaPaintEvent(QPaintEvent *event)
{
    QPainter painter(lineNumberArea);
    painter.fillRect(event->rect(), Qt::lightGray);

    QTextBlock block = firstVisibleBlock();
    int blockNumber = block.blockNumber();
    int top = (int) blockBoundingGeometry(block).translated(contentOffset()).top();
    int bottom = top + (int) blockBoundingRect(block).height();

    while (block.isValid() && top <= event->rect().bottom()) {
        if (block.isVisible() && bottom >= event->rect().top()) {
            QString number = QString::number(blockNumber + 1);
            painter.setPen(Qt::black);
            painter.drawText(0, top, lineNumberArea->width(), fontMetrics().height(),
                             Qt::AlignRight, number);
        }

        block = block.next();
        top = bottom;
        bottom = top + (int) blockBoundingRect(block).height();
        ++blockNumber;
    }
}

void CodeEditor::paintEvent(QPaintEvent *e)
{
    uint position = fontMetrics().width("  ") * 80;
    QPainter p(viewport());
    QPen     pen = p.pen();
    QColor   c = pen.color();
    c.setAlpha(64);
    pen.setColor(c);
    p.setPen(pen);
    p.drawLine(position,0,position,viewport()->height());
    QPlainTextEdit::paintEvent(e);
}


void  CodeEditor::createParenthesisSelection(int pos)
{
    QList<QTextEdit::ExtraSelection> selections = extraSelections();

    QTextEdit::ExtraSelection selection;
    QTextCharFormat format = selection.format;
    format.setBackground(Qt::green);
    selection.format = format;

    QTextCursor cursor = textCursor();
    cursor.setPosition(pos);
    cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor);
    selection.cursor = cursor;

    selections.append(selection);

    setExtraSelections(selections);
}

int CodeEditor::findMatchingChar(QChar c1, QChar c2, bool forward, QTextBlock &block, int from)
{
    int i = 1;
    while (block.isValid())
    {
            TextBlockData *data = static_cast<TextBlockData *>(block.userData());
            QVector<ParenthesisInfo *> parentheses = data->parentheses();
            for( int k=0; (data) && (k<parentheses.size()); k++)
            {
                    int j = forward? k : parentheses.size() - k - 1;
                    ParenthesisInfo *m = parentheses.at(j);
                    int globalPosition = m->position + block.position();
                    if (forward) {
                            if (globalPosition <= from) continue;
                    }	else if (globalPosition >= from) continue;

                    if (m->character == c1){
                            i ++;
                    }
                    if (m->character == c2)
                            i --;
                    // we found the braket
                    if (i==0)
                    {createParenthesisSelection(globalPosition);
                            return globalPosition;
                    }
            }
            if (forward)
                    block = block.next();
            else
                    block = block.previous();
    }
    return -1;
}

void CodeEditor::openFile(const QString file)
{
    QFile f(file);
    if (!f.open(QFile::ReadOnly | QFile::Text))
        return;
    fetch(&f);
}

void CodeEditor::fetch(QFile *file)
{
    QByteArray buf;
    buf = file->readAll();
    file->close();
    int mib = 106; // utf-8
    codec = QTextCodec::codecForUtfText(buf, 0); // try BOM detection
    if (!codec) {
        if (buf.length() > 3) { // auto-detect
            const char *data = buf.constData();
            if (data[0] != 0) {
                if (data[1] != 0)
                    mib = 106; // utf-8
                else if (data[2] != 0)
                    mib = 1014; // utf16 le
                else
                    mib = 1019; // utf32 le
            } else if (data[1] != 0)
                mib = 1013; // utf16 be
            else
                mib = 1018; // utf32 be
        }
        codec = QTextCodec::codecForMib(mib);
    }
    else {
        codec = QTextCodec::codecForLocale();
    }

    setPlainText(codec->toUnicode(buf));
}

bool CodeEditor::saveFile(const QString file)
{
    QFile f (file);
    if ( !f.open(QFile::WriteOnly | QFile::Text))
        return false;
// rewrite
    f.write(codec->toUnicode(
                        document()->toPlainText().toLocal8Bit()
                    ).toLocal8Bit()
                );
    f.close();
    return true;
}

void CodeEditor::setHighlightingRules(QVector<HighlightingRule> highlightingRules)
{
    highlighter->setHighlightingRules(highlightingRules);
    emit(highlighter->rehighlight());
}

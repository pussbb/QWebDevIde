#include <QtGui>

#include "codeeditor.h"
#include <QSettings>

CodeEditor::CodeEditor(QWidget *parent) : QPlainTextEdit(parent)
{
    lineNumberArea = new LineNumberArea(this);

    connect(this, SIGNAL(blockCountChanged(int)),
            this, SLOT(updateLineNumberAreaWidth(int)));
    connect(this, SIGNAL(updateRequest(QRect,int)),
            this, SLOT(updateLineNumberArea(QRect,int)));
    connect(this, SIGNAL(cursorPositionChanged()),
            this, SLOT(highlightCurrentLine()));


    initSettings();
    updateLineNumberAreaWidth(0);
    highlightCurrentLine();

}

CodeEditor::~CodeEditor()
{
    delete lineNumberArea;
}

void CodeEditor::initSettings()
{
    changed = false;
    m_lineAreaStyle.backgroundBrush = QBrush(Qt::lightGray);
    m_lineAreaStyle.textPen = QPen();
    m_lineAreaStyle.lineColor = QColor(220,220,217,55);
    QTextOption option =  document()->defaultTextOption();
    QFont font;
    QSettings settings;
    font.setFamily(settings.value("Editor/fontFamily", "Monospace").toString());
    font.setPointSize(settings.value("Editor/fontSize", 10).toInt());
    setFont(font);
    int tabStop = settings.value("Editor/tabStop", 4).toInt();
    option.setTabStop(fontMetrics().width(" ") * tabStop);

    option.setWrapMode(QTextOption::NoWrap);
    option.setFlags( QTextOption::IncludeTrailingSpaces
                     | QTextOption::AddSpaceForLineAndParagraphSeparators
                     |QTextOption::ShowTabsAndSpaces
                     );
    option.setUseDesignMetrics(true);
    document()->setDefaultTextOption(option);
}

int CodeEditor::lineNumberAreaWidth()
{
    int digits = 1;
    int max = qMax(1, blockCount());
    while (max >= 10) {
        max /= 10;
        ++digits;
    }

    int space = 10 + fontMetrics().width(QLatin1Char('9')) * digits;

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
        selection.format.setBackground(m_lineAreaStyle.lineColor);
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

    painter.fillRect(event->rect(),m_lineAreaStyle.backgroundBrush);

    QTextBlock block = firstVisibleBlock();
    int blockNumber = block.blockNumber();
    int top = (int) blockBoundingGeometry(block).translated(contentOffset()).top();
    int bottom = top + (int) blockBoundingRect(block).height();

    while (block.isValid() && top <= event->rect().bottom()) {
        if (block.isVisible() && bottom >= event->rect().top()) {
            QString number = QString::number(blockNumber + 1);
            painter.setPen(m_lineAreaStyle.textPen);
            painter.drawText(0, top, lineNumberArea->width(), fontMetrics().height(),
                             Qt::AlignRight, number);
        }
        if ( textCursor().block().blockNumber() == blockNumber) {
            QString number = QString::number(blockNumber + 1);
            painter.setPen(Qt::lightGray);
            painter.drawText(0, top - 1, lineNumberArea->width(), fontMetrics().height(),
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
    uint position = fontMetrics().width(" ") * 80;
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
            if (i==0) {
                createParenthesisSelection(globalPosition);
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
    if ( ! f.open(QFile::ReadOnly | QFile::Text))
        return;
    m_file = file;
    fetch(&f);

    /// delete &file;
}

void CodeEditor::fetch(QFile *file)
{
    QByteArray buf;
    //if(!file->isWritable())
    //     setReadOnly(true);
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
    //TODO a hack need to remove
    origin = toPlainText();
    connect(this,SIGNAL(textChanged()),
            this,SLOT(changedText()));
    buf.clear();
    ///delete codec;
}

bool CodeEditor::saveFile()
{
    QFile f (m_file);
    if ( !f.open(QFile::WriteOnly | QFile::Text))
        return false;

    // rewrite
    QTextCursor cursor = textCursor();
    int start =  document()->findBlock( cursor.position()).position();
    QStringList list = document()->toPlainText().split('\n');
    for (int i = 0; i < list.count(); ++i)
        list[i] = list[i].remove(QRegExp("\\s*$"));
    document()->setPlainText(list.join("\n"));

    cursor.setPosition( start, QTextCursor::MoveAnchor);
    setTextCursor( cursor);

    f.write(codec->toUnicode(
                document()->toPlainText().toLocal8Bit()
                ).toLocal8Bit()
            );
    f.close();
    f.deleteLater();
    changed = false;
    return true;
}

void CodeEditor::setLineAreaPalette(LineAreaStyle lineAreaStyle)
{
    m_lineAreaStyle = lineAreaStyle;
    emit(cursorPositionChanged());
}

void CodeEditor::keyPressEvent(QKeyEvent *e)
{
    emit(keyPressed(e));

    QTextCursor cursor = textCursor();
    int start = cursor.selectionStart();
    int end = cursor.selectionEnd();

    if ( e->key() == Qt::Key_Tab
         && e->modifiers() != Qt::ControlModifier) {
        if ( ! textCursor().hasSelection()) {
            textCursor().insertText(QString(" ").repeated(4));
            return;
        }

        QStringList list = cursor.selection().toPlainText().split('\n');
        for (int i=0; i < list.count(); ++i)
            list[i] = QString(" ").repeated(4) + list[i];

        QTextBlock b1 = document()->findBlock(start);
        QTextBlock b2 = document()->findBlock(end);
        cursor.insertText(list.join("\n"));
        cursor.setPosition(b1.position(), QTextCursor::KeepAnchor);
        cursor.setPosition(b2.position(), QTextCursor::KeepAnchor);
        setTextCursor(cursor);
        return;
    }

    if ( e->key() == Qt::Key_Tab
         && e->modifiers() == Qt::ControlModifier) {
        QString text;

        cursor.beginEditBlock();
        if ( ! textCursor().hasSelection()) {
            cursor.select(QTextCursor::LineUnderCursor);
            text = cursor.selection().toPlainText().remove(QRegExp("^\\s{1,4}"));
            int anchor = cursor.anchor();
            cursor.insertText(text);
            cursor.setPosition(anchor);
        }
        else {
            QStringList list = cursor.selection().toPlainText().split('\n');
            for (int i=0; i < list.count(); ++i)
                list[i] = list[i].remove(QRegExp("^\\s{1,4}"));
            text = list.join("\n");
            QTextBlock b1 = document()->findBlock(start);
            QTextBlock b2 = document()->findBlock(end);
            cursor.insertText(text);
            cursor.setPosition(b1.position(), QTextCursor::KeepAnchor);
            cursor.setPosition(b2.position(), QTextCursor::KeepAnchor);
        }
        cursor.endEditBlock();
        setTextCursor(cursor);
        return;
    }
    /// to upper case
    if ( e->key() == Qt::Key_U
         && e->modifiers() == Qt::ControlModifier
         && textCursor().hasSelection()) {

        cursor.beginEditBlock();
        cursor.insertText(cursor.selectedText().toUpper());
        cursor.setPosition(start);
        cursor.setPosition(end, QTextCursor::KeepAnchor);
        cursor.endEditBlock();
        setTextCursor(cursor);

    }
    ///to lower case
    if ( e->key() == Qt::Key_U
         && int(e->modifiers()) == (Qt::ControlModifier + Qt::ShiftModifier)
         && textCursor().hasSelection()) {
        cursor.beginEditBlock();
        cursor.insertText(cursor.selectedText().toLower());
        cursor.setPosition(start);
        cursor.setPosition(end, QTextCursor::KeepAnchor);
        cursor.endEditBlock();
        setTextCursor(cursor);
    }
    QPlainTextEdit::keyPressEvent(e);
}

void CodeEditor::changedText()
{
    //TODO origin is a hack need to remove
    if ( changed || origin.compare(toPlainText()) == 0)
        return;

    changed = true;
    emit(contentChanged());
}


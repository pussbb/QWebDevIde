#ifndef CODEEDITOR_H
#define CODEEDITOR_H

#include <QPlainTextEdit>
#include <QObject>

#include <QFile>
#include <QTextCharFormat>
#include <QTextBlock>
#include <textblockdata.h>
#include <global.h>

QT_BEGIN_NAMESPACE
class QPaintEvent;
class QResizeEvent;
class QSize;
class QWidget;
QT_END_NAMESPACE

class LineNumberArea;

class CodeEditor : public QPlainTextEdit
{
    Q_OBJECT

public:
    CodeEditor(QWidget *parent = 0);
    void lineNumberAreaPaintEvent(QPaintEvent *event);
    int lineNumberAreaWidth();
    void openFile(const QString file);
    bool saveFile();
    bool changed;
 ///   void setPalette(const QPalette &palette);
    inline QString file(){return m_file;}
    void setLineAreaPalette(LineAreaStyle lineAreaStyle);

protected:
    void resizeEvent(QResizeEvent *event);
    int findMatchingChar( QChar c1, QChar c2, bool forward, QTextBlock &block, int from );
    void keyPressEvent ( QKeyEvent * e );

signals:
    void keyPressed(QKeyEvent *);
    void contentChanged();
private slots:
    void updateLineNumberAreaWidth(int newBlockCount);
    void highlightCurrentLine();
    void updateLineNumberArea(const QRect &, int);
    void paintEvent(QPaintEvent *e);
    void changedText();

private:
    QString m_file;
    void createParenthesisSelection(int pos);
    void matchParentheses();
    void fetch(QFile *file);
    QTextCodec *codec;
    QWidget *lineNumberArea;
    LineAreaStyle m_lineAreaStyle;
    void initSettings();
};

class LineNumberArea : public QWidget
{
public:
    LineNumberArea(CodeEditor *editor) : QWidget(editor) {
        codeEditor = editor;
    }

    QSize sizeHint() const {
        return QSize(codeEditor->lineNumberAreaWidth(), 0);
    }

protected:
    void paintEvent(QPaintEvent *event) {
        codeEditor->lineNumberAreaPaintEvent(event);
    }

private:
    CodeEditor *codeEditor;
};

#endif

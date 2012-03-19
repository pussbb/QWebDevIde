#include "syntaxhighlighter.h"

#include <codeeditorplugin.h>
#include "../colorscheme/colorscheme.h"

SyntaxHighlighter::SyntaxHighlighter()
{
    highlightManager = new HighlightManager();
}

QStringList SyntaxHighlighter::dependencies() const
{
    return QStringList() << "CodeEditor"
                         << "ColorScheme";
}

void SyntaxHighlighter::init(QMap<QString, QObject *> dependencies, QObject *parent)
{
    Q_UNUSED(parent);
    CodeEditorPlugin *editorPlugin = static_cast<CodeEditorPlugin *> (dependencies.value("CodeEditor"));
    ColorScheme *colorScheme = static_cast<ColorScheme *> (dependencies.value("ColorScheme"));
    highlightManager->setColorScheme(colorScheme->currentColorScheme());
    highlightManager->initSyntaxes();

    connect(editorPlugin,SIGNAL(editorCreated(CodeEditor*,QString)),
            this,SLOT(setEditorHighlighter(CodeEditor*,QString)));
    connect(editorPlugin,SIGNAL(aboutToClose(QString)),
            this,SLOT(editorAboutToClose(QString)));

}

void SyntaxHighlighter::setEditorHighlighter(CodeEditor *editor, const QString &fileId)
{
    Highlighter *highlighter = new Highlighter(editor->document());
    QFileInfo fi(editor->file());

    highlighter->highlightingRules = highlightManager->getHighlighting(fi.suffix());
    highlighter->commentEndExpression = highlightManager->getEndMultiComments(fi.suffix());
    highlighter->commentStartExpression = highlightManager->getStartMultiComments(fi.suffix());
    highlighter->multiLineCommentFormat = highlightManager->getMultiCommentsFormart();
    highlighter->sectionHighlightingRules = highlightManager->getSectionHighlighting(fi.suffix());
    highlighters.insert(fileId, highlighter);
}

void SyntaxHighlighter::editorAboutToClose(const QString &fileId)
{qDebug()<< "close";
    if ( ! highlighters.contains(fileId))
        return;
    qDebug()<<fileId;
    qDebug()<< "delete highlighter";
    qDebug()<<highlighters.value(fileId);
    highlighters.value(fileId)->deleteLater();
    highlighters.remove(fileId);

}

Q_EXPORT_PLUGIN2(SyntaxHighlighter, SyntaxHighlighter);













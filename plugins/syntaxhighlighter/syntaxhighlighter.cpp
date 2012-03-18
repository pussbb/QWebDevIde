#include "syntaxhighlighter.h"
#include <json.h>
#include <highlighter.h>
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

    connect(editorPlugin,SIGNAL(editorCreated(CodeEditor*)),
            this,SLOT(setEditorColorScheme(CodeEditor*)));

}
void SyntaxHighlighter::setEditorColorScheme(CodeEditor *editor)
{
    Highlighter *highlighter = new Highlighter(editor->document());
    QFileInfo fi(editor->file());
    highlighter->highlightingRules = highlightManager->getHighlighting(fi.completeSuffix());
    highlighter->commentEndExpression = highlightManager->getEndMultiComments(fi.completeSuffix());
    highlighter->commentStartExpression = highlightManager->getStartMultiComments(fi.completeSuffix());
    highlighter->multiLineCommentFormat = highlightManager->getMultiCommentsFormart();
    highlighter->sectionHighlightingRules = highlightManager->getSectionHighlighting(fi.completeSuffix());
    emit(highlighter->rehighlight());
}

Q_EXPORT_PLUGIN2(SyntaxHighlighter, SyntaxHighlighter);









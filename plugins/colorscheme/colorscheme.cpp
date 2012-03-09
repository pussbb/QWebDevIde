#include "colorscheme.h"
#include "QDebug"
#include <QDir>
#include <json.h>
#include <codeeditorplugin.h>

ColorScheme::ColorScheme()
{
    appPath =  QDir::toNativeSeparators ( QCoreApplication::applicationDirPath()+QDir::toNativeSeparators("/"));
    schemesPath = appPath + QDir::toNativeSeparators("schemes/syntax/");
    initScheme();
}

void ColorScheme::initScheme(const QString & fileName)
{
    QFile f(schemesPath + fileName + ".json");

    if( ! f.open(QIODevice::ReadOnly))
        return;

    QTextStream stream(&f);
    stream.setCodec("UTF-8");
    JsonReader reader;
    reader.parse(stream.readAll());

    if( !reader.errorString().isEmpty())
        return;
    QVariant v = reader.result();
    QVariantMap scheme = v.toMap();
    foreach(const QString &index,scheme.keys()){
        QVariantMap item = scheme.value(index).toMap();
        if(item.isEmpty())
            continue;

        QTextCharFormat charFormat;
        bool bold = item.value("bold",false).toBool();
        if( bold)
            charFormat.setFontWeight(QFont::Bold);
        bool italic = item.value("italic",false).toBool();
        if( italic)
            charFormat.setFontItalic(true);
        bool underLine = item.value("underline",false).toBool();
        if( underLine)
            charFormat.setFontUnderline(true);
        QVariant color = item.value("color","#FFF");
        if( color.canConvert(QVariant::Map)){
            QVariantMap rgb = color.toMap();
            int r = rgb.value("r",0).toInt();
            int b = rgb.value("b",0).toInt();
            int g = rgb.value("g",0).toInt();
            int a = rgb.value("a",255).toInt();
            charFormat.setForeground(QColor(r,g,b,a));
        }
        else{
            charFormat.setForeground(QColor(color.toString()));
        }
        m_colorScheme.insert(index,charFormat);
    }
}
QStringList ColorScheme::dependencies() const
{
    return QStringList() << "CodeEditor";
}

void ColorScheme::init(QMap<QString, QObject *> dependencies, QObject *parent)
{
    Q_UNUSED(parent);
    CodeEditorPlugin *editorPlugin = static_cast<CodeEditorPlugin *> (dependencies.value("CodeEditor"));
    connect(editorPlugin,SIGNAL(editorCreated(CodeEditor*)),
            this,SLOT(setEditorColorScheme(CodeEditor*)));
}

QColor ColorScheme::getEditorBackround()
{
    if( m_colorScheme.contains("editor_background"))
        return m_colorScheme.value("editor_background").foreground().color();
    return QColor(240,240,130);
}

void ColorScheme::setEditorColorScheme(CodeEditor *editor)
{
    editor->setBackgroundColor(getEditorBackround());
}

Q_EXPORT_PLUGIN2(ColorScheme, ColorScheme);











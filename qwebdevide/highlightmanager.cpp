#include "highlightmanager.h"

HighlightManager::HighlightManager(QObject *parent) :
    QObject(parent)
{
    QString appDir =  QDir::toNativeSeparators ( QCoreApplication::applicationDirPath()+QDir::toNativeSeparators("/"));
    schemePath = appDir + QDir::toNativeSeparators("schemes/syntax/");
    syntaxesPath = appDir + QDir::toNativeSeparators("syntax/");
    initScheme();
}

void HighlightManager::initScheme()
{
    QFile f(schemePath + "default.json");
    if(!f.open(QIODevice::ReadOnly))
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
        if(bold)
            charFormat.setFontWeight(QFont::Bold);
        bool italic = item.value("italic",false).toBool();
        if(italic)
            charFormat.setFontItalic(true);
        bool underLine = item.value("underline",false).toBool();
        if(underLine)
            charFormat.setFontUnderline(true);
        QVariant color = item.value("color","#FFF");
        if(color.canConvert(QVariant::Map)){
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

void HighlightManager::initSyntaxes()
{
    QDir dir(syntaxesPath);
    QStringList filters;
    filters << "*.json";
    dir.setNameFilters(filters);
    QFileInfoList files = dir.entryInfoList();
    foreach(const QFileInfo &file,files){
        if(!file.isReadable())
            continue;
        QString fileName = file.baseName();
        AbstractSyntaxHighlight *syntax = new AbstractSyntaxHighlight(this);
        syntax->setColorScheme(m_colorScheme);
        bool ok = syntax->initSyntax(file.absoluteFilePath());
        if ( ok)
            syntaxes.insert(fileName,syntax);
    }
    foreach(const QString &file,syntaxes.keys()){
        AbstractSyntaxHighlight *syntax = syntaxes.value(file);
        if ( syntax == NULL)
            continue;
        syntax->dependenciesWalk(syntaxes);
    }
}

#include "mimedata.h"


MimeData::MimeData()
{
    QFile file(":/freedesktop/freedesktop.js");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream jsStream(&file);
    m_engine.evaluate(jsStream.readAll());
}

QString MimeData::getMimeType(QString fileName)
{
    const QString cmd = QString("getMIMEtype(\"%1\")").arg(fileName);
    const QScriptValue res = m_engine.evaluate(cmd);
    if(res.isString())
        return res.toString();
    return "unknown";
}

QString MimeData::getIconMimeType(QString fileName)
{
    QString file = getMimeType(fileName);
    file = file.replace("/","-");
    QFileInfo fi(":/freedesktop/mimetypes/"+file+".png");
    if(!fi.exists())
        return ":/freedesktop/mimetypes/unknown.png";
    return fi.absoluteFilePath();
}

#ifndef MIMEDATA_H
#define MIMEDATA_H

#include "MimeData_global.h"
#include <QtCore>
#include <QtScript>
#include <QFile>
class MIMEDATASHARED_EXPORT MimeData {
public:
    MimeData();
    QString getMimeType(const QString &fileName);
    QString getIconMimeType(const QString &fileName);
    QString getIconMimeType(const QFileInfo &fi);
private:
    QScriptEngine m_engine;
    static QHash<QString, QString> hash;
};

#endif // MIMEDATA_H

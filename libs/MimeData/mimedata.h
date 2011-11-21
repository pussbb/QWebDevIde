#ifndef MIMEDATA_H
#define MIMEDATA_H

#include "MimeData_global.h"
#include <QtCore>
#include <QtScript>
#include <QFile>
class MIMEDATASHARED_EXPORT MimeData {
public:
    MimeData();
    QString getMimeType(QString fileName);
    QString getIconMimeType(QString fileName);
private:
    QScriptEngine m_engine;
};

#endif // MIMEDATA_H

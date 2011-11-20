#ifndef MIMETYPES_H
#define MIMETYPES_H

#include <QObject>
#include <QMap>
class MimeTypes : public QObject
{
    Q_OBJECT
public:
    explicit MimeTypes(QObject *parent = 0);
    QString iconForFileExt(QString fileExt);
signals:

public slots:
private:
    QMap<QString,QString> mimetypes_;
};

#endif // MIMETYPES_H

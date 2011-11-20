#ifndef PAGEDATA_H
#define PAGEDATA_H

#include <QObject>
#include <QMap>
#include <QString>
#include <QVariant>
class PageData : public QObject
{
    Q_OBJECT
public:
    PageData() { }
    ~PageData() { }
    QMap<QString, QVariant> itemMap;
};
#endif // PAGEDATA_H

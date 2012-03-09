#ifndef BOOKMARKMANAGER_H
#define BOOKMARKMANAGER_H

#include <QObject>

class BookmarkManager : public QObject
{
    Q_OBJECT
public:
    explicit BookmarkManager(QObject *parent = 0);
    inline QString test(){return "test";}

signals:

public slots:

};

#endif // BOOKMARKMANAGER_H

#ifndef FILETEMPLATES_H
#define FILETEMPLATES_H

#include <QObject>
#include <QMenu>
#include "qtjsonsettings.h"

class FileTemplates : public QObject
{
    Q_OBJECT
public:
    explicit FileTemplates(QObject *parent = 0);

signals:

public slots:
private:
    QMenu *m_menu;
};

#endif // FILETEMPLATES_H

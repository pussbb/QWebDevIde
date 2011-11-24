#ifndef FILETEMPLATES_H
#define FILETEMPLATES_H

#include <QObject>
#include <QMenu>
#include "json.h"
#include <QtCore>
#include <QDir>

class FileTemplates : public QObject
{
    Q_OBJECT
public:
    explicit FileTemplates(QObject *parent = 0);
    QMenu* getTemplatesMenu();
signals:

public slots:
    void create();
private:
    QMenu m_menu;
    void buildMenu(QVariant v);
};

#endif // FILETEMPLATES_H

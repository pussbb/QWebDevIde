#ifndef FILETEMPLATES_H
#define FILETEMPLATES_H

#include <QObject>
#include <QMenu>
#include "json.h"
#include <QtCore>
#include <QDir>
#include <QFileInfo>
#include <QMessageBox>
#include <QInputDialog>

class FileTemplates : public QObject
{
    Q_OBJECT
public:
    explicit FileTemplates(QObject *parent = 0);
    QMenu* getTemplatesMenu();
    QString folder;
signals:

public slots:
    void create();
private:
    QMenu m_menu;
    void buildMenu(QVariant v);
    QString templateDir;
};

#endif // FILETEMPLATES_H

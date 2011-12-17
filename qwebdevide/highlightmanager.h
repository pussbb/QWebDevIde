#ifndef HIGHLIGHTMANAGER_H
#define HIGHLIGHTMANAGER_H

#include <QObject>
#include "abstractsyntaxhighlight.h"
#include <QMap>
#include "json.h"
#include <QTextCharFormat>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QtCore>

class HighlightManager : public QObject
{
    Q_OBJECT
public:
    explicit HighlightManager(QObject *parent = 0);
    QMap<QString , AbstractSyntaxHighlight*> syntaxes;
signals:

public slots:

private:
    void initScheme();
    void initSyntaxes();
    QString schemePath;
    QString syntaxesPath;
    QMap<QString,QTextCharFormat> m_colorScheme;
};

#endif // HIGHLIGHTMANAGER_H

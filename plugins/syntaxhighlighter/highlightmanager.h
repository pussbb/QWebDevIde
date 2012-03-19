#ifndef HIGHLIGHTMANAGER_H
#define HIGHLIGHTMANAGER_H

#include <QObject>
#include "abstractsyntaxhighlight.h"
#include <QMap>
#include <json.h>
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

    QVector<HighlightingRule> getHighlighting(QString syntax = "");
    QVector<sectionHighlightingRule> getSectionHighlighting(QString syntax = "");
    QRegExp getStartMultiComments(QString syntax = "");
    QRegExp getEndMultiComments(QString syntax = "");
    QTextCharFormat getMultiCommentsFormart();
    inline void setColorScheme(QMap<QString,QTextCharFormat> scheme){ m_colorScheme = scheme;}
    void initSyntaxes();

signals:

public slots:

private:
    QString syntaxesPath;
    QMap<QString,QTextCharFormat> m_colorScheme;
    QMap<QString , AbstractSyntaxHighlight*> syntaxes;
};

#endif // HIGHLIGHTMANAGER_H

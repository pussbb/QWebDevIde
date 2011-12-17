#include "abstractsyntaxhighlight.h"

AbstractSyntaxHighlight::AbstractSyntaxHighlight(QObject *parent) :
    QObject(parent)
{
}

bool AbstractSyntaxHighlight::initSyntax(const QString &fileName,
                                         QMap<QString, AbstractSyntaxHighlight*> existing)
{
return true;
}

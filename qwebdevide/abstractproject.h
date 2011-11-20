#ifndef ABSTRACTPROJECT_H
#define ABSTRACTPROJECT_H

#include <QObject>
#include <QSettings>

class AbstractProject : public QObject
{
    Q_OBJECT
public:
    explicit AbstractProject(QObject *parent = 0);
    QString fileName;
    QString projectName;
    void init();
    QVariant getProperty(QString property);
    QString projectPath();
signals:

public slots:

private:
    QSettings m_projectSettings;
};

#endif // ABSTRACTPROJECT_H

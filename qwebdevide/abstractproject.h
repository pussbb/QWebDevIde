#ifndef ABSTRACTPROJECT_H
#define ABSTRACTPROJECT_H

#include <QObject>
#include <QSettings>

class AbstractProject : public QObject
{
    Q_OBJECT
public:
    explicit AbstractProject(QObject *parent = 0);
    void setProjectFile(QString file);
    QVariant getProperty(QString property);
    inline QString projectPath(){return m_projectPath;}
    inline QString projectName(){return m_projectName;}
signals:

public slots:

private:
    QSettings *m_projectSettings;
    QString m_projectName;
    QString m_projectPath;
};

#endif // ABSTRACTPROJECT_H

#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H

#include <QtCore>
#include <QtGui>
#include <QObject>
#include <ifaces.h>
#include <iplugin.h>
#include <projects.h>
#include <abstractproject.h>
#include <projectexplorer/projectexplorer.h>

class ProjectManager : public QObject, IPlugin, IEditors ,IRightPane
{
    Q_OBJECT
    Q_INTERFACES(IPlugin)
    Q_INTERFACES(IEditors)
    Q_INTERFACES(IRightPane)

public:
    explicit ProjectManager();
    QStringList dependencies() const;
    void init(QMap<QString, QObject *> dependencies, QObject *parent);
    /// edor interface
    QWidget * open(const QString &file);
    bool save(const QString &fileName);
    void close(const QString &fileName);
    QStringList mimeTypes();

    /// RightPane interface
    QWidget * getWidget();
    inline QString widgetTitle() { return tr("Projects");}
    Projects *projects;

signals:
    void projectAdd();

private:
    QPointer<ProjectExplorer> projectExplorer;
    QObject *m_parent;

};

#endif // COREPLUGIN_H

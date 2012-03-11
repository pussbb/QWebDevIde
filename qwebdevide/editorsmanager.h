#ifndef EDITORMANAGER_H
#define EDITORMANAGER_H

#include <QObject>
#include <QDebug>
#include <QFileInfo>
#include <editingwidget.h>
#include <mimedata.h>
#include "QMap"

class EditorsManager : public QObject
{
    Q_OBJECT

public:
    explicit EditorsManager(QObject *parent = 0);
    inline QWidget * getMainEditorWidget(){return m_editingWidget;}
    QMap<QString, EditedFile> openedFiles;
    void saveCurrent();
    void saveAll();
    void initPlugins(QMap<QString, QObject *> list);

signals:

public slots:
    void openFile(QString );
    void closeFile(QString );

private :
    MimeData mime;
    QMap<QString, IEditors *> editors;
    EditingWidget *m_editingWidget;
    bool isOpened(const QString &fileId, const QFileInfo &fi);
};

#endif // EDITORMANAGER_H

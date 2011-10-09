#ifndef QCOREWINDOW_H
#define QCOREWINDOW_H

//-------------------
#include <QDebug>
//-------------------

#include <QMainWindow>
#include <QDir>
#include <QApplication>
#include <QMenu>
#include <QMenuBar>
#include <QLocale>
#include <QTranslator>
#include <QSettings>
#include <QLibraryInfo>
#define appDir QDir::toNativeSeparators ( QApplication::applicationDirPath()+QDir::toNativeSeparators("/"))
#define langDir QDir::toNativeSeparators ( QApplication::applicationDirPath()+QDir::toNativeSeparators("/lang/"))

class QCoreWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit QCoreWindow(QWidget *parent = 0);
    void buildLangMenu(QString appname = "*",QDir *dir = new QDir(langDir),QString icon = "");
    void langMenuToMenuBar(QString objectName);
    void restoreWindowState();
    void attachTranslation(QString fileName);
    QMenu *languageMenu;
    QString locale;
    QSettings settings;
signals:

private:
    QString app_lang_prefix;
    QString lang_files_path;
    QTranslator translator;
    QTranslator qtTranslator;
    QString syslocale;
    QCoreWindow *d;
    QMap<QString , QTranslator*> translationList;
private slots:
    void setLocale();
protected:
    void closeEvent(QCloseEvent *event);
public slots:
    void switchLanguage(QAction *action);


};

#endif // QCOREWINDOW_H

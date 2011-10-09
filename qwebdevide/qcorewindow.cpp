#include "qcorewindow.h"


QCoreWindow::QCoreWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setLocale();
    if(settings.value("Core/saveWindowLayout",false).toBool()) {
       restoreGeometry(settings.value("Core/window_geometry").toByteArray());
    }
}
void QCoreWindow::restoreWindowState()
{
    if(settings.value("Core/saveWindowLayout",false).toBool()) {
       restoreState(settings.value("Core/windowState").toByteArray());
    }
}

void QCoreWindow::buildLangMenu(QString appname,QDir *dir,QString icon)
{
    lang_files_path = dir->absolutePath()+QDir::toNativeSeparators("/");
    app_lang_prefix = appname;
    languageMenu = new QMenu(tr("langmenu"),this);
    if(!icon.isEmpty())
        languageMenu->setIcon(QIcon(icon));

    QActionGroup *languageActionGroup = new QActionGroup(this);
    connect(languageActionGroup, SIGNAL(triggered(QAction *)),
            this, SLOT(switchLanguage(QAction *)));

    QStringList fileNames =
            dir->entryList(QStringList(appname+"*.qm"));

    for (int i = 0; i < fileNames.size(); ++i) {
        QString file_locale = fileNames[i];
        file_locale.remove(0, file_locale.indexOf('_') + 1);
        file_locale.truncate(file_locale.lastIndexOf('.'));

        QTranslator translator1;
        translator1.load(lang_files_path+fileNames[i]);
        QString language = translator1.translate("Language","English");
        QAction *action = new QAction(tr("&%2").arg(language), this);
        action->setCheckable(true);
        action->setData(file_locale);
        action->setIcon(QIcon(":/core/flags/"+file_locale+".png"));
        languageMenu->addAction(action);
        languageActionGroup->addAction(action);
        if(file_locale == locale)
            action->setChecked(true);
    }
    translator.load(lang_files_path+appname+"_"+locale);

    qtTranslator.load("qt_" + locale,
                 QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    QApplication::installTranslator(&qtTranslator);
    QApplication::installTranslator(&translator);
    languageMenu->setTitle(tr("langmenu"));
}

void QCoreWindow::switchLanguage(QAction *action)
{
    locale = action->data().toString();

    if(settings.value("Core/save_locale","false").toBool())
        settings.setValue("locale",locale);
    qtTranslator.load("qt_" + locale,
                 QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    translator.load(app_lang_prefix + "_" +locale, lang_files_path);
    foreach(QString fileName, translationList.keys()) {
        translationList.value(fileName)->load(fileName+app_lang_prefix + "_" +locale,lang_files_path);
    }

    languageMenu->setTitle(tr("langmenu"));
}

void QCoreWindow::langMenuToMenuBar(QString objectName)
{
    QMenuBar* bar=this->menuBar();
    QList<QAction *> actions = bar->actions();
    QList<QAction *>::const_iterator it = actions.begin();
    for(; it != actions.end(); it++) {
        QAction *action = *it;
        if(action->menu()->objectName() == objectName) {
            if(languageMenu->actions().count() >0)
                action->menu()->addMenu(languageMenu);
        }
    }
}
void QCoreWindow::attachTranslation(QString fileName)
{
    translationList.insert(fileName,new QTranslator());
    translationList.value(fileName)->load(fileName+app_lang_prefix + "_" +locale,lang_files_path);
    QApplication::installTranslator(translationList.value(fileName));
}

void QCoreWindow::setLocale()
{
    syslocale = QLocale::system().name();
    if(syslocale.length()>2)
        syslocale.resize(2);

    if(settings.value("Core/locale","none") == "none")
        locale = syslocale;
    else
        locale = settings.value("Core/locale","none").toString();
}

void QCoreWindow::closeEvent(QCloseEvent *event)
 {
    if(settings.value("Core/saveWindowLayout",false).toBool()) {
        settings.setValue("Core/window_geometry", saveGeometry());
        settings.setValue("Core/windowState", saveState());
    }
    QMainWindow::closeEvent(event);
 }

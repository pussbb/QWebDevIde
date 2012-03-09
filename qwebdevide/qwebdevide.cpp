#include "qwebdevide.h"
#include "ui_qwebdevide.h"

#include <wizard/wizard.h>
#include "pluginmanager.h"

QWebDevIde::QWebDevIde(QWidget *parent) :
    QCoreWindow(parent),
    ui(new Ui::QWebDevIde)
{
    ui->setupUi(this);

    buildLangMenu("qwebdevide");
    langMenuToMenuBar("menuOptions");
    projectManager = new ProjectManager(this);
    bookmarkManager = new BookmarkManager(this);
    editorsManager = new EditorsManager(this);
        PluginManager *pm = new PluginManager(this, locale);
        editorsManager->initPlugins(pm->loadedPlugins());
    QString baseName = QApplication::style()->objectName();
    #ifdef Q_WS_X11
        if (baseName == QLatin1String("windows")) {
            // Sometimes we get the standard windows 95 style as a fallback
            // e.g. if we are running on a KDE4 desktop
            QByteArray desktopEnvironment = qgetenv("DESKTOP_SESSION");
            if (desktopEnvironment == "kde")
                baseName = QLatin1String("plastique");
            else
                baseName = QLatin1String("cleanlooks");
        }
    #endif
    qApp->setStyle(new ManhattanStyle(baseName));
    ptab = new FancyTabWidget(this);
    setCentralWidget(ptab);


    rightPaneSplitter = new MiniSplitter(parent);
    MiniSplitter *splitter = new MiniSplitter(parent);

    splitter->addWidget(rightPaneSplitter);
    splitter->addWidget(editorsManager->getMainEditorWidget());
    rightPane = new RightPane(rightPaneSplitter,projectManager,editorsManager,bookmarkManager);
    rightPaneSplitter->setOrientation(Qt::Vertical);

    ptab->insertTab(0,new QWidget(this),QIcon(":/core/images/category_core.png"),tr("Welcome") );
    ptab->setTabEnabled(0, true);
    ptab->insertTab(1,splitter,QIcon(":/core/images/category_texteditor.png"),tr("Editor") );
    ptab->setTabEnabled(1, true);
    ptab->insertTab(2,new QWidget(this),QIcon(":/core/images/category_project.png"),tr("Project") );
    ptab->setTabEnabled(2, true);
    ptab->insertTab(3,new QWidget(this),QIcon(":/core/images/category_help.png"),tr("Help") );
    ptab->setTabEnabled(3, true);
    ptab->setCurrentIndex(0);
    restoreWindowState();

}

void QWebDevIde::initUI()
{

}

QWebDevIde::~QWebDevIde()
{
    delete ui;
}

void QWebDevIde::changeEvent(QEvent *e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
    {
        ui->retranslateUi(this);
        break;
    }
    default:
        break;
    }
}


void QWebDevIde::on_actionNewProject_triggered()
{
    Wizard *wizard = new Wizard(this);
    if(wizard->exec() == QDialog::Accepted){
        openFile(wizard->fileName);
    }
}

void QWebDevIde::openFile(QString fileName)
{
    QFileInfo file(fileName);qDebug()<<file.completeSuffix();
    if(file.completeSuffix() == "webpro"){
        projectManager->openProject(fileName);
        ptab->setCurrentIndex(1);
        qDebug()<<  projectManager->current->projectPath();
    }
    else
        editorsManager->openFile(fileName);
}

void QWebDevIde::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open file or project"),
                                                    QDir::currentPath(),
                                                    tr("All Files (*.*)"));
    if(!fileName.isEmpty())
        openFile(fileName);
}

void QWebDevIde::on_actionFull_screen_triggered()
{
    if(!isFullScreen())
        showFullScreen();
    else
        showNormal();
}

void QWebDevIde::on_actionShow_Hide_Editor_Right_pane_triggered()
{
    if(rightPane->isVisible())
        rightPane->hide();
    else
        rightPane->show();

}

void QWebDevIde::on_actionSave_file_triggered()
{
    editorsManager->saveCurrent();
}

void QWebDevIde::on_actionSave_all_triggered()
{
    foreach(const QString &file,editorsManager->openedFiles.keys()) {
//        AbstractEditor *editor = editorsManager->openedFiles.value(file);
//        if ( editor != NULL)
//            editor->saveFile();
    }
}

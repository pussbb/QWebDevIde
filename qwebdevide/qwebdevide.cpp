#include "qwebdevide.h"
#include "ui_qwebdevide.h"

QWebDevIde::QWebDevIde(QWidget *parent) :
    QCoreWindow(parent),
    ui(new Ui::QWebDevIde)
{
    ui->setupUi(this);

    buildLangMenu("qwebdevide");
    langMenuToMenuBar("menuOptions");

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
    FancyTabWidget* ptab = new FancyTabWidget(this);
    setCentralWidget(ptab);


    rightPaneSplitter = new MiniSplitter(parent);
      MiniSplitter *splitter = new MiniSplitter(parent);
      QListView *listview = new QListView;
      QTreeView *treeview = new QTreeView;
      QTextEdit *textedit = new QTextEdit;
      splitter->addWidget(rightPaneSplitter);
      splitter->addWidget(textedit);
      new RightPane(rightPaneSplitter);
      new RightPane(rightPaneSplitter);
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


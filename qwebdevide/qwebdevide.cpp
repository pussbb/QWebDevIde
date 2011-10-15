#include "qwebdevide.h"
#include "ui_qwebdevide.h"
#include <fancytabwidget.h>
#include <manhattanstyle.h>
///#include <minisplitter.h>
using namespace Core;
using namespace Core::Internal;
QWebDevIde::QWebDevIde(QWidget *parent) :
    QCoreWindow(parent),
    ui(new Ui::QWebDevIde)
{
    ui->setupUi(this);
    QSettings::setDefaultFormat(QSettings::IniFormat);
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
    ptab->insertTab(0, new QWidget(this),QIcon(":/core/images/category_cpp.png"),"Very~" );
    ptab->setTabEnabled(0, true);
        ptab->setProperty("p_styled", true);
//ptab->p

}

QWebDevIde::~QWebDevIde()
{
    delete ui;
}

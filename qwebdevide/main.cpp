#include <QtGui/QApplication>
#include "qwebdevide.h"

#include <fstream>
using namespace std;
ofstream logFile;

void SimpleLoggingHandler(QtMsgType type, const char *msg) {
    switch (type) {
    case QtDebugMsg:
        logFile << QTime::currentTime().toString().toAscii().data() << " Debug: " << msg << "\n";
        break;
    case QtCriticalMsg:
        logFile << QTime::currentTime().toString().toAscii().data() << " Critical: " << msg << "\n";
        break;
    case QtWarningMsg:
        logFile << QTime::currentTime().toString().toAscii().data() << " Warning: " << msg << "\n";
        break;
    case QtFatalMsg:
        logFile << QTime::currentTime().toString().toAscii().data() <<  " Fatal: " << msg << "\n";
        abort();
    }

#ifdef QT_DEBUG
    fprintf(stderr, "%s\n", qPrintable(msg));
    fflush(stderr);
#endif
    logFile.flush();
}
void init_logger(QApplication &a)
{
    QString logFileName = a.applicationDirPath()
            + QDir::toNativeSeparators("/logs/")
            + QDate::currentDate().toString("dd_MM_yyyy")
            +".log";

    logFile.open(logFileName.toLocal8Bit(), ios::app);
    qInstallMsgHandler(SimpleLoggingHandler);

    logFile << qPrintable(QString('-').repeated(40) + "\n ")
            << qPrintable("Application started\n")
            << qPrintable("Built with Qt " ) << ' '
            << qPrintable(QT_VERSION_STR) << ' '
            << qPrintable("running on ")
            << qPrintable( qVersion()) << "\n"
            << qPrintable("Application session id: " + a.sessionId()) << "\n"
            << qPrintable("Arguments : " + a.arguments().join(" , ")) << "\n"
            << qPrintable(QString('-').repeated(40) + "\n ");

}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    init_logger(a);
    QWebDevIde w;
    w.show();
    return a.exec();
}

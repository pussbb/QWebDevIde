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
    logFile.flush();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString logFileName = a.applicationDirPath()
            + QDir::toNativeSeparators("/log/")
            + QDate::currentDate().toString()
            +".log";

    logFile.open(logFileName.toLocal8Bit(), ios::app);
    qInstallMsgHandler(SimpleLoggingHandler);

    QWebDevIde w;
    w.show();
    return a.exec();
}

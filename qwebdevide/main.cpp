#include <QtGui/QApplication>
#include "qwebdevide.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWebDevIde w;
    w.show();
    return a.exec();
}

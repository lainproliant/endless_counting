#include "endlessmainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EndlessMainWindow w;
    w.show();

    return a.exec();
}

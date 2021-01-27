/********************************************************************************
 * Created by E-Protocol
 * https://github.com/e-protocol
********************************************************************************/
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

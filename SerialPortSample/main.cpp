#include "mainwindow.h"
#include "DeviceDialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    DeviceDialog dlg;
    dlg.show();
    return a.exec();
}

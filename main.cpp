#include "widget.h"
#include "mainWindow.h"
#include "buttonsWidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mainWin;
    Widget w(&mainWin);
    ButtonsWidget bw(&w, &mainWin);
    mainWin.show();
    return a.exec();
}

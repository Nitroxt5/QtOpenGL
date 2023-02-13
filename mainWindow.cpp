#include "mainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle("Qt+OpenGL");
    setGeometry(100, 50, 1300, 900);
    setFixedSize(1300, 900);
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QThreadPool"

#include "src/test/test.h" //TODO: THIS NEEDS TO BE REMOVED AT SOME POINT

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::run()
{
    //TODO: THIS NEEDS TO BE REMOVED AT SOME POINT
    Test test(ui->geoplot);
    test.run();
}

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setText("Javad");
    ui->pushButton->setText("Javad ragimifdf");

}

MainWindow::~MainWindow()
{
    delete ui;
}

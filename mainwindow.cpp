#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sysinfo.h"
#include <QLayout>
#include <QLabel>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    cpuWidget(this),
    memWidget(this)
{
    ui->setupUi(this);
    SysInfo::instance().init();
    //    ui->centralWidget->layout()->addWidget(&cpuWidget);
    ui->verticalLayout->layout()->addWidget(&cpuWidget);
    ui->verticalLayout->layout()->addWidget(&memWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

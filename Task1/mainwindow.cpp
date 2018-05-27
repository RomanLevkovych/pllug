#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(300, 300);
    QPushButton *closePushButton = new QPushButton("&Close", this);
    closePushButton->setGeometry((300-66)/2, (300-56)/2, 66,26);
    connect(closePushButton,&QPushButton::clicked,this, &QApplication::quit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralWidget->setFixedSize(300, 300);
    QPushButton *closePushButton = new QPushButton("&Close", this);
    closePushButton->setGeometry((300-33), (300-13), 66,26);
    connect(closePushButton,&QPushButton::clicked,this, &QApplication::quit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QString>
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->menuBar->setNativeMenuBar(false);

    connect(ui->menuQuit, &QMenu::aboutToShow, this, &QApplication::quit);
    connect(ui->menuOpen, &QMenu::aboutToShow, this, &MainWindow::slotOpen);
    connect(ui->menuSave, &QMenu::aboutToShow, this, &MainWindow::slotSave);
    connect(ui->menuSave_as, &QMenu::aboutToShow, this, &MainWindow::slotSaveAs);
    connect(ui->menuNew, &QMenu::aboutToShow, this, &MainWindow::slotNew);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotOpen()
{
    filePath = QFileDialog::getOpenFileName(this, "Open file");
    QFile openFile(filePath);
    ui->textEdit->clear();
    if (openFile.open(QIODevice::ReadOnly))
    {
        QTextStream input(&openFile);
        while(!input.atEnd())
        {
            QString line = input.readLine();
            ui->textEdit->append(line);
        }
    }
}

void MainWindow::slotSave()
{
    QFile saveFile(filePath);
    if (!saveFile.open(QIODevice::WriteOnly))
    {
        QTextStream output(&saveFile);
        output << ui->textEdit->toPlainText();
    }
    saveFile.close();
}

void MainWindow::slotSaveAs()
{

}

void MainWindow::slotNew()
{
    filePath = "";
    ui->textEdit->clear();
}

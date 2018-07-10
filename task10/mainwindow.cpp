#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QString>
#include <QFile>
#include <QDebug>
#include <QByteArray>

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
        ui->textEdit->setText(openFile.readAll());
    }
    openFile.close();
    setWindowModified(false);
}

void MainWindow::slotSave()
{
    QFile saveFile(filePath);
    qDebug() << "\n";
    qDebug() << filePath;
    if (!saveFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QByteArray output;
        output.append(ui->textEdit->toPlainText());
        saveFile.write(output);
        setWindowModified(false);
    }
    saveFile.close();
}

void MainWindow::slotSaveAs()
{
    filePath = QFileDialog::getOpenFileName(this, "Open file");
    slotSave();
}

void MainWindow::slotNew()
{
    filePath = "";
    ui->textEdit->clear();
}

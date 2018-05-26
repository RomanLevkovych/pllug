#include "widget.h"
#include "ui_widget.h"

#include <QString>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pluspushButton_clicked()
{
    double firstOperand = ui->firstOperandlineEdit->text().toDouble();
    double secondOperand = ui->secondOperandlineEdit->text().toDouble();
    ui->resultlineEdit->clear();
    ui->resultlineEdit->setText(QString::number(firstOperand + secondOperand));
}

void Widget::on_minuspushButton_clicked()
{
    double firstOperand = ui->firstOperandlineEdit->text().toDouble();
    double secondOperand = ui->secondOperandlineEdit->text().toDouble();
    ui->resultlineEdit->clear();
    ui->resultlineEdit->setText(QString::number(firstOperand - secondOperand));
}

void Widget::on_multiplypushButton_clicked()
{
    double firstOperand = ui->firstOperandlineEdit->text().toDouble();
    double secondOperand = ui->secondOperandlineEdit->text().toDouble();
    ui->resultlineEdit->clear();
    ui->resultlineEdit->setText(QString::number(firstOperand * secondOperand));
}

void Widget::on_dividepushButton_clicked()
{
    double firstOperand = ui->firstOperandlineEdit->text().toDouble();
    double secondOperand = ui->secondOperandlineEdit->text().toDouble();
    ui->resultlineEdit->clear();
    if (secondOperand == 0)
        ui->resultlineEdit->setText("Division by zero");
    else
        ui->resultlineEdit->setText(QString::number(firstOperand + secondOperand));
}

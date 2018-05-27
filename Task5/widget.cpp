#include "widget.h"
#include "ui_widget.h"

#include<QVector>
#include <QTimer>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    currentLight = 0;
    radioButtons.append(ui->redRadioButton);
    radioButtons.append(ui->YellowRadioButton);
    radioButtons.append(ui->greenRadioButton);
    timer = new QTimer(this);

}

Widget::~Widget()
{
    delete ui;
    radioButtons.clear();
    delete timer;
}

void Widget::on_startPushButton_clicked()
{
    timer->start(1000);
    connect(timer, &QTimer::timeout, this, &Widget::changeColour);
}

void Widget::changeColour()
{
    radioButtons.at((++currentLight) % 3)->setChecked(true);
}

void Widget::on_stopPushButton_clicked()
{
    timer->stop();
}

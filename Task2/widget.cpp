#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    status = false;
    ui->checkBox->setChecked(true);
    ui->spinBox->setMaximum(99);

    //MARK: - Connects
    connect(ui->pushButton, &QPushButton::clicked, this, &Widget::buttonPressed);
    connect(ui->horizontalSlider, &QSlider::sliderMoved, this, &Widget::sliderMoved);
    connect(ui->verticalScrollBar, &QScrollBar::sliderMoved, this, &Widget::scrollBarMoved);
    connect(ui->spinBox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &Widget::spinBoxValueChanged);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::buttonPressed()
{
    if (status)
    {
        ui->checkBox->setChecked(false);
        ui->radioButton->setChecked(true);
    } else {
        ui->checkBox->setChecked(true);
        ui->radioButton->setChecked(false);
    }
    status = !status;
}

void Widget::sliderMoved(int pos)
{
    ui->spinBox->setValue(pos);
    ui->verticalScrollBar->setValue(pos);
}

void Widget::scrollBarMoved(int pos)
{
    ui->spinBox->setValue(pos);
    ui->horizontalSlider->setValue(pos);
}

void Widget::spinBoxValueChanged(int val)
{
    ui->horizontalSlider->setValue(val);
    ui->verticalScrollBar->setValue(val);
}

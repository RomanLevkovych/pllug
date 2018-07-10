#include "widget.h"
#include "ui_widget.h"

#include <QPixmap>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->loadPushButton, &QPushButton::clicked, this, &Widget::load);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::load()
{
    QPixmap picture;
    if (picture.load(ui->pathLineEdit->text()))
    {
        ui->showPicLabel->setPixmap(picture);
    }
}

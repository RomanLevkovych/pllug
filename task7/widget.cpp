#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setMouseTracking(true);

    connect(this, &Widget::signalMouseMove, this, &Widget::slotMouseOver);
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->button() == Qt::NoButton)
    {
        mMousePositionX = event->x();
        mMousePositionY = event->y();
    }
    emit signalMouseMove();
}

void Widget::slotMouseOver()
{
    bool upperBoundX = mMousePositionX <= (ui->pushButton->x() + ui->pushButton->width());
    bool lowerBoundX = mMousePositionX >= ui->pushButton->x();
    bool upperBoundY = mMousePositionY <= (ui->pushButton->y() + ui->pushButton->height());
    bool lowerBoundY = mMousePositionY >= ui->pushButton->y();

    if(upperBoundX && lowerBoundX && upperBoundY && lowerBoundY)
    {
        ui->pushButton->setGeometry(ui->pushButton->x()+25, ui->pushButton->y()+25, ui->pushButton->width(), ui->pushButton->height());
    }
}

Widget::~Widget()
{
    delete ui;
}

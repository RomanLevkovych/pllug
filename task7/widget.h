#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QEvent>
#include <QMouseEvent>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void mouseMoveEvent(QMouseEvent *event);
public slots:
    void slotMouseOver();
signals:
    void signalMouseMove();
private:
    Ui::Widget *ui;
    int mMousePositionX;
    int mMousePositionY;
};

#endif // WIDGET_H

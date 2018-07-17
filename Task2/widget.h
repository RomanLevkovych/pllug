#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void buttonPressed();
    void sliderMoved(int pos);
    void scrollBarMoved(int pos);
    void spinBoxValueChanged(int val);

private:
    Ui::Widget *ui;
    bool status; //check if pressed
};

#endif // WIDGET_H

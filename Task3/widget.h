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

private slots:


    void on_pluspushButton_clicked();

    void on_minuspushButton_clicked();

    void on_multiplypushButton_clicked();

    void on_dividepushButton_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H

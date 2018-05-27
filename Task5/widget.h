#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QRadioButton>

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
    void on_startPushButton_clicked();
    void changeColour();

    void on_stopPushButton_clicked();

private:
    QTimer *timer;
    int currentLight;
    Ui::Widget *ui;
    QVector<QRadioButton *> radioButtons;
};

#endif // WIDGET_H

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSignalMapper>
#include <vector>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void isWinner();

public slots:
    void clearField();
    void playersTurn(int id);
    void clearButton(int id);

signals:
    void signalNewGameStarted(int id);

private:
    QSignalMapper *buttonsMapper;
    Ui::Widget *ui;
    std::vector<QString> fieldState; //current situation on field
    bool state; //true on first player's turn and false on second players turn
};

#endif // WIDGET_H

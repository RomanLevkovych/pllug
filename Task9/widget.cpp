#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    state = true;
    buttonsMapper = new QSignalMapper(this);
    ui->playerInfoLabel->setText("Player 1");

    for (auto it = 0; it <= 9; ++it)
    {
        fieldState.push_back(QString(""));
    }

    buttonsMapper->setMapping(ui->pushButton_1, 1);
    buttonsMapper->setMapping(ui->pushButton_2, 2);
    buttonsMapper->setMapping(ui->pushButton_3, 3);
    buttonsMapper->setMapping(ui->pushButton_4, 4);
    buttonsMapper->setMapping(ui->pushButton_5, 5);
    buttonsMapper->setMapping(ui->pushButton_6, 6);
    buttonsMapper->setMapping(ui->pushButton_7, 7);
    buttonsMapper->setMapping(ui->pushButton_8, 8);
    buttonsMapper->setMapping(ui->pushButton_9, 9);


    connect(ui->newGameButton, &QPushButton::clicked, this, &Widget::clearField);

    connect(ui->pushButton_1, &QPushButton::clicked, buttonsMapper, static_cast<void (QSignalMapper::*) ()>(&QSignalMapper::map));
    connect(ui->pushButton_2, &QPushButton::clicked, buttonsMapper, static_cast<void (QSignalMapper::*) ()>(&QSignalMapper::map));
    connect(ui->pushButton_3, &QPushButton::clicked, buttonsMapper, static_cast<void (QSignalMapper::*) ()>(&QSignalMapper::map));
    connect(ui->pushButton_4, &QPushButton::clicked, buttonsMapper, static_cast<void (QSignalMapper::*) ()>(&QSignalMapper::map));
    connect(ui->pushButton_5, &QPushButton::clicked, buttonsMapper, static_cast<void (QSignalMapper::*) ()>(&QSignalMapper::map));
    connect(ui->pushButton_6, &QPushButton::clicked, buttonsMapper, static_cast<void (QSignalMapper::*) ()>(&QSignalMapper::map));
    connect(ui->pushButton_7, &QPushButton::clicked, buttonsMapper, static_cast<void (QSignalMapper::*) ()>(&QSignalMapper::map));
    connect(ui->pushButton_8, &QPushButton::clicked, buttonsMapper, static_cast<void (QSignalMapper::*) ()>(&QSignalMapper::map));
    connect(ui->pushButton_9, &QPushButton::clicked, buttonsMapper, static_cast<void (QSignalMapper::*) ()>(&QSignalMapper::map));

    connect(buttonsMapper, static_cast<void (QSignalMapper::*)(int)>(&QSignalMapper::mapped), this, &Widget::playersTurn);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::isWinner()
{
    for (int i = 1; i <= 3; ++i)
    {
        if ((fieldState.at(i) == fieldState.at(i+1) == fieldState.at(i+2)) && fieldState.at(i) != "")
        {
            ui->playerInfoLabel->setText(QString("Player " + fieldState.at(i) + " wins"));
        }
    }

    for (int i = 1; i <= 3; ++i)
    {
        if ((fieldState.at(i) == fieldState.at(i+3) == fieldState.at(i+6)) && fieldState.at(i) != "")
        {
            ui->playerInfoLabel->setText(QString("Player " + fieldState.at(i) + " wins"));
        }
    }
    if (fieldState.at(1) == fieldState.at(5) == fieldState.at(9) && fieldState.at(1) != "")
    {
        ui->playerInfoLabel->setText(QString("Player " + fieldState.at(2) + " wins"));
    }
    if (fieldState.at(3) == fieldState.at(5) == fieldState.at(7) && fieldState.at(7) != "")
    {
        ui->playerInfoLabel->setText(QString("Player  wins"));
    }
}

void Widget::clearField()
{
    ui->pushButton_1->setText("");
    ui->pushButton_2->setText("");
    ui->pushButton_3->setText("");
    ui->pushButton_4->setText("");
    ui->pushButton_5->setText("");
    ui->pushButton_6->setText("");
    ui->pushButton_7->setText("");
    ui->pushButton_8->setText("");
    ui->pushButton_9->setText("");
    ui->pushButton_1->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_4->setEnabled(true);
    ui->pushButton_5->setEnabled(true);
    ui->pushButton_6->setEnabled(true);
    ui->pushButton_7->setEnabled(true);
    ui->pushButton_8->setEnabled(true);
    ui->pushButton_9->setEnabled(true);
}

void Widget::playersTurn(int id)
{
    const auto buttonPressed = qobject_cast<QPushButton *> (buttonsMapper->mapping(id));
    if (state)
    {
        buttonPressed->setText("X");
        buttonPressed->setEnabled(false);
        ui->playerInfoLabel->setText("Player 1");
        fieldState.at(id) = "X";
    } else {
        buttonPressed->setText("O");
        ui->playerInfoLabel->setText("Player 2");
        buttonPressed->setEnabled(false);
        fieldState.at(id) = "O";
    }
    //  isWinner();
    state = !state;
}

void Widget::clearButton(int id)
{
    qobject_cast<QPushButton *>(buttonsMapper->mapping(id))->setEnabled(true);
    qobject_cast<QPushButton *>(buttonsMapper->mapping(id))->setText("");
}



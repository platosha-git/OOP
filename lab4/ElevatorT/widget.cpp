#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->liftStatus->append("Лифт на 1 этаже.");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_inFloor1_clicked()
{
    ui->liftStatus->append("В лифте нажата кнопка: 1 этаж.");
    lift.acceptOrder(1);
}

void Widget::on_inFloor2_clicked()
{
    ui->liftStatus->append("В лифте нажата кнопка: 2 этаж.");
    lift.acceptOrder(2);
}

void Widget::on_inFloor3_clicked()
{
    ui->liftStatus->append("В лифте нажата кнопка: 3 этаж.");
    lift.acceptOrder(3);
}

void Widget::on_inFloor4_clicked()
{
    ui->liftStatus->append("В лифте нажата кнопка: 4 этаж.");
    lift.acceptOrder(4);
}

void Widget::on_inFloor5_clicked()
{
    ui->liftStatus->append("В лифте нажата кнопка: 5 этаж.");
    lift.acceptOrder(5);
}

////////////////////////////////////////////////////////////////////

void Widget::on_outFloor1_clicked()
{
    ui->liftStatus->append("Лифт был вызван на 1 этаже.");
    lift.acceptOrder(1);
}

void Widget::on_outFloor2_clicked()
{
    ui->liftStatus->append("Лифт был вызван на 2 этаже.");
    lift.acceptOrder(2);
}

void Widget::on_outFloor3_clicked()
{
    ui->liftStatus->append("Лифт был вызван на 3 этаже.");
    lift.acceptOrder(3);
}

void Widget::on_outFloor4_clicked()
{
    ui->liftStatus->append("Лифт был вызван на 4 этаже.");
    lift.acceptOrder(4);
}

void Widget::on_outFloor5_clicked()
{
    ui->liftStatus->append("Лифт был вызван на 5 этаже.");
    lift.acceptOrder(5);
}

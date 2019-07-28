#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbGongcha->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int n){
    money += n;
    ui->lcdNumber->display(QString::number((money)));

    ui->pbCoffee->setEnabled(money>=100);
    ui->pbTea->setEnabled(money>=150);
    ui->pbGongcha->setEnabled(money>=200);
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbGongcha_clicked()
{
     changeMoney(-200);
}

void Widget::on_pbReturn_clicked()
{
    int _500 = money / 500;
    int result = money % 500;
    int _100 = result / 100;
    result = result % 100;
    int _50 = result / 50;
    int _10 = result % 50;


    QString str = "500W : " + QString::number(_500) + "\n100W : " + QString::number(_100) + "\n50W : " + QString::number(_50) + "\n10W : " + QString::number(_10);


    QMessageBox msg;
    msg.information(nullptr, "change", str);
}

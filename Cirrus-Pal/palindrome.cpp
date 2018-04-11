#include "palindrome.h"
#include "ui_palindrome.h"
#include <iostream>

Palindrome::Palindrome(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Palindrome)
{
    ui->setupUi(this);
}

Palindrome::~Palindrome()
{
    delete ui;
}

void Palindrome::on_pushButton_clicked()
{
    QString big = ui->big->text();
    QString small = ui->small->text();

    ui->lcdNumber->display(big.toDouble());
}

#include "palindrome.h"
#include "ui_palindrome.h"

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

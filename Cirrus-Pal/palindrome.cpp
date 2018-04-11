#include "palindrome.h"
#include "ui_palindrome.h"
#include <iostream>
#include <QFormLayout>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

Palindrome::Palindrome(QWidget *parent) :
    QMainWindow(parent)
{
    //components of the dialog
    QWidget *mainWidget = new QWidget(this);
    QGridLayout *gLayout = new QGridLayout(this);
    QVBoxLayout *vLayout = new QVBoxLayout;
    QFormLayout *fLayout = new QFormLayout;
    bigNumber = new QLineEdit();
    lowNumber = new QLineEdit();
    palLabel = new QLabel("something", this);
    QPushButton *computeButton = new QPushButton(this);

    //set up layout for components
    computeButton->setText("Compute!");
    vLayout->addWidget(palLabel);
    vLayout->setMargin(40);
    fLayout->addRow("Big Number: ", bigNumber);
    fLayout->addRow("Low Number: ", lowNumber);
    fLayout->addWidget(computeButton);
    gLayout->addLayout(fLayout, 0, 0, 1, 3);
    gLayout->addLayout(vLayout, 0,3,1,1);

    //connect button to slot
    QObject::connect(computeButton, SIGNAL(clicked()), this, SLOT(computeClicked()));

    //set the top layout to the main widget
    mainWidget->setLayout(gLayout);

    //set the default size of the window and set central widget
    this->setGeometry(250,250,450,250);
    this->setCentralWidget(mainWidget);

    //display the window
    show();
}

//Sets the label in the window to the highest palindrome
void Palindrome::computeClicked() {
    QString big = bigNumber->text();
    QString little = lowNumber->text();
    std::string pal = findPalindrome(big.toInt(), little.toInt());
    palLabel->setText(QString::fromStdString(pal));
}

/*
 * Finds the largest palindrome between two sets of numbers
 * current - The larger number in the set
 * limit - The smallest number in the set
 * returns - returns the palindromic number as a std::string
 */
std::string Palindrome::findPalindrome(const int current, const int limit) {
    if (current == limit) return "nothing";
    else {
        const std::string c = std::to_string(current);
        if (isPal(c, 0, (int)c.size()/2)) return c;
        else return findPalindrome(current - 1, limit);
    }
}

/*
 * recursively computes whether is a number is a palindrome
 * n - The number being evaluated represented as a string
 * index - the index of the number being evaluated
 * halfsize - the index of half the number
 * returns - returns a boolean representing whether or not the number evaluated is palindromic or not
 */
bool Palindrome::isPal(const std::string n, const int index, const int halfSize) {
    if (index == halfSize) return true;
    else {
        if (n.at(index) != n.at((n.size() - 1) - index)) return false;
        else return isPal(n, index + 1, halfSize);
    }
}

Palindrome::~Palindrome()
{
    delete bigNumber;
    delete lowNumber;
    delete palLabel;
}

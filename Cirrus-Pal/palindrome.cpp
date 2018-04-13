#include "palindrome.h"
#include "ui_palindrome.h"
#include <iostream>
#include <QFormLayout>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>

Palindrome::Palindrome(QWidget *parent) :
    QMainWindow(parent)
{
    //components of the dialog
    QWidget *mainWidget = new QWidget(this);

    QGridLayout *gLayout = new QGridLayout(this);
    QGridLayout *vLayout = new QGridLayout(this);
    QVBoxLayout *tLayout = new QVBoxLayout;
    QVBoxLayout *fLayout = new QVBoxLayout;

    QPushButton *bigLabel = new QPushButton("Big Number:", this);
    QPushButton *smallLabel = new QPushButton("Small Number: ", this);
    QPushButton *title = new QPushButton("Palindrome Finder", this);
    QPushButton *computeButton = new QPushButton("Compute!",this);
    QPushButton *PTitle = new QPushButton("Largest Palindromic Number:", this);
    palLabel = new QPushButton("0", this);

    bigNumber = new QLineEdit();
    lowNumber = new QLineEdit();
    QFrame *tLine = new QFrame;

    /**
     * NOTE
     * I had to use buttons here instead of labels as there
     * seems to be some sort of bug in the QT framework when
     * it comes to adding styling to QLabels.
     *
     * Instead, I just added a little bit of css to the buttons
     * to turn them into labels.
     *
     **/
    //Styling all the widgets
    bigLabel->setStyleSheet("QPushButton { padding: 0 0 4 2px;"
                                          "background: transparent;"
                                          "border: none;"
                                          "text-align: left;}");

    smallLabel->setStyleSheet("QPushButton {background: transparent;"
                                           "border: none;"
                                           "text-align: left;"
                                           "padding: 20 0 4 2px}");

    PTitle->setStyleSheet("QPushButton {background: transparent;"
                                       "border: none;"
                                       "text-align:left;"
                                       "padding: 0 0 10 0px;}");

    palLabel->setStyleSheet("QPushButton {background: transparent;"
                                         "border: none;"
                                         "text-align: right;"
                                         "margin: 20 10 0 0px;}");

    title->setStyleSheet("QPushButton { padding: 0 0 4 2px;"
                                       "background: transparent;"
                                       "border: none;"
                                       "text-align: left;}");

    computeButton->setStyleSheet("QPushButton {margin: 15 0 0 0px;"
                                              "border: none;"
                                              "color: white;"
                                              "text-align: center;"
                                              "background-color: grey;"
                                              "font-size: 13px;"
                                              "padding: 10 24px;"
                                              "border-radius: 8px;"
                                              "width: 100px}");

    tLine->setFrameShape(QFrame::HLine);
    tLine->setFrameShadow(QFrame::Sunken);

    //set up layout for components
    vLayout->addWidget(PTitle, 0,0);
    vLayout->addWidget(palLabel,0,0);
    vLayout->setSpacing(0);
    vLayout->setContentsMargins(40,-1,-1,-1);

    tLayout->addWidget(title);
    tLayout->addWidget(tLine);
    tLayout->setSpacing(0);
    tLayout->setContentsMargins(-1,-1,-1,-1);

    fLayout->addWidget(bigLabel);
    fLayout->addWidget(bigNumber);
    fLayout->addWidget(smallLabel);
    fLayout->addWidget(lowNumber);
    fLayout->addWidget(computeButton, 0, Qt::AlignCenter);
    fLayout->setSpacing(0);

    gLayout->addLayout(tLayout, 0, 0, 1, 4);
    gLayout->addLayout(fLayout, 1, 0, 1, 3);
    gLayout->addLayout(vLayout, 1,3,1,1);
    gLayout->setSpacing(0);

    //connect button to slot
    QObject::connect(computeButton, SIGNAL(clicked()), this, SLOT(computeClicked()));

    //set the top layout to the main widget
    mainWidget->setLayout(gLayout);

    //set the default size of the window and set central widget
    this->setGeometry(250,250,350,150);
    this->setCentralWidget(mainWidget);

    //display the window
    show();
}

//Sets the label in the window to the highest palindrome
void Palindrome::computeClicked() {
    bool bIsInt;
    bool sIsInt;
    const int bigInt = bigNumber->text().toInt(&bIsInt, 10);
    const int littleInt = lowNumber->text().toInt(&sIsInt, 10);
    if (!bIsInt | !sIsInt) {
        palLabel->setText("Not a base 10 Number!");
    }
    else if (bigInt < 0 || littleInt < 0) {
        palLabel->setText("No negatives!");
    } else if (bigInt < littleInt) {
        palLabel->setText("Big number too small!");
    } else {
        std::string pal = findPalindrome(bigInt, littleInt);
        palLabel->setText(QString::fromStdString(pal));
    }
}

/*
 * Finds the largest palindrome between two sets of numbers
 * current - The larger number in the set
 * limit - The smallest number in the set
 * returns - returns the palindromic number as a std::string
 */
std::string Palindrome::findPalindrome(const int current, const int limit) {
    if (current < limit) return "nothing";
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

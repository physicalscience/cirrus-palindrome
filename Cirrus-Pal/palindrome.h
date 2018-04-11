#ifndef PALINDROME_H
#define PALINDROME_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>

namespace Ui {
class Palindrome;
}

class Palindrome : public QMainWindow
{
    Q_OBJECT

public:
    explicit Palindrome(QWidget *parent = 0);
    ~Palindrome();

private slots:
    void computeClicked();

private:
    Ui::Palindrome *ui;
    QLabel *palLabel;
    QLineEdit *bigNumber;
    QLineEdit *lowNumber;

    std::string findPalindrome(const int current, const int limit);
    bool isPal(const std::string n, const int index, const int halfSize);

};

#endif // PALINDROME_H

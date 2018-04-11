#ifndef PALINDROME_H
#define PALINDROME_H

#include <QMainWindow>

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
    void on_pushButton_clicked();

private:
    Ui::Palindrome *ui;
};

#endif // PALINDROME_H

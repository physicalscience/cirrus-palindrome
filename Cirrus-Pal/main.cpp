#include "palindrome.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Palindrome w;
    w.show();

    return a.exec();
}

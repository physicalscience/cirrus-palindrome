#include <iostream>
#include <string>
using namespace std;

bool isPal(string n, int index, int halfSize);
string palWrapper(int current, int limit);

int main() {
    int bigNumber;
    int littleNumber;
    cout << "enter some big number: " << endl;
    cin >> bigNumber;
    cout << "enter little number: " << endl;
    cin >> littleNumber;

    string s =  palWrapper(bigNumber, littleNumber);

    cout << "this is the largest palindrome: " << s << endl;
    return 0;
}

string palWrapper(int current, int limit) {
    if (current == limit) return "nothing";
    else {
        string c = to_string(current);
        if (isPal(c, 0, (int)c.size()/2)) return c;
        else return palWrapper(current - 1, limit);
    }
}

bool isPal(string n, int index, int halfSize) {
    if (index == halfSize) return true;
    else {
        if (n.at(index) != n.at((n.size() - 1) - index)) return false;
        else return isPal(n, ++index, halfSize);
    }
}
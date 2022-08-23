#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void print(const string &a, const string &b, const string &c, const string &d) {
    cout << left << setw(15) << a << setw(3) << b;
    cout << right << setw(2) << c << setw(3) << d << '\n';
}

int main() {
    print("NFC West", "W", "L", "T");
    cout << "-----------------------\n";
    print("Seattle", "13", "3", "0");
    print("San Francisco", "12", "4", "0");
    print("Arizona", "10", "6", "0");
    print("St. Louis", "7", "9", "0");
    cout << '\n';
    print("NFC North", "W", "L", "T");
    cout << "-----------------------\n";
    print("Green Bay", "8", "7", "1");
    print("Chicago", "8", "8", "0");
    print("Detroit", "7", "9", "0");
    print("Minnesota", "5", "10", "1");
    return 0;
}

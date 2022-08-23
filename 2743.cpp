#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string word;
    getline(cin, word);
    for (auto const &x : word) {
        if (isalpha(x)) {
            if (('A' <= x && x <= 'M') || ('a' <= x && x <= 'm')) {
                cout << char(x + 13);
            } else {
                cout << char(x - 13);
            }
        } else {
            cout << x;
        }
    }
    return 0;
}

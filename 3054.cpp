#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;

    cout << "..#..";
    for (int i = 1; i < str.size(); ++i) {
        cout << (i % 3 == 2 ? ".*.." : ".#..");
    }
    cout << '\n';

    cout << ".#.#.";
    for (int i = 1; i < str.size(); ++i) {
        cout << (i % 3 == 2 ? "*.*." : "#.#.");
    }
    cout << '\n';

    cout << "#." << str[0] << ".#";
    for (int i = 1; i < str.size() - 1; ++i) {
        cout << '.' << str[i] << '.' << (i % 3 ? '*' : '#');
    }
    if (str.size() > 1) {
        cout << '.' << str.back() << '.' << (str.size() % 3 ? '#' : '*');
    }
    cout << '\n';

    cout << ".#.#.";
    for (int i = 1; i < str.size(); ++i) {
        cout << (i % 3 == 2 ? "*.*." : "#.#.");
    }
    cout << '\n';

    cout << "..#..";
    for (int i = 1; i < str.size(); ++i) {
        cout << (i % 3 == 2 ? ".*.." : ".#..");
    }
    cout << '\n';
    return 0;
}

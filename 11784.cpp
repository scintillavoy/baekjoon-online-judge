#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    while (cin >> str) {
        for (int i = 0; i < str.size(); i += 2) {
            cout << char(stoi(str.substr(i, 2), 0, 16));
        }
        cout << '\n';
    }
    return 0;
}

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;
    cout << oct;
    if (str.size() % 3 != 0) {
        cout << stoi(str.substr(0, str.size() % 3), nullptr, 2);
    }
    for (int i = str.size() % 3; i < str.size(); i += 3) {
        cout << stoi(str.substr(i, 3), nullptr, 2);
    }
    return 0;
}

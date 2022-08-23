#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;
    if (str[1] == '0') {
        cout << 10 + stoi(str.substr(2, string::npos));
    } else {
        cout << stoi(str.substr(0, 1)) + stoi(str.substr(1, string::npos));
    }
    return 0;
}

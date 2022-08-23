#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    while (getline(cin, str)) {
        if (str == "***") {
            break;
        }
        for (auto it = str.crbegin(); it != str.crend(); ++it) {
            cout << *it;
        }
        cout << '\n';
    }
    return 0;
}

#include <iostream>
#include <string>
#include <limits>
#include <cctype>
using namespace std;

int main() {
    string str;
    while (getline(cin, str)) {
        if (str[0] == '#') {
            break;
        }
        int cnt = 0;
        for (int i = 2; i < str.size(); ++i) {
            if (tolower(str[i]) == str[0]) {
                ++cnt;
            }
        }
        cout << str[0] << ' ' << cnt << '\n';
    }
    return 0;
}

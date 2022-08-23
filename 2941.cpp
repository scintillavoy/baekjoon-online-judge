#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;
    int cnt = 0;
    for (int i = 0; i < str.size(); ++i, ++cnt) {
        switch (str[i]) {
            case 'c':
                if (i + 1 < str.size() &&
                    (str[i + 1] == '=' || str[i + 1] == '-')) {
                    ++i;
                }
                break;
            case 'd':
                if (i + 1 < str.size() && str[i + 1] == '-') {
                    ++i;
                } else if (i + 2 < str.size() &&
                    str[i + 1] == 'z' && str[i + 2] == '=') {
                    i += 2;
                }
                break;
            case 'l':
                if (i + 1 < str.size() && str[i + 1] == 'j') {
                    ++i;
                }
                break;
            case 'n':
                if (i + 1 < str.size() && str[i + 1] == 'j') {
                    ++i;
                }
                break;
            case 's':
                if (i + 1 < str.size() && str[i + 1] == '=') {
                    ++i;
                }
                break;
            case 'z':
                if (i + 1 < str.size() && str[i + 1] == '=') {
                    ++i;
                }
                break;
        }
    }
    cout << cnt;
    return 0;
}

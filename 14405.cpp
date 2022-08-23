#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); ) {
        switch (str[i]) {
            case 'p':
                if (str.substr(i, 2) != "pi") {
                    cout << "NO";
                    return 0;
                } else {
                    i += 2;
                    break;
                }
            case 'k':
                if (str.substr(i, 2) != "ka") {
                    cout << "NO";
                    return 0;
                } else {
                    i += 2;
                    break;
                }
            case 'c':
                if (str.substr(i, 3) != "chu") {
                    cout << "NO";
                    return 0;
                } else {
                    i += 3;
                    break;
                }
            default:
                cout << "NO";
                return 0;
        }
    }
    cout << "YES";
    return 0;
}

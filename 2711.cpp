#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int errIdx;
        string str;
        cin >> errIdx >> str;
        for (int j = 0; j < errIdx - 1; ++j) {
            cout << str[j];
        }
        for (int j = errIdx; j < str.size(); ++j) {
            cout << str[j];
        }
        cout << '\n';
    }
    return 0;
}

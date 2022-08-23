#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    string input;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> input;
        int cnt = 0;
        bool valid = true;
        for (auto const &x : input) {
            if (x == '(') {
                ++cnt;
            } else if (x == ')') {
                if (cnt <= 0) {
                    valid = false;
                    break;
                }
                --cnt;
            }
        }
        if (cnt) {
            valid = false;
        }
        if (valid) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}

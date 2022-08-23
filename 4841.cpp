#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string str;
        cin >> str;
        int cnt = 0;
        char num = str[0];
        for (auto const &x : str) {
            if (x != num) {
                cout << cnt << num;
                cnt = 1;
                num = x;
            } else {
                ++cnt;
            }
        }
        cout << cnt << num << '\n';
    }
    return 0;
}

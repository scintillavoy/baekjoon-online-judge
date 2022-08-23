#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string str;
        cin >> str;
        int ans = 3;
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] == 'l') {
                if (i+1 < str.size() && str[i+1] == 'o') {
                    if (i+2 < str.size() && str[i+2] == 'l') {
                        ans = 0;
                        break;
                    } else {
                        ans = 1;
                    }
                } else if (i+1 < str.size() && str[i+1] == 'l') {
                    ans = 1;
                } else if (i+2 < str.size() && str[i+2] == 'l') {
                    ans = 1;
                } else {
                    ans = min(ans, 2);
                }
            } else if (str[i] == 'o') {
                if (i+1 < str.size() && str[i+1] == 'l') {
                    ans = 1;
                } else {
                    ans = min(ans, 2);
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

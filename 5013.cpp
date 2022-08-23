#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    while (n--) {
        string str;
        cin >> str;
        bool win = true;
        for (int i = 0; i < str.size() - 1; ++i) {
            if (str[i] == 'C' && str[i+1] == 'D') {
                win = false;
                break;
            }
        }
        if (win) {
            ++cnt;
        }
    }
    cout << cnt;
    return 0;
}

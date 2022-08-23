#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int H, W;
        cin >> H >> W;
        while (H--) {
            string str;
            cin >> str;
            reverse(str.begin(), str.end());
            cout << str << '\n';
        }
    }
    return 0;
}

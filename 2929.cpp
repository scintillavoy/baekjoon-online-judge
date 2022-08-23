#include <iostream>
#include <cctype>
using namespace std;

int main() {
    int cnt = 0;
    char c;
    for (int i = 0; cin >> c; ++i) {
        if (isupper(c)) {
            if (i % 4 != 0) {
                cnt += 4 - i % 4;
                i = 0;
            }
        }
    }
    cout << cnt;
}

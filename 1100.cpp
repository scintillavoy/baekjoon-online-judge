#include <iostream>
using namespace std;

int main() {
    int cnt = 0;
    char c[2];
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> c[0] >> c[1];
            if (i % 2 == 0 && c[0] == 'F') {
                ++cnt;
            } else if (i % 2 == 1 && c[1] == 'F') {
                ++cnt;
            }
        }
    }
    cout << cnt;
    return 0;
}

#include <iostream>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    for (int i = 0; i < H; ++i) {
        int pos = -1;
        for (int j = 0; j < W; ++j) {
            char c;
            cin >> c;
            if (j > 0) {
                cout << ' ';
            }
            if (c == 'c') {
                pos = 0;
            } else if (pos != -1) {
                ++pos;
            }
            cout << pos;
        }
        cout << '\n';
    }
    return 0;
}

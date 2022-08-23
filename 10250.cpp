#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int H, W, N;
        cin >> H >> W >> N;
        cout << (N - 1) % H + 1;
        int X = (N - 1) / H + 1;
        if (X < 10) {
            cout << 0;
        }
        cout << X << '\n';
    }
    return 0;
}

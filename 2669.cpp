#include <iostream>
using namespace std;

int main() {
    int arr[99][99] = {0};
    for (int i = 0; i < 4; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int j = x1 - 1; j < x2 - 1; ++j) {
            for (int k = y1 - 1; k < y2 - 1; ++k) {
                ++arr[j][k];
            }
        }
    }
    int cnt = 0;
    for (auto const &row : arr) {
        for (auto const &x : row) {
            if (x > 0) {
                ++cnt;
            }
        }
    }
    cout << cnt;
    return 0;
}

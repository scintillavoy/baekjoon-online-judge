#include <iostream>
using namespace std;

int main() {
    int color[100][100] = {0};
    int numOfPaper;
    cin >> numOfPaper;
    for (int i = 0; i < numOfPaper; ++i) {
        int x, y;
        cin >> x >> y;
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < 10; ++k) {
                color[x + j][y + k] = 1;
            }
        }
    }
    int cnt = 0;
    for (auto const &x : color) {
        for (auto const &y : x) {
            if (y == 1) {
                ++cnt;
            }
        }
    }
    cout << cnt;
    return 0;
}

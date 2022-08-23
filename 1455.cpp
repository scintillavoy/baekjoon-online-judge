#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<char>> vec(N, vector<char>(M));
    for (auto &row : vec) {
        for (auto &x : row) {
            cin >> x;
        }
    }
    int cnt = 0;
    for (int i = N - 1; i >= 0; --i) {
        for (int j = M - 1; j >= 0; --j) {
            if (vec[i][j] == '1') {
                ++cnt;
                for (int i2 = 0; i2 <= i; ++i2) {
                    for (int j2 = 0; j2 <= j; ++j2) {
                        vec[i2][j2] = (vec[i2][j2] == '0' ? '1' : '0');
                    }
                }
            }
        }
    }
    cout << cnt;
    return 0;
}

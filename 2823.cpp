#include <iostream>
#include <vector>
using namespace std;

int main() {
    int R, C;
    cin >> R >> C;
    vector<vector<char>> vec(R, vector<char>(C));
    for (auto &row : vec) {
        for (auto &x : row) {
            cin >> x;
        }
    }
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (vec[i][j] == 'X') {
                continue;
            }
            int cnt = 0;
            if (i > 0 && vec[i-1][j] == '.') {
                ++cnt;
            }
            if (i < R - 1 && vec[i+1][j] == '.') {
                ++cnt;
            }
            if (j > 0 && vec[i][j-1] == '.') {
                ++cnt;
            }
            if (j < C - 1 && vec[i][j+1] == '.') {
                ++cnt;
            }
            if (cnt < 2) {
                cout << 1;
                return 0;
            }
        }
    }
    cout << 0;
    return 0;
}

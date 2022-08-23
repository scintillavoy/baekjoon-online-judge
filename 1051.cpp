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

    int l;
    for (l = min(N, M); l > 1; --l) {
        for (int i = 0; i <= N - l; ++i) {
            for (int j = 0; j <= M - l; ++j) {
                if (vec[i][j] == vec[i][j + l - 1] &&
                    vec[i][j + l - 1] == vec[i + l - 1][j + l - 1] &&
                    vec[i + l - 1][j + l - 1] == vec[i + l - 1][j]) {
                    cout << l * l;
                    return 0;
                }
            }
        }
    }
    cout << l * l;
    return 0;
}

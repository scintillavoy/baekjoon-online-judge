#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> dp(N, vector<int>(M));
    for (auto &row : dp) {
        for (auto &x : row) {
            cin >> x;
        }
    }
    for (int i = 1; i < N; ++i) {
        dp[i][0] += dp[i-1][0];
    }
    for (int i = 1; i < M; ++i) {
        dp[0][i] += dp[0][i-1];
    }
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < M; ++j) {
            dp[i][j] += max(dp[i][j-1], dp[i-1][j]);
        }
    }
    cout << dp[N-1][M-1];
    return 0;
}

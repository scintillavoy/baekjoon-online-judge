#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T, W;
    cin >> T >> W;
    vector<int> tree(T + 1);
    for (int i = 1; i <= T; ++i) {
        cin >> tree[i];
    }

    vector<vector<vector<int>>> dp(T + 1,
        vector<vector<int>>(W + 1, vector<int>(2)));
    dp[1][(tree[1]+1)%2][(tree[1]+1)%2] = 1;
    for (int i = 2; i <= T; ++i) {
        dp[i][0][tree[i]%2] = dp[i-1][0][tree[i]%2];
        dp[i][0][(tree[i]+1)%2] = dp[i-1][0][(tree[i]+1)%2] + 1;
        for (int j = 1; j <= W; ++j) {
            dp[i][j][tree[i]%2] = max(dp[i-1][j][tree[i]%2],
                                        dp[i-1][j-1][(tree[i]+1)%2]);
            dp[i][j][(tree[i]+1)%2] = max(dp[i-1][j][(tree[i]+1)%2],
                                            dp[i-1][j-1][tree[i]%2]) + 1;
        }
    }
    int maxNum = 0;
    for (auto const &x : dp[T]) {
        for (auto const &y : x) {
            if (maxNum < y) {
                maxNum = y;
            }
        }
    }
    cout << maxNum;
    return 0;
}

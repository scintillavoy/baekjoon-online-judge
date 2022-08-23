#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> sticker(2, vector<int>(n));
        for (auto &row : sticker) {
            for (auto &x : row) {
                cin >> x;
            }
        }
        vector<vector<int>> dp(n, vector<int>(3));
        dp[0] = {sticker[0][0], sticker[1][0], 0};
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + sticker[0][i];
            dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + sticker[1][i];
            dp[i][2] = *max_element(dp[i-1].begin(), dp[i-1].end());
        }
        cout << *max_element(dp[n-1].begin(), dp[n-1].end()) << '\n';
    }
    return 0;
}

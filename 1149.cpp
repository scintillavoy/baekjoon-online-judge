#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> dp(N, vector<int>(3));
    vector<vector<int>> price(N, vector<int>(3));
    for (auto &x : price) {
        cin >> x[0] >> x[1] >> x[2];
    }

    dp[0] = price[0];
    for (int i = 1; i < N; ++i) {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + price[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + price[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + price[i][2];
    }

    cout << min({dp[N-1][0], dp[N-1][1], dp[N-1][2]});
    return 0;
}

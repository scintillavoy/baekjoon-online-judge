#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> dp(N, vector<int>(2));
    vector<int> score(N);
    for (auto &x : score) {
        cin >> x;
    }

    dp[0][0] = score[0];
    dp[0][1] = 0;
    dp[1][0] = score[1];
    dp[1][1] = score[0] + score[1];
    for (int i = 2; i < N; ++i) {
        dp[i][0] = *max_element(dp[i-2].cbegin(), dp[i-2].cend()) + score[i];
        dp[i][1] = dp[i-1][0] + score[i];
    }

    cout << max(dp.back()[0], dp.back()[1]);
    return 0;
}

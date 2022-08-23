#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> dp(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            int num;
            cin >> num;
            dp[i].push_back(num);
        }
    }

    for (int i = 1; i < n; ++i) {
        dp[i][0] += dp[i-1][0];
        for (int j = 1; j < i; ++j) {
            dp[i][j] += max(dp[i-1][j-1], dp[i-1][j]);
        }
        dp[i].back() += dp[i-1].back();
    }
    
    cout << *max_element(dp[n-1].cbegin(), dp[n-1].cend());
    return 0;
}

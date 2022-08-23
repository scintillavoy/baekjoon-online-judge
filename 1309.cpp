#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> dp(N, vector<int>(3));
    
    dp[0] = {1, 1, 1};
    for (int i = 1; i < N; ++i) {
        dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % 9901;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % 9901;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1]) % 9901;
    }

    cout << (dp.back()[0] + dp.back()[1] + dp.back()[2]) % 9901;
    return 0;
}

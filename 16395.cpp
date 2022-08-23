#include <iostream>
#include <vector>
using namespace std;

long long choose(int n, int k, vector<vector<long long>> &dp) {
    if (dp[n][k] > 0) {
        return dp[n][k];
    } else if (k == 0 || n == k) {
        return dp[n][k] = 1;
    } else {
        return dp[n][k] = choose(n-1, k-1, dp) + choose(n-1, k, dp);
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<long long>> dp(n, vector<long long>(k, 0));
    cout << choose(n-1, k-1, dp) << '\n';
    return 0;
}

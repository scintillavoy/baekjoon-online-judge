#include <algorithm>
#include <iostream>
using namespace std;

int dp[101][101][2];

int solve(int n, int k, int last) {
  if (n < 0 || k < 0) {
    return 0;
  }
  if (dp[n][k][last] != -1) {
    return dp[n][k][last];
  }
  if (last == 0) {
    return dp[n][k][last] = solve(n - 1, k, 0) + solve(n - 1, k, 1);
  }
  return dp[n][k][last] = solve(n - 1, k, 0) + solve(n - 1, k - 1, 1);
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  fill_n(&dp[0][0][0], sizeof(dp) / sizeof(dp[0][0][0]), -1);
  dp[1][0][0] = 1;
  dp[1][0][1] = 1;
  while (T--) {
    int n, k;
    cin >> n >> k;
    cout << solve(n, k, 0) + solve(n, k, 1) << '\n';
  }
  return 0;
}

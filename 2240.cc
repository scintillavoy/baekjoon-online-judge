#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int main() {
  int T, W;
  cin >> T >> W;
  vector<vector<int>> dp(W + 1, vector<int>(2, numeric_limits<int>::min()));
  dp[0][0] = 0;
  for (int i = 1; i <= T; ++i) {
    int number;
    cin >> number;
    for (int j = W; j > 0; --j) {
      dp[j][number - 1] = max(dp[j][number - 1], dp[j - 1][number % 2]) + 1;
    }
    dp[0][number - 1] = dp[0][number - 1] + 1;
  }
  int max_count = 0;
  for (int i = 0; i <= W; ++i) {
    for (int j = 0; j < 2; ++j) {
      max_count = max(max_count, dp[i][j]);
    }
  }
  cout << max_count;
  return 0;
}

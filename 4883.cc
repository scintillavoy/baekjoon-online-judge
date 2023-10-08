#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int main() {
  for (int t = 1; true; ++t) {
    int N;
    cin >> N;
    if (N == 0) {
      break;
    }
    vector<vector<int>> costs(N, vector<int>(3));
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < 3; ++j) {
        cin >> costs[i][j];
      }
    }
    vector<vector<int>> dp(N, vector<int>(3, numeric_limits<int>::max()));
    dp[0][1] = costs[0][1];
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (dp[i][j] == numeric_limits<int>::max()) {
          continue;
        }
        if (j + 1 < 3) {
          dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + costs[i][j + 1]);
        }
        if (i + 1 < N) {
          if (j - 1 >= 0) {
            dp[i + 1][j - 1] =
                min(dp[i + 1][j - 1], dp[i][j] + costs[i + 1][j - 1]);
          }
          dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + costs[i + 1][j]);
          if (j + 1 < 3) {
            dp[i + 1][j + 1] =
                min(dp[i + 1][j + 1], dp[i][j] + costs[i + 1][j + 1]);
          }
        }
      }
    }
    cout << t << ". " << dp.back()[1] << '\n';
  }
  return 0;
}

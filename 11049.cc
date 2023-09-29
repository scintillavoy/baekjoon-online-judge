#include <algorithm>
#include <iostream>
#include <limits>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<pair<int, int>> vec(N);
  for (auto &x : vec) {
    cin >> x.first >> x.second;
  }
  vector<vector<int>> dp(N, vector<int>(N, numeric_limits<int>::max()));
  for (int i = 0; i < N; ++i) {
    dp[i][i] = 0;
  }
  for (int i = 2; i <= N; ++i) {
    for (int j = 0; j + i - 1 < N; ++j) {
      for (int k = 0; j + k + 1 <= j + i - 1; ++k) {
        dp[j][j + i - 1] =
            min(dp[j][j + i - 1],
                dp[j][j + k] + dp[j + k + 1][j + i - 1] +
                    vec[j].first * vec[j + k].second * vec[j + i - 1].second);
      }
    }
  }
  cout << dp[0][N - 1];
  return 0;
}

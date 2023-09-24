#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int>> costs(N, vector<int>(3));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> costs[i][j];
    }
  }
  vector<vector<int>> dp(N, vector<int>(3));
  int min_cost = numeric_limits<int>::max();
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (i == j) {
        dp[0][j] = costs[0][i];
      } else {
        dp[0][j] = numeric_limits<int>::max() - 1000;
      }
    }
    for (int j = 1; j < N; ++j) {
      dp[j][0] = min(dp[j - 1][1], dp[j - 1][2]) + costs[j][0];
      dp[j][1] = min(dp[j - 1][2], dp[j - 1][0]) + costs[j][1];
      dp[j][2] = min(dp[j - 1][0], dp[j - 1][1]) + costs[j][2];
    }
    for (int j = 0; j < 3; ++j) {
      if (i == j) {
        continue;
      }
      min_cost = min(min_cost, dp[N - 1][j]);
    }
  }
  cout << min_cost;
  return 0;
}

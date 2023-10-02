#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int>> vec(N, vector<int>(N));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> vec[i][j];
    }
  }
  vector<vector<long long>> dp(N, vector<long long>(N));
  dp[0][0] = 1;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (vec[i][j] == 0 || dp[i][j] == 0) {
        continue;
      }
      if (i + vec[i][j] < N) {
        dp[i + vec[i][j]][j] += dp[i][j];
      }
      if (j + vec[i][j] < N) {
        dp[i][j + vec[i][j]] += dp[i][j];
      }
    }
  }
  cout << dp.back().back();
  return 0;
}

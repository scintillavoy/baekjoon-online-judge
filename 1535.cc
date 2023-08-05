#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> L(N), J(N);
  for (auto &x : L) {
    cin >> x;
  }
  for (auto &x : J) {
    cin >> x;
  }
  vector<vector<int>> dp(N, vector<int>(101));
  if (100 - L[0] > 0) {
    dp[0][100 - L[0]] = J[0];
  }
  for (int i = 1; i < N; ++i) {
    for (int j = 1; j <= 100; ++j) {
      if (j + L[i] <= 100) {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j + L[i]] + J[i]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  cout << *max_element(dp[N - 1].cbegin(), dp[N - 1].cend());
  return 0;
}

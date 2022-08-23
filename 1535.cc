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
  // dp[i][j] = max(dp[i][j], dp[i-1][j])
  // dp[i][j-L[i]] = dp[i-1][j] + J[i]
  // i from 0 to N-1
  // j from 100 to 0
  // dp[0][100] = 0
  // dp[0][100-L[0]] = J[0]
  // dp[1][100] = dp[0][100]
  // dp[1][100-L[1]] = dp[0][100] + J[1]
  // dp[1][99] = dp[0][99]
  // dp[1][99-L[1]] = dp[0][99] + J[1]
  return 0;
}

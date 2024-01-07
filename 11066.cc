#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int K;
    cin >> K;
    vector<int> sum(K + 1);
    vector<vector<int>> dp(K + 1,
                           vector<int>(K + 1, numeric_limits<int>::max()));
    for (int i = 1; i <= K; ++i) {
      cin >> sum[i];
      sum[i] += sum[i - 1];
      dp[i][i] = 0;
    }
    for (int l = 1; l < K; ++l) {
      for (int i = 1; i + l <= K; ++i) {
        int k = i + l;
        for (int j = i; j < k; ++j) {
          dp[i][k] =
              min(dp[i][k], dp[i][j] + dp[j + 1][k] + sum[k] - sum[i - 1]);
        }
      }
    }
    cout << dp[1][K] << '\n';
  }
  return 0;
}

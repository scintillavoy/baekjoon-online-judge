#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int A, K;
  cin >> A >> K;
  vector<int> dp(K + 1, numeric_limits<int>::max());
  dp[A] = 0;
  for (int i = A; i < K; ++i) {
    dp[i + 1] = min(dp[i + 1], dp[i] + 1);
    if (i * 2 <= K) {
      dp[i * 2] = min(dp[i * 2], dp[i] + 1);
    }
  }
  cout << dp[K];
  return 0;
}

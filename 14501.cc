#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> T(N + 1), P(N + 1);
  for (int i = 1; i <= N; ++i) {
    cin >> T[i] >> P[i];
  }

  vector<int> dp(N + 2);
  for (int i = 1; i <= N + 1; ++i) {
    dp[i] = max(dp[i], dp[i - 1]);
    if (i + T[i] <= N + 1) {
      dp[i + T[i]] = max(dp[i + T[i]], dp[i] + P[i]);
    }
  }

  cout << dp.back();
  return 0;
}

#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> dp(N + 1, numeric_limits<int>::max());
  dp[1] = 0;
  for (int i = 2; i <= N; ++i) {
    if (i % 3 == 0) {
      dp[i] = min(dp[i], dp[i / 3] + 1);
    }
    if (i % 2 == 0) {
      dp[i] = min(dp[i], dp[i / 2] + 1);
    }
    dp[i] = min(dp[i], dp[i - 1] + 1);
  }
  cout << dp[N] << '\n';
  int curr = N;
  while (curr >= 1) {
    cout << curr << ' ';
    if (curr % 3 == 0 && dp[curr] - 1 == dp[curr / 3]) {
      curr /= 3;
    } else if (curr % 2 == 0 && dp[curr] - 1 == dp[curr / 2]) {
      curr /= 2;
    } else {
      --curr;
    }
  }
  return 0;
}

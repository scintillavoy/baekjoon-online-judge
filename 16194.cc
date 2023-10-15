#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> P(N + 1);
  for (int i = 1; i <= N; ++i) {
    cin >> P[i];
  }
  vector<int> dp(N + 1, numeric_limits<int>::max());
  dp[0] = 0;
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= i; ++j) {
      dp[i] = min(dp[i], dp[i - j] + P[j]);
    }
  }
  cout << dp[N];
  return 0;
}

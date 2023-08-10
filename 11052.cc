#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> P(N + 1);
  vector<int> dp(N + 1);
  for (int i = 1; i <= N; ++i) {
    cin >> P[i];
    dp[i] = P[i];
    for (int j = 1; j < i; ++j) {
      dp[i] = max(dp[i], P[i - j] + dp[j]);
    }
  }
  cout << dp[N];
  return 0;
}

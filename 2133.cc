#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> dp(N + 1);
  dp[0] = 1;
  if (N >= 2) {
    dp[2] = 3;
  }
  for (int i = 4; i <= N; i += 2) {
    dp[i] = dp[i - 2] * 3;
    for (int j = i - 4; j >= 0; j -= 2) {
      dp[i] += dp[j] * 2;
    }
  }
  cout << dp[N];
  return 0;
}

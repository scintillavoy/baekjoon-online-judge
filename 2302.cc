#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<bool> vips(N + 1);
  for (int i = 0; i < M; ++i) {
    int vip;
    cin >> vip;
    vips[vip] = true;
  }
  vector<vector<int>> dp(N + 1, vector<int>(3));
  dp[0][1] = 1;
  for (int i = 1; i <= N; ++i) {
    dp[i][0] = (vips[i] ? 0 : dp[i - 1][2]);
    dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
    dp[i][2] = (vips[i] ? 0 : dp[i - 1][0] + dp[i - 1][1]);
  }
  cout << dp.back()[0] + dp.back()[1];
  return 0;
}

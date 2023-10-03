#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, S, M;
  cin >> N >> S >> M;
  vector<int> V(N + 1);
  for (int i = 1; i <= N; ++i) {
    cin >> V[i];
  }
  vector<vector<bool>> dp(N + 1, vector<bool>(M + 1));
  dp[0][S] = true;
  for (int i = 1; i <= N; ++i) {
    for (int j = 0; j <= M; ++j) {
      if (!dp[i - 1][j]) {
        continue;
      }
      if (j - V[i] >= 0) {
        dp[i][j - V[i]] = true;
      }
      if (j + V[i] <= M) {
        dp[i][j + V[i]] = true;
      }
    }
  }
  for (int i = M; i >= 0; --i) {
    if (dp.back()[i]) {
      cout << i;
      return 0;
    }
  }
  cout << -1;
  return 0;
}

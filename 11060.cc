#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N + 1);
  for (int i = 1; i <= N; ++i) {
    cin >> A[i];
  }
  vector<int> dp(N + 1, numeric_limits<int>::max());
  dp[1] = 0;
  for (int i = 1; i <= N; ++i) {
    if (dp[i] == numeric_limits<int>::max()) {
      continue;
    }
    for (int j = 1; j <= A[i]; ++j) {
      if (i + j > N) {
        continue;
      }
      dp[i + j] = min(dp[i + j], dp[i] + 1);
    }
  }
  cout << (dp[N] == numeric_limits<int>::max() ? -1 : dp[N]);
  return 0;
}

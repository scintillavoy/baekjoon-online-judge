#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> m(N), c(N);
  for (auto &x : m) {
    cin >> x;
  }
  for (auto &x : c) {
    cin >> x;
  }
  vector<int> dp(N * 100 + 1);
  for (int i = 0; i < N; ++i) {
    for (int j = dp.size() - 1; j - c[i] >= 0; --j) {
      dp[j] = max(dp[j], dp[j - c[i]] + m[i]);
    }
  }
  cout << lower_bound(dp.cbegin(), dp.cend(), M) - dp.cbegin();
  return 0;
}

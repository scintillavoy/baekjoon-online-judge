#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> values(n);
  for (int i = 0; i < n; ++i) {
    cin >> values[i];
  }
  vector<int> dp(k + 1);
  dp[0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= k; ++j) {
      if (j + values[i] > k) {
        continue;
      }
      dp[j + values[i]] += dp[j];
    }
  }
  cout << dp[k];
  return 0;
}

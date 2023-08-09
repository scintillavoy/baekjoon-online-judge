#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> vec(n);
  for (auto &x : vec) {
    cin >> x;
  }
  vector<vector<int>> dp(n, vector<int>(3, 0));
  dp[0] = {0, vec[0], 0};
  for (int i = 1; i < n; ++i) {
    dp[i] = {
        *max_element(dp[i - 1].cbegin(), dp[i - 1].cend()),
        dp[i - 1][0] + vec[i],
        dp[i - 1][1] + vec[i],
    };
  }
  cout << *max_element(dp[n - 1].cbegin(), dp[n - 1].cend());
  return 0;
}

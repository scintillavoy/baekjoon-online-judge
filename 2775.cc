#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dp(15, vector<int>(15, -1));

int calculate(int k, int n) {
  if (dp[k][n] != -1) return dp[k][n];
  return dp[k][n] = calculate(k, n - 1) + calculate(k - 1, n);
}

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < dp.size(); ++i) {
    dp[i][0] = 0;
    dp[i][1] = 1;
  }
  for (int i = 1; i < dp[0].size(); ++i) {
    dp[0][i] = i;
  }
  while (T--) {
    int k, n;
    cin >> k >> n;
    cout << calculate(k, n) << '\n';
  }
  return 0;
}

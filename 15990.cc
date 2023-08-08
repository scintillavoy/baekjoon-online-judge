#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dp;

int calculate(int n, int m) {
  if (dp[n][m] != -1) {
    return dp[n][m];
  }
  return dp[n][m] = ((long long)calculate(n - m - 1, (m + 1) % 3) +
                     calculate(n - m - 1, (m + 2) % 3)) %
                    1'000'000'009;
}

int main() {
  int T;
  cin >> T;
  dp = vector<vector<int>>(100001, vector<int>(3, -1));
  dp[1] = {1, 0, 0};
  dp[2] = {0, 1, 0};
  dp[3] = {1, 1, 1};
  while (T--) {
    int n;
    cin >> n;
    cout << ((long long)calculate(n, 0) + calculate(n, 1) + calculate(n, 2)) %
                1'000'000'009
         << '\n';
  }
  return 0;
}

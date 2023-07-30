#include <iostream>
#include <vector>
using namespace std;

vector<long long> dp(1'000'001, -1);

long long solve(int n) {
  if (dp[n] != -1) return dp[n];
  return dp[n] = (solve(n - 1) + solve(n - 2) + solve(n - 3)) % 1'000'000'009;
}

int main() {
  int T;
  cin >> T;
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;
  while (T--) {
    int n;
    cin >> n;
    cout << solve(n) << '\n';
  }
  return 0;
}

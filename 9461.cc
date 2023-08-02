#include <iostream>
#include <vector>
using namespace std;

vector<long long> dp(101, -1);

long long solve(int N) {
  if (dp[N] != -1) {
    return dp[N];
  }
  return dp[N] = solve(N - 2) + solve(N - 3);
}

int main() {
  dp[1] = 1;
  dp[2] = 1;
  dp[3] = 1;
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    cout << solve(N) << '\n';
  }
  return 0;
}

#include <iostream>
#include <vector>
using namespace std;

#define MOD 10'007

vector<vector<int>> dp;

int calculate(int N, int K) {
  if (dp[N][K] != 0) {
    return dp[N][K];
  }
  if (K == 0 || K == N) {
    return dp[N][K] = 1;
  }
  return dp[N][K] = (calculate(N - 1, K - 1) + calculate(N - 1, K)) % MOD;
}

int main() {
  int N, K;
  cin >> N >> K;
  dp = vector<vector<int>>(N + 1, vector<int>(N + 1));
  cout << calculate(N, K);
  return 0;
}

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dp;

int solve(int N, int M) {
  if (dp[N][M] != 0) {
    return dp[N][M];
  }
  if (N == 1) {
    return dp[N][M] = solve(N, M - 1);
  }
  if (M == 1) {
    return dp[N][M] = solve(N - 1, M);
  }
  return dp[N][M] = solve(N, M - 1) + solve(N - 1, M);
}

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  dp = vector<vector<int>>(N + 1, vector<int>(M + 1));
  dp[1][1] = 1;
  if (K == 0) {
    cout << solve(N, M);
  } else {
    int x = (K - 1) / M + 1, y = (K - 1) % M + 1;
    cout << solve(x, y) * solve(N - x + 1, M - y + 1);
  }
  return 0;
}

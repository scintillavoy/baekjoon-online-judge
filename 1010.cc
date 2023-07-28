#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dp(31, vector<int>(31, -1));

int combination(int N, int M) {
  if (N < M) return 0;
  if (N == M || M == 0) return 1;
  if (dp[N][M] != -1) return dp[N][M];
  return dp[N][M] = combination(N - 1, M - 1) + combination(N - 1, M);
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N, M;
    cin >> N >> M;
    cout << combination(M, N) << endl;
  }
  return 0;
}

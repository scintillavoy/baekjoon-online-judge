#include <iostream>
#include <vector>
using namespace std;

vector<int> vec;
vector<vector<int>> dp;

int solve(int S, int E) {
  if (S > E) {
    return 1;
  }
  if (dp[S][E] != -1) {
    return dp[S][E];
  }
  if (S == E) {
    return dp[S][E] = 1;
  }
  if (vec[S] != vec[E]) {
    return dp[S][E] = 0;
  }
  return dp[S][E] = solve(S + 1, E - 1);
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  vec = vector<int>(N + 1);
  dp = vector<vector<int>>(N + 1, vector<int>(N + 1, -1));
  for (int i = 1; i <= N; ++i) {
    cin >> vec[i];
  }
  int M;
  cin >> M;
  for (int i = 0; i < M; ++i) {
    int S, E;
    cin >> S >> E;
    cout << solve(S, E) << '\n';
  }
  return 0;
}

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> vec;
vector<vector<int>> dp;

int solve(int start, int end) {
  if (start > end) {
    return 0;
  }
  if (dp[start][end] != -1) {
    return dp[start][end];
  }
  if (vec[start] == vec[end]) {
    return dp[start][end] = solve(start + 1, end - 1);
  }
  int left = solve(start + 1, end) + 1;
  int right = solve(start, end - 1) + 1;
  return dp[start][end] = min(left, right);
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  vec = vector<int>(N);
  for (int i = 0; i < N; ++i) {
    cin >> vec[i];
  }
  dp = vector<vector<int>>(N, vector<int>(N, -1));
  cout << solve(0, N - 1);
  return 0;
}

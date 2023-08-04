#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N + 1);
  for (int i = 1; i <= N; ++i) {
    cin >> A[i];
  }
  vector<long long> dp(N + 1, numeric_limits<long long>::max());
  dp[1] = 0;
  for (int i = 2; i <= N; ++i) {
    for (int j = 1; j < i; ++j) {
      dp[i] =
          min(dp[i], max(dp[j], (long long)(i - j) * (1 + abs(A[j] - A[i]))));
    }
  }
  cout << dp[N];
  return 0;
}

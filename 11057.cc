#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int>> dp(N, vector<int>(10));
  for (int i = 0; i < 10; ++i) {
    dp[0][i] = 1;
  }
  for (int i = 1; i < N; ++i) {
    for (int j = 0; j < 10; ++j) {
      for (int k = j; k >= 0; --k) {
        dp[i][j] = (dp[i][j] + dp[i - 1][k]) % 10007;
      }
    }
  }
  int sum = 0;
  for (int i = 0; i < 10; ++i) {
    sum = (sum + dp.back()[i]) % 10007;
  }
  cout << sum;
  return 0;
}

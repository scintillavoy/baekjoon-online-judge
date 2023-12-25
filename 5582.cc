#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  string A, B;
  cin >> A >> B;
  vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1));
  int max_length = 0;
  for (int i = 1; i <= A.size(); ++i) {
    for (int j = 1; j <= B.size(); ++j) {
      if (A[i - 1] == B[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        max_length = max(max_length, dp[i][j]);
      }
    }
  }
  cout << max_length;
  return 0;
}

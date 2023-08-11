#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<vector<int>> vec(2, vector<int>(n));
    for (auto &row : vec) {
      for (auto &x : row) {
        cin >> x;
      }
    }
    vector<int> dp{vec[0][0], vec[1][0], 0};
    for (int i = 1; i < n; ++i) {
      dp = {
          vec[0][i] + max(dp[1], dp[2]),
          vec[1][i] + max(dp[0], dp[2]),
          *max_element(dp.cbegin(), dp.cend()),
      };
    }
    cout << *max_element(dp.cbegin(), dp.cend()) << '\n';
  }
  return 0;
}

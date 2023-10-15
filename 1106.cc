#include <algorithm>
#include <iostream>
#include <limits>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int C, N;
  cin >> C >> N;
  vector<int> costs(N), values(N);
  for (int i = 0; i < N; ++i) {
    cin >> costs[i] >> values[i];
  }
  vector<int> dp(C + 100 + 1, numeric_limits<int>::max());
  dp[0] = 0;
  for (int i = 1; i < dp.size(); ++i) {
    for (int j = 0; j < N; ++j) {
      if (i - values[j] < 0 ||
          dp[i - values[j]] == numeric_limits<int>::max()) {
        continue;
      }
      dp[i] = min(dp[i], dp[i - values[j]] + costs[j]);
    }
  }
  cout << *min_element(dp.cbegin() + C, dp.cend());
  return 0;
}

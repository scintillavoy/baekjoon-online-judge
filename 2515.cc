#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, S;
  cin >> N >> S;
  vector<pair<int, int>> pictures(N);
  for (int i = 0; i < N; ++i) {
    cin >> pictures[i].first >> pictures[i].second;
  }
  sort(pictures.begin(), pictures.end());
  vector<int> dp(N);
  dp[0] = pictures[0].second;
  for (int i = 1; i < N; ++i) {
    auto it = upper_bound(pictures.cbegin(), pictures.cbegin() + i,
                          pictures[i].first - S,
                          [](int height, pair<int, int> picture) {
                            return height < picture.first;
                          });
    if (it == pictures.cbegin()) {
      dp[i] = max(dp[i - 1], pictures[i].second);
    } else {
      dp[i] = max(dp[i - 1],
                  dp[distance(pictures.cbegin(), it) - 1] + pictures[i].second);
    }
  }
  cout << dp.back();
  return 0;
}

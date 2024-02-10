#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<tuple<int, int, int, int>> blocks(N);
  for (int i = 0; i < N; ++i) {
    int area, height, weight;
    cin >> area >> height >> weight;
    blocks[i] = {area, height, weight, i + 1};
  }
  sort(blocks.begin(), blocks.end());
  vector<int> dp(N);
  for (int i = 0; i < N; ++i) {
    dp[i] = get<1>(blocks[i]);
  }
  for (int i = 1; i < N; ++i) {
    for (int j = 0; j < i; ++j) {
      if (get<2>(blocks[i]) > get<2>(blocks[j])) {
        dp[i] = max(dp[i], dp[j] + get<1>(blocks[i]));
      }
    }
  }
  int max_height = *max_element(dp.cbegin(), dp.cend());
  vector<int> answer;
  for (int i = N - 1; i >= 0; --i) {
    if (dp[i] == max_height) {
      answer.push_back(get<3>(blocks[i]));
      max_height -= get<1>(blocks[i]);
    }
  }
  cout << answer.size() << '\n';
  for (auto it = answer.rbegin(); it != answer.rend(); ++it) {
    cout << *it << '\n';
  }
  return 0;
}

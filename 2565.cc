#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<pair<int, int>> lines(N);
  for (int i = 0; i < N; ++i) {
    cin >> lines[i].first >> lines[i].second;
  }
  sort(lines.begin(), lines.end());
  vector<int> dp;
  dp.push_back(lines[0].second);
  for (int i = 1; i < N; ++i) {
    if (dp.back() < lines[i].second) {
      dp.push_back(lines[i].second);
    } else {
      auto it = lower_bound(dp.begin(), dp.end(), lines[i].second);
      *it = lines[i].second;
    }
  }
  cout << lines.size() - dp.size();
  return 0;
}

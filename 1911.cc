#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, L;
  cin >> N >> L;
  vector<pair<int, int>> puddles(N);
  for (int i = 0; i < N; ++i) {
    cin >> puddles[i].first >> puddles[i].second;
  }
  sort(puddles.begin(), puddles.end());
  int total_count = 1;
  int last_covered = puddles[0].first + L;
  for (int i = 0; i < puddles.size(); ++i) {
    if (last_covered < puddles[i].first) {
      last_covered = puddles[i].first;
    }
    if (last_covered < puddles[i].second) {
      int count = (puddles[i].second - last_covered) / L;
      if ((puddles[i].second - last_covered) % L != 0) {
        ++count;
      }
      total_count += count;
      last_covered += count * L;
    }
  }
  cout << total_count;
  return 0;
}

#include <algorithm>
#include <functional>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  vector<pair<int, int>> positions;
  for (int i = 0; i < N; ++i) {
    int from, to;
    cin >> from >> to;
    if (from > to) {
      positions.push_back({from, to});
    }
  }
  long long total_distance = M;
  if (positions.size() > 0) {
    sort(positions.begin(), positions.end(), greater<pair<int, int>>());
    int backwards = 0;
    int last_position = M + 1;
    for (int i = 0; i < N; ++i) {
      if (positions[i].first <= last_position) {
        backwards += positions[i].first - positions[i].second;
      } else {
        backwards += max(0, last_position - positions[i].second);
      }
      last_position = min(last_position, positions[i].second);
    }
    total_distance += backwards * 2;
  }
  cout << total_distance;
  return 0;
}

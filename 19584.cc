#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  vector<int> places(N + 1);
  for (int i = 1; i <= N; ++i) {
    int x, y;
    cin >> x >> y;
    places[i] = y;
  }
  vector<pair<int, int>> roads;
  for (int i = 0; i < M; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    int y1 = places[u];
    int y2 = places[v];
    if (y1 > y2) {
      swap(y1, y2);
    }
    roads.push_back({y1, -c});
    roads.push_back({y2, c});
  }
  sort(roads.begin(), roads.end());
  long long max_value = 0;
  long long current_value = 0;
  for (int i = 0; i < roads.size(); ++i) {
    current_value -= roads[i].second;
    max_value = max(max_value, current_value);
  }
  cout << max_value;
  return 0;
}

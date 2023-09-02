#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, d, c;
    cin >> n >> d >> c;
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < d; ++i) {
      int a, b, s;
      cin >> a >> b >> s;
      graph[b].push_back({s, a});
    }
    vector<int> distance_(n + 1, numeric_limits<int>::max());
    distance_[c] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    pq.push({0, c});
    while (!pq.empty()) {
      auto [curr_distance, curr] = pq.top();
      pq.pop();
      if (distance_[curr] < curr_distance) {
        continue;
      }
      for (const auto& [adj_weight, adj] : graph[curr]) {
        if (distance_[adj] > curr_distance + adj_weight) {
          distance_[adj] = curr_distance + adj_weight;
          pq.push({distance_[adj], adj});
        }
      }
    }
    int count = 0;
    int max_distance = 0;
    for (int i = 1; i <= n; ++i) {
      if (distance_[i] == numeric_limits<int>::max()) {
        continue;
      }
      ++count;
      max_distance = max(max_distance, distance_[i]);
    }
    cout << count << ' ' << max_distance << '\n';
  }
  return 0;
}

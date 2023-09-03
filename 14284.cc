#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> graph(n + 1);
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    graph[a].push_back({c, b});
    graph[b].push_back({c, a});
  }
  int s, t;
  cin >> s >> t;
  vector<int> distance_(n + 1, numeric_limits<int>::max());
  distance_[s] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push({0, s});
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
  cout << distance_[t];
  return 0;
}

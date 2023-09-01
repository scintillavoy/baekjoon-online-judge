#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int V, E;
  cin >> V >> E;
  vector<vector<pair<int, int>>> graph(V + 1);
  int K;
  cin >> K;
  for (int i = 0; i < E; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    graph[u].push_back({w, v});
  }
  vector<int> distance_(V + 1, numeric_limits<int>::max());
  distance_[K] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push({0, K});
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
  for (int i = 1; i <= V; ++i) {
    if (distance_[i] == numeric_limits<int>::max()) {
      cout << "INF";
    } else {
      cout << distance_[i];
    }
    cout << '\n';
  }
  return 0;
}

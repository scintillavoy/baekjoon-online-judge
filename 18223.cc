#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

vector<vector<pair<int, int>>> graph;

vector<int> dijkstra(int source) {
  vector<int> distance_(graph.size(), numeric_limits<int>::max());
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  distance_[source] = 0;
  pq.push({0, source});
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
  return distance_;
}

int main() {
  int V, E, P;
  cin >> V >> E >> P;
  graph = vector<vector<pair<int, int>>>(V + 1);
  for (int i = 0; i < E; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    graph[a].push_back({c, b});
    graph[b].push_back({c, a});
  }
  vector<int> distance_from_1 = dijkstra(1);
  vector<int> distance_from_P = dijkstra(P);
  if (distance_from_1[V] == distance_from_1[P] + distance_from_P[V]) {
    cout << "SAVE HIM";
  } else {
    cout << "GOOD BYE";
  }
  cout << '\n';
  return 0;
}

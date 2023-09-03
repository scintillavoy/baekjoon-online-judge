#include <algorithm>
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
  distance_[source] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
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
  int N, E;
  cin >> N >> E;
  graph = vector<vector<pair<int, int>>>(N + 1);
  for (int i = 0; i < E; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    graph[a].push_back({c, b});
    graph[b].push_back({c, a});
  }
  int v1, v2;
  cin >> v1 >> v2;
  vector<int> distance_from_1 = dijkstra(1);
  vector<int> distance_from_v1 = dijkstra(v1);
  vector<int> distance_from_v2 = dijkstra(v2);
  int distance_1_v1_v2_N = numeric_limits<int>::max();
  int distance_1_v2_v1_N = numeric_limits<int>::max();
  if (distance_from_1[v1] != numeric_limits<int>::max() &&
      distance_from_v1[v2] != numeric_limits<int>::max() &&
      distance_from_v2[N] != numeric_limits<int>::max()) {
    distance_1_v1_v2_N =
        distance_from_1[v1] + distance_from_v1[v2] + distance_from_v2[N];
  }
  if (distance_from_1[v2] != numeric_limits<int>::max() &&
      distance_from_v2[v1] != numeric_limits<int>::max() &&
      distance_from_v1[N] != numeric_limits<int>::max()) {
    distance_1_v2_v1_N =
        distance_from_1[v2] + distance_from_v2[v1] + distance_from_v1[N];
  }
  if (distance_1_v1_v2_N == numeric_limits<int>::max() &&
      distance_1_v2_v1_N == numeric_limits<int>::max()) {
    cout << -1;
  } else {
    cout << min(distance_1_v1_v2_N, distance_1_v2_v1_N);
  }
  return 0;
}

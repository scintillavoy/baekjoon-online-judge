#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int N, M, X;

vector<int> dijkstra(vector<vector<pair<int, int>>>& graph) {
  vector<int> distance_(N + 1, numeric_limits<int>::max());
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  distance_[X] = 0;
  pq.push({0, X});
  while (!pq.empty()) {
    auto [curr_distance, curr] = pq.top();
    pq.pop();
    if (distance_[curr] < curr_distance) {
      continue;
    }
    for (const auto& [adj_weight, adj] : graph[curr]) {
      if (distance_[adj] > distance_[curr] + adj_weight) {
        distance_[adj] = distance_[curr] + adj_weight;
        pq.push({adj_weight, adj});
      }
    }
  }
  return distance_;
}

int main() {
  cin >> N >> M >> X;
  vector<vector<pair<int, int>>> graph(N + 1), graph_reversed(N + 1);
  for (int i = 0; i < M; ++i) {
    int from, to, weight;
    cin >> from >> to >> weight;
    graph[from].push_back({weight, to});
    graph_reversed[to].push_back({weight, from});
  }
  vector<int> distance_ = dijkstra(graph);
  vector<int> distance_reversed = dijkstra(graph_reversed);
  int max_distance = numeric_limits<int>::min();
  for (int i = 1; i <= N; ++i) {
    max_distance = max(max_distance, distance_[i] + distance_reversed[i]);
  }
  cout << max_distance;
  return 0;
}

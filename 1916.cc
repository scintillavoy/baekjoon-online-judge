#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<pair<int, int>>> graph(N + 1);
  for (int i = 0; i < M; ++i) {
    int from, to, weight;
    cin >> from >> to >> weight;
    graph[from].push_back({weight, to});
  }
  int source, destination;
  cin >> source >> destination;
  vector<int> distance_(N + 1, numeric_limits<int>::max());
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
  cout << distance_[destination];
  return 0;
}

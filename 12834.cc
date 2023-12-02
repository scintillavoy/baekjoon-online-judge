#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int N, V, E;
int A, B;
vector<vector<pair<int, int>>> graph;

vector<int> dijkstra(int source) {
  vector<int> distances(V + 1, numeric_limits<int>::max());
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  distances[source] = 0;
  pq.push({0, source});
  while (!pq.empty()) {
    auto [curr_distance, curr] = pq.top();
    pq.pop();
    if (distances[curr] < curr_distance) {
      continue;
    }
    for (const auto& [adj_weight, adj] : graph[curr]) {
      if (distances[adj] > distances[curr] + adj_weight) {
        distances[adj] = distances[curr] + adj_weight;
        pq.push({distances[adj], adj});
      }
    }
  }
  return distances;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cin >> N >> V >> E;
  cin >> A >> B;
  vector<int> H(N);
  for (int i = 0; i < N; ++i) {
    cin >> H[i];
  }
  graph = vector<vector<pair<int, int>>>(V + 1);
  for (int i = 0; i < E; ++i) {
    int from, to, weight;
    cin >> from >> to >> weight;
    graph[from].push_back({weight, to});
    graph[to].push_back({weight, from});
  }
  int total_distances = 0;
  for (int i = 0; i < N; ++i) {
    vector<int> distances = dijkstra(H[i]);
    total_distances +=
        (distances[A] == numeric_limits<int>::max() ? -1 : distances[A]);
    total_distances +=
        (distances[B] == numeric_limits<int>::max() ? -1 : distances[B]);
  }
  cout << total_distances;
  return 0;
}

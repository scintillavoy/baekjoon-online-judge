#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int S, D;
vector<vector<pair<int, int>>> graph;
vector<vector<int>> parents;
vector<bool> deleted;

void deleteEdges(int curr) {
  deleted[curr] = true;
  for (const auto& parent : parents[curr]) {
    for (auto& adj : graph[parent]) {
      if (adj.second == curr) {
        adj.first = -1;
        break;
      }
    }
    if (!deleted[parent]) {
      deleteEdges(parent);
    }
  }
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  while (true) {
    int N, M;
    cin >> N >> M;
    if (N == 0 && M == 0) {
      break;
    }
    graph = vector<vector<pair<int, int>>>(N);
    cin >> S >> D;
    for (int i = 0; i < M; ++i) {
      int U, V, P;
      cin >> U >> V >> P;
      graph[U].push_back({P, V});
    }
    vector<int> distances(N, numeric_limits<int>::max());
    parents = vector<vector<int>>(N);
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    distances[S] = 0;
    pq.push({0, S});
    while (!pq.empty()) {
      auto [curr_distance, curr] = pq.top();
      pq.pop();
      if (distances[curr] < curr_distance) {
        continue;
      }
      for (const auto& [adj_weight, adj] : graph[curr]) {
        int next_distance = distances[curr] + adj_weight;
        if (distances[adj] > next_distance) {
          distances[adj] = next_distance;
          parents[adj] = {curr};
          pq.push({distances[adj], adj});
        } else if (distances[adj] == next_distance) {
          parents[adj].push_back(curr);
        }
      }
    }
    deleted = vector<bool>(N);
    deleteEdges(D);
    distances = vector<int>(N, numeric_limits<int>::max());
    distances[S] = 0;
    pq.push({0, S});
    while (!pq.empty()) {
      auto [curr_distance, curr] = pq.top();
      pq.pop();
      if (distances[curr] < curr_distance) {
        continue;
      }
      for (const auto& [adj_weight, adj] : graph[curr]) {
        if (adj_weight == -1) {
          continue;
        }
        int next_distance = distances[curr] + adj_weight;
        if (distances[adj] > next_distance) {
          distances[adj] = next_distance;
          pq.push({distances[adj], adj});
        }
      }
    }
    cout << (distances[D] == numeric_limits<int>::max() ? -1 : distances[D])
         << '\n';
  }
  return 0;
}

#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<pair<int, int>>> graph(N + 1);
  for (int i = 0; i < M; ++i) {
    int A, B, C;
    cin >> A >> B >> C;
    graph[A].push_back({C, B});
    graph[B].push_back({C, A});
  }
  vector<int> distance_(N + 1, numeric_limits<int>::max());
  distance_[1] = 0;
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                 greater<tuple<int, int, int>>>
      pq;
  pq.push({0, 1, -1});
  vector<pair<int, int>> edges;
  while (!pq.empty()) {
    auto [curr_distance, curr, parent] = pq.top();
    pq.pop();
    if (distance_[curr] < curr_distance) {
      continue;
    }
    edges.push_back({curr, parent});
    for (const auto& [adj_weight, adj] : graph[curr]) {
      if (distance_[adj] > distance_[curr] + adj_weight) {
        distance_[adj] = distance_[curr] + adj_weight;
        pq.push({distance_[adj], adj, curr});
      }
    }
  }
  cout << edges.size() - 1 << '\n';
  for (int i = 1; i < edges.size(); ++i) {
    cout << edges[i].first << ' ' << edges[i].second << '\n';
  }
  return 0;
}

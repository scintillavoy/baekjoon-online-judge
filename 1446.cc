#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int N, D;
  cin >> N >> D;
  vector<vector<pair<int, int>>> graph(D + 1);
  for (int i = 0; i < D; ++i) {
    graph[i].push_back({1, i + 1});
  }
  for (int i = 0; i < N; ++i) {
    int from, to, weight;
    cin >> from >> to >> weight;
    if (from > D || to > D) {
      continue;
    }
    graph[from].push_back({weight, to});
  }
  vector<int> distance_(D + 1, numeric_limits<int>::max());
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  distance_[0] = 0;
  pq.push({0, 0});
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
  cout << distance_[D];
  return 0;
}

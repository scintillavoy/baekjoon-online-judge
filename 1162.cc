#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, M, K;
  cin >> N >> M >> K;
  vector<vector<pair<int, int>>> graph(N + 1);
  for (int i = 0; i < M; ++i) {
    int from, to, weight;
    cin >> from >> to >> weight;
    graph[from].push_back({weight, to});
    graph[to].push_back({weight, from});
  }
  vector<vector<long long>> distances(
      N + 1, vector<long long>(K + 1, numeric_limits<long long>::max()));
  priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>,
                 greater<tuple<long long, int, int>>>
      pq;
  for (int i = 0; i <= K; ++i) {
    distances[1][i] = 0;
  }
  pq.push({0, 1, 0});
  while (!pq.empty()) {
    auto [curr_distance, curr, k] = pq.top();
    pq.pop();
    if (distances[curr][k] < curr_distance) {
      continue;
    }
    for (const auto& [adj_weight, adj] : graph[curr]) {
      if (distances[adj][k] > distances[curr][k] + adj_weight) {
        distances[adj][k] = distances[curr][k] + adj_weight;
        pq.push({distances[adj][k], adj, k});
      }
      if (k < K && distances[adj][k + 1] > distances[curr][k]) {
        distances[adj][k + 1] = distances[curr][k];
        pq.push({distances[adj][k + 1], adj, k + 1});
      }
    }
  }
  cout << *min_element(distances[N].cbegin(), distances[N].cend());
  return 0;
}

#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> W(N);
  for (auto& w : W) {
    cin >> w;
  }
  vector<vector<pair<int, int>>> graph(N);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      int P;
      cin >> P;
      graph[i].push_back({P, j});
      graph[j].push_back({P, i});
    }
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  auto min_it = min_element(W.cbegin(), W.cend());
  pq.push({*min_it, min_it - W.cbegin()});
  vector<bool> visited(N);
  int mst_cost = 0;
  while (!pq.empty()) {
    auto [curr_weight, curr] = pq.top();
    pq.pop();
    if (visited[curr]) continue;
    visited[curr] = true;
    mst_cost += curr_weight;
    for (const auto& [adj_weight, adj] : graph[curr]) {
      if (visited[adj]) continue;
      pq.push({min(adj_weight, W[adj]), adj});
    }
  }
  cout << mst_cost;
  return 0;
}

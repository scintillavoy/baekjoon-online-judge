#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> graph(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    graph[u].push_back({v, w});
  }
  vector<int> revenue(n + 1, numeric_limits<int>::min());
  vector<int> parent(n + 1, -1);
  queue<int> q;
  revenue[1] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int from = 1; from <= n; ++from) {
      for (const auto& [to, weight] : graph[from]) {
        if (revenue[from] == numeric_limits<int>::min()) {
          continue;
        }
        if (revenue[to] < revenue[from] + weight) {
          if (i == n) {
            q.push(from);
          }
          revenue[to] = revenue[from] + weight;
          parent[to] = from;
        }
      }
    }
  }
  if (revenue[n] == numeric_limits<int>::min()) {
    cout << -1;
    return 0;
  }
  vector<bool> visited(n + 1);
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    if (visited[curr]) {
      continue;
    }
    visited[curr] = true;
    for (const auto& [adj, adj_weight] : graph[curr]) {
      q.push(adj);
    }
  }
  if (visited[n]) {
    cout << -1;
    return 0;
  }
  vector<int> route;
  for (int curr = n; curr != -1; curr = parent[curr]) {
    route.push_back(curr);
  }
  for (auto it = route.crbegin(); it != route.crend(); ++it) {
    cout << *it << ' ';
  }
}

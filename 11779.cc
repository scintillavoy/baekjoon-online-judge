#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

vector<int> parent;

void find_path(vector<int> &path, int v) {
  if (parent[v] == -1) {
    path.push_back(v);
    return;
  }
  find_path(path, parent[v]);
  path.push_back(v);
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> graph(n + 1);
  for (int i = 0; i < m; ++i) {
    int from, to, weight;
    cin >> from >> to >> weight;
    graph[from].push_back({weight, to});
  }
  int source, destination;
  cin >> source >> destination;
  vector<int> distance_(n + 1, numeric_limits<int>::max());
  parent = vector<int>(n + 1, -1);
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  distance_[source] = 0;
  pq.push({0, source});
  while (!pq.empty()) {
    auto [curr_distance, curr] = pq.top();
    pq.pop();
    if (distance_[curr] < curr_distance) {
      continue;
    }
    for (const auto &[adj_weight, adj] : graph[curr]) {
      if (distance_[adj] > distance_[curr] + adj_weight) {
        distance_[adj] = distance_[curr] + adj_weight;
        parent[adj] = curr;
        pq.push({distance_[adj], adj});
      }
    }
  }
  cout << distance_[destination] << '\n';
  vector<int> path;
  find_path(path, destination);
  cout << path.size() << '\n';
  for (const auto &v : path) {
    cout << v << ' ';
  }
  return 0;
}

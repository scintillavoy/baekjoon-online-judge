#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, int>>> graph(M);
    for (int i = 0; i < N; ++i) {
      int x, y, z;
      cin >> x >> y >> z;
      graph[x].push_back({z, y});
      graph[y].push_back({z, x});
    }
    vector<int> distance_(M, numeric_limits<int>::max());
    vector<int> parent(M, -1);
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
        if (distance_[adj] > distance_[curr] + adj_weight) {
          distance_[adj] = distance_[curr] + adj_weight;
          parent[adj] = curr;
          pq.push({distance_[adj], adj});
        }
      }
    }
    cout << "Case #" << t << ":";
    if (distance_[M - 1] == numeric_limits<int>::max()) {
      cout << " -1";
    } else {
      vector<int> path;
      int v = M - 1;
      while (parent[v] != -1) {
        path.push_back(v);
        v = parent[v];
      }
      path.push_back(v);
      for (auto it = path.crbegin(); it != path.crend(); ++it) {
        cout << ' ' << *it;
      }
    }
    cout << '\n';
  }
  return 0;
}

#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

vector<int> dijkstra(const vector<vector<pair<int, int>>>& graph, int source) {
  vector<int> distance_(graph.size(), numeric_limits<int>::max());
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
    for (const auto& [adj_weight, adj] : graph[curr]) {
      if (distance_[adj] > distance_[curr] + adj_weight) {
        distance_[adj] = distance_[curr] + adj_weight;
        pq.push({distance_[adj], adj});
      }
    }
  }
  return distance_;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m, t;
    cin >> n >> m >> t;
    int s, g, h;
    cin >> s >> g >> h;
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
      int a, b, d;
      cin >> a >> b >> d;
      graph[a].push_back({d, b});
      graph[b].push_back({d, a});
    }
    vector<int> candidates;
    for (int i = 0; i < t; ++i) {
      int x;
      cin >> x;
      candidates.push_back(x);
    }
    vector<int> distance_from_s = dijkstra(graph, s);
    int c = (distance_from_s[g] > distance_from_s[h] ? g : h);
    vector<int> distance_from_c = dijkstra(graph, c);
    vector<int> destinations;
    for (int i = 0; i < candidates.size(); ++i) {
      if (distance_from_s[candidates[i]] == numeric_limits<int>::max() ||
          distance_from_s[candidates[i]] <
              distance_from_s[c] + distance_from_c[candidates[i]]) {
        continue;
      }
      destinations.push_back(candidates[i]);
    }
    sort(destinations.begin(), destinations.end());
    for (int i = 0; i < destinations.size(); ++i) {
      cout << destinations[i] << ' ';
    }
    cout << '\n';
  }
  return 0;
}

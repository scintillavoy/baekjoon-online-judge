#include <cmath>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<int, int>> positions(n + 2);
    for (int i = 0; i < positions.size(); ++i) {
      cin >> positions[i].first >> positions[i].second;
    }
    vector<vector<int>> graph(n + 2);
    for (int i = 0; i < positions.size() - 1; ++i) {
      auto [x, y] = positions[i];
      for (int j = i + 1; j < positions.size(); ++j) {
        auto [x2, y2] = positions[j];
        int distance = abs(x2 - x) + abs(y2 - y);
        if (distance <= 1000) {
          graph[i].push_back(j);
          graph[j].push_back(i);
        }
      }
    }
    vector<bool> visited(n + 2);
    queue<int> q;
    visited[0] = true;
    q.push(0);
    while (!q.empty()) {
      int curr = q.front();
      q.pop();
      for (const auto &adj : graph[curr]) {
        if (visited[adj]) {
          continue;
        }
        visited[adj] = true;
        q.push(adj);
      }
    }
    cout << (visited.back() ? "happy" : "sad") << '\n';
  }
  return 0;
}

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int K;
  cin >> K;
outer_loop:
  while (K--) {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> graph(V + 1);
    for (int i = 0; i < E; ++i) {
      int u, v;
      cin >> u >> v;
      graph[u].push_back(v);
      graph[v].push_back(u);
    }
    vector<int> visited(V + 1);
    for (int i = 1; i <= V; ++i) {
      if (visited[i] != 0) {
        continue;
      }
      queue<int> q;
      visited[i] = 1;
      q.push(i);
      while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (const auto &adj : graph[curr]) {
          if (visited[adj] == 0) {
            visited[adj] = visited[curr] * -1;
            q.push(adj);
          } else if (visited[adj] == visited[curr]) {
            cout << "NO\n";
            goto outer_loop;
          }
        }
      }
    }
    cout << "YES\n";
  }
  return 0;
}

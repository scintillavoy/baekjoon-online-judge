#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
outer_loop:
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
      int x, y;
      cin >> x >> y;
      graph[x].push_back(y);
      graph[y].push_back(x);
    }
    vector<int> visited(n + 1);
    for (int i = 1; i <= n; ++i) {
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
          if (adj == curr) {
            continue;
          }
          if (visited[adj] == 0) {
            visited[adj] = visited[curr] % 2 + 1;
            q.push(adj);
          } else if (visited[adj] == visited[curr]) {
            cout << "impossible\n";
            goto outer_loop;
          }
        }
      }
    }
    cout << "possible\n";
  }
  return 0;
}

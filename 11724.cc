#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> graph(N + 1, vector<int>());
  for (int i = 0; i < M; ++i) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  vector<bool> is_visited(N + 1, false);
  int count = 0;
  for (int i = 1; i <= N; ++i) {
    if (is_visited[i]) continue;
    is_visited[i] = true;
    ++count;
    queue<int> bfs_queue;
    bfs_queue.push(i);
    while (!bfs_queue.empty()) {
      int current = bfs_queue.front();
      bfs_queue.pop();
      for (const auto &adj : graph[current]) {
        if (is_visited[adj]) continue;
        is_visited[adj] = true;
        bfs_queue.push(adj);
      }
    }
  }
  cout << count;
  return 0;
}

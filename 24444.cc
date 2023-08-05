#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<bool> is_visited;
vector<int> start_time;
int current_time = 0;

int main() {
  int N, M, R;
  cin >> N >> M >> R;
  graph = vector<vector<int>>(N + 1);
  for (int i = 0; i < M; ++i) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  for (int i = 1; i <= N; ++i) {
    sort(graph[i].begin(), graph[i].end());
  }
  is_visited = vector<bool>(N + 1, false);
  start_time = vector<int>(N + 1);
  queue<int> bfs_queue;
  is_visited[R] = true;
  start_time[R] = ++current_time;
  bfs_queue.push(R);
  while (!bfs_queue.empty()) {
    int current = bfs_queue.front();
    bfs_queue.pop();
    for (const auto &adj : graph[current]) {
      if (is_visited[adj]) continue;
      is_visited[adj] = true;
      start_time[adj] = ++current_time;
      bfs_queue.push(adj);
    }
  }
  for (int i = 1; i <= N; ++i) {
    cout << start_time[i] << '\n';
  }
  return 0;
}

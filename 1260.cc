#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<bool> is_visited;

void dfs(int vertex) {
  is_visited[vertex] = true;
  cout << vertex << ' ';
  for (const auto &adj : graph[vertex]) {
    if (!is_visited[adj]) {
      dfs(adj);
    }
  }
}

void bfs(int source) {
  vector<bool> is_visited(graph.size(), false);
  queue<int> bfs_queue;
  is_visited[source] = true;
  bfs_queue.push(source);
  while (!bfs_queue.empty()) {
    int current = bfs_queue.front();
    bfs_queue.pop();
    cout << current << ' ';
    for (const auto &adj : graph[current]) {
      if (!is_visited[adj]) {
        is_visited[adj] = true;
        bfs_queue.push(adj);
      }
    }
  }
}

int main() {
  int N, M, V;
  cin >> N >> M >> V;

  graph = vector<vector<int>>(N + 1);
  for (int i = 0; i < M; ++i) {
    int from, to;
    cin >> from >> to;
    graph[from].push_back(to);
    graph[to].push_back(from);
  }

  for (auto &edges : graph) {
    sort(edges.begin(), edges.end());
  }

  is_visited = vector<bool>(N + 1, false);
  dfs(V);
  cout << '\n';

  is_visited = vector<bool>(N + 1, false);
  bfs(V);
  return 0;
}

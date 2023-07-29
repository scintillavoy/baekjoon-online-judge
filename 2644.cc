#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  int from, to;
  cin >> from >> to;
  int m;
  cin >> m;
  vector<vector<int>> graph(n + 1, vector<int>());
  while (m--) {
    int x, y;
    cin >> x >> y;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  vector<bool> is_visited(n + 1);
  vector<int> distance(n + 1);
  queue<int> bfs_queue;
  is_visited[from] = true;
  distance[from] = 0;
  bfs_queue.push(from);
  while (!bfs_queue.empty()) {
    int current = bfs_queue.front();
    bfs_queue.pop();
    for (const auto &adj : graph[current]) {
      if (is_visited[adj]) continue;
      is_visited[adj] = true;
      distance[adj] = distance[current] + 1;
      bfs_queue.push(adj);
      if (adj == to) {
        cout << distance[adj];
        return 0;
      }
    }
  }
  cout << -1;
  return 0;
}

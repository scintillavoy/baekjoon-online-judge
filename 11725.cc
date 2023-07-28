#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int>> graph(N + 1);
  for (int i = 0; i < N - 1; ++i) {
    int from, to;
    cin >> from >> to;
    graph[from].push_back(to);
    graph[to].push_back(from);
  }
  vector<int> parents(N + 1);
  vector<bool> is_visited(N + 1);
  queue<int> bfs_queue;
  bfs_queue.push(1);
  is_visited[1] = true;
  while (!bfs_queue.empty()) {
    int curr = bfs_queue.front();
    bfs_queue.pop();
    for (const auto &adj : graph[curr]) {
      if (!is_visited[adj]) {
        is_visited[adj] = true;
        parents[adj] = curr;
        bfs_queue.push(adj);
      }
    }
  }
  for (int i = 2; i < parents.size(); ++i) {
    cout << parents[i] << '\n';
  }
  return 0;
}

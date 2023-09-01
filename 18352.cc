#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int N, M, K, X;
  cin >> N >> M >> K >> X;
  vector<vector<int>> graph(N + 1);
  for (int i = 0; i < M; ++i) {
    int A, B;
    cin >> A >> B;
    graph[A].push_back(B);
  }
  vector<bool> visited(N + 1);
  queue<int> bfs_queue;
  visited[X] = true;
  bfs_queue.push(X);
  while (K--) {
    for (int i = bfs_queue.size(); i > 0; --i) {
      int curr = bfs_queue.front();
      bfs_queue.pop();
      for (const auto &adj : graph[curr]) {
        if (visited[adj]) {
          continue;
        }
        visited[adj] = true;
        bfs_queue.push(adj);
      }
    }
  }
  if (bfs_queue.size() == 0) {
    cout << -1;
    return 0;
  }
  vector<int> answer;
  while (!bfs_queue.empty()) {
    answer.push_back(bfs_queue.front());
    bfs_queue.pop();
  }
  sort(answer.begin(), answer.end());
  for (const auto &x : answer) {
    cout << x << '\n';
  }
  return 0;
}

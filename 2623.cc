#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  vector<vector<int>> graph(N + 1);
  vector<int> in_degree(N + 1);
  for (int i = 0; i < M; ++i) {
    int count;
    cin >> count;
    int from;
    cin >> from;
    for (int j = 1; j < count; ++j) {
      int to;
      cin >> to;
      graph[from].push_back(to);
      ++in_degree[to];
      from = to;
    }
  }
  queue<int> q;
  for (int i = 1; i <= N; ++i) {
    if (in_degree[i] == 0) {
      q.push(i);
    }
  }
  vector<int> finished;
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    finished.push_back(curr);
    for (const auto &adj : graph[curr]) {
      --in_degree[adj];
      if (in_degree[adj] == 0) {
        q.push(adj);
      }
    }
  }
  if (finished.size() != N) {
    cout << 0;
  } else {
    for (int i = 0; i < finished.size(); ++i) {
      cout << finished[i] << '\n';
    }
  }
  return 0;
}

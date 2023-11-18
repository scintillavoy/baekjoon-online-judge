#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

bool dfs(int curr, int depth) {
  if (depth == 4) {
    return true;
  }
  for (const auto &adj : graph[curr]) {
    if (visited[adj]) {
      continue;
    }
    visited[adj] = true;
    bool result = dfs(adj, depth + 1);
    visited[adj] = false;
    if (result) {
      return true;
    }
  }
  return false;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  graph = vector<vector<int>>(N);
  for (int i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  for (int i = 0; i < N; ++i) {
    visited = vector<bool>(N);
    visited[i] = true;
    if (dfs(i, 0)) {
      cout << 1;
      return 0;
    }
  }
  cout << 0;
  return 0;
}

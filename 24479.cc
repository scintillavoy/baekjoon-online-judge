#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<bool> is_visited;
vector<int> start_time;
int current_time = 0;

void dfs(int current) {
  is_visited[current] = true;
  start_time[current] = ++current_time;
  for (const auto &adj : graph[current]) {
    if (is_visited[adj]) continue;
    dfs(adj);
  }
}

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
  dfs(R);
  for (int i = 1; i <= N; ++i) {
    cout << start_time[i] << '\n';
  }
  return 0;
}

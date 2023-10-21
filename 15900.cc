#include <iostream>
#include <vector>
using namespace std;

vector<bool> visited;
vector<vector<int>> graph;
int count_ = 0;

void dfs(int x, int depth) {
  visited[x] = true;
  if (x != 1 && graph[x].size() == 1) {
    count_ += depth;
    return;
  }
  for (const auto &adj : graph[x]) {
    if (visited[adj]) continue;
    dfs(adj, depth + 1);
  }
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  visited = vector<bool>(N + 1);
  graph = vector<vector<int>>(N + 1);
  for (int i = 0; i < N - 1; ++i) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  dfs(1, 0);
  cout << (count_ % 2 == 1 ? "Yes" : "No");
  return 0;
}

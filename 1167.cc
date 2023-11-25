#include <iostream>
#include <utility>
#include <vector>
using namespace std;

vector<vector<pair<int, int>>> graph;
vector<bool> visited;
int farthest;
int max_weight;

void dfs(int curr, int curr_weight) {
  visited[curr] = true;
  for (const auto& [adj, adj_weight] : graph[curr]) {
    if (visited[adj]) {
      continue;
    }
    int next_weight = curr_weight + adj_weight;
    if (max_weight < next_weight) {
      max_weight = next_weight;
      farthest = adj;
    }
    dfs(adj, next_weight);
  }
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int V;
  cin >> V;
  graph = vector<vector<pair<int, int>>>(V + 1);
  for (int i = 0; i < V; ++i) {
    int from;
    cin >> from;
    while (true) {
      int to;
      cin >> to;
      if (to == -1) {
        break;
      }
      int weight;
      cin >> weight;
      graph[from].push_back({to, weight});
    }
  }
  visited = vector<bool>(V + 1);
  max_weight = 0;
  dfs(1, 0);
  visited = vector<bool>(V + 1);
  max_weight = 0;
  dfs(farthest, 0);
  cout << max_weight;
  return 0;
}

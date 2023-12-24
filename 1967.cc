#include <iostream>
#include <utility>
#include <vector>
using namespace std;

vector<vector<pair<int, int>>> graph;
vector<bool> visited;
int max_distance;
int farthest;

void dfs(int curr, int curr_distance) {
  visited[curr] = true;
  if (max_distance < curr_distance) {
    max_distance = curr_distance;
    farthest = curr;
  }
  for (const auto& [adj, adj_weight] : graph[curr]) {
    if (visited[adj]) {
      continue;
    }
    dfs(adj, curr_distance + adj_weight);
  }
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  graph = vector<vector<pair<int, int>>>(n + 1);
  for (int i = 0; i < n - 1; ++i) {
    int parent, child, weight;
    cin >> parent >> child >> weight;
    graph[parent].push_back({child, weight});
    graph[child].push_back({parent, weight});
  }
  visited = vector<bool>(n + 1);
  max_distance = 0;
  dfs(1, 0);
  visited = vector<bool>(n + 1);
  max_distance = 0;
  dfs(farthest, 0);
  cout << max_distance;
  return 0;
}

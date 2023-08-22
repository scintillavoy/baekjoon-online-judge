#include <algorithm>
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

vector<int> parent;
vector<int> rank_;

int find_set(int x) {
  if (parent[x] != x) {
    parent[x] = find_set(parent[x]);
  }
  return parent[x];
}

void union_set(int x, int y) {
  x = find_set(x);
  y = find_set(y);
  if (x == y) return;
  if (rank_[x] > rank_[y]) {
    swap(x, y);
  } else if (rank_[x] == rank_[y]) {
    ++rank_[y];
  }
  parent[x] = y;
}

int main() {
  int n, m;
  cin >> n >> m;
  parent = vector<int>(n + 1);
  for (int i = 1; i < n + 1; ++i) {
    parent[i] = i;
  }
  rank_ = vector<int>(n + 1);
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    union_set(x, y);
  }
  vector<tuple<int, int, int>> edges;
  int weight;
  for (int i = 1; i <= n; ++i) {
    cin >> weight;
  }
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      cin >> weight;
    }
    for (int j = i + 1; j <= n; ++j) {
      cin >> weight;
      edges.push_back({weight, i, j});
    }
  }
  sort(edges.begin(), edges.end());
  int mst_cost = 0;
  vector<tuple<int, int, int>> mst_edges;
  for (const auto &edge : edges) {
    auto [weight, from, to] = edge;
    if (find_set(from) == find_set(to)) continue;
    union_set(from, to);
    mst_cost += weight;
    mst_edges.push_back(edge);
  }
  cout << mst_cost << ' ' << mst_edges.size() << '\n';
  for (const auto &edge : mst_edges) {
    auto [weight, from, to] = edge;
    cout << from << ' ' << to << '\n';
  }
  return 0;
}

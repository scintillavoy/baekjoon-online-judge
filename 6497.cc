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
  while (true) {
    int m, n;
    cin >> m >> n;
    if (m == 0 && n == 0) break;
    parent = vector<int>(m);
    for (int i = 0; i < m; ++i) {
      parent[i] = i;
    }
    rank_ = vector<int>(m);
    int weight_sum = 0;
    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < n; ++i) {
      int from, to, weight;
      cin >> from >> to >> weight;
      edges.push_back({weight, from, to});
      weight_sum += weight;
    }
    sort(edges.begin(), edges.end());
    int mst_cost = 0;
    for (const auto &edge : edges) {
      auto [weight, from, to] = edge;
      if (find_set(from) == find_set(to)) continue;
      union_set(from, to);
      mst_cost += weight;
    }
    cout << weight_sum - mst_cost << '\n';
  }
  return 0;
}

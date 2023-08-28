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
  int N, M;
  cin >> N >> M;
  parent = vector<int>(N + 1);
  for (int i = 1; i <= N; ++i) {
    parent[i] = i;
  }
  rank_ = vector<int>(N + 1);
  vector<bool> types(N + 1);
  for (int i = 1; i <= N; ++i) {
    char c;
    cin >> c;
    if (c == 'M') {
      types[i] = true;
    }
  }
  vector<tuple<int, int, int>> edges;
  for (int i = 0; i < M; ++i) {
    int u, v, d;
    cin >> u >> v >> d;
    edges.push_back({d, u, v});
  }
  sort(edges.begin(), edges.end());
  int mst_cost = 0;
  for (const auto &edge : edges) {
    auto [weight, from, to] = edge;
    if (find_set(from) == find_set(to) || types[from] == types[to]) {
      continue;
    }
    union_set(from, to);
    mst_cost += weight;
  }
  int num_of_sets = 0;
  for (int i = 1; i <= N; ++i) {
    if (parent[i] == i) {
      ++num_of_sets;
    }
  }
  cout << (num_of_sets > 1 ? -1 : mst_cost);
  return 0;
}

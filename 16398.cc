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
  int N;
  cin >> N;
  parent = vector<int>(N + 1);
  for (int i = 1; i <= N; ++i) {
    parent[i] = i;
  }
  rank_ = vector<int>(N + 1);
  vector<tuple<int, int, int>> edges;
  for (int i = 0; i < N; ++i) {
    int weight;
    for (int j = 0; j <= i; ++j) {
      cin >> weight;
    }
    for (int j = i + 1; j < N; ++j) {
      cin >> weight;
      edges.push_back({weight, i, j});
    }
  }
  sort(edges.begin(), edges.end());
  long long mst_cost = 0;
  for (const auto &edge : edges) {
    auto [weight, from, to] = edge;
    if (find_set(from) == find_set(to)) continue;
    union_set(from, to);
    mst_cost += weight;
  }
  cout << mst_cost;
  return 0;
}

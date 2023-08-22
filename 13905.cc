#include <algorithm>
#include <functional>
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
  int s, e;
  cin >> s >> e;
  vector<tuple<int, int, int>> edges;
  for (int i = 0; i < M; ++i) {
    int h1, h2, k;
    cin >> h1 >> h2 >> k;
    edges.push_back({k, h1, h2});
  }
  sort(edges.begin(), edges.end(), greater<tuple<int, int, int>>());
  for (const auto &edge : edges) {
    auto [weight, from, to] = edge;
    if (find_set(from) == find_set(to)) continue;
    union_set(from, to);
    if (find_set(s) == find_set(e)) {
      cout << weight;
      return 0;
    }
  }
  cout << 0;
  return 0;
}

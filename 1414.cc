#include <algorithm>
#include <cctype>
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
  parent = vector<int>(N);
  for (int i = 0; i < N; ++i) {
    parent[i] = i;
  }
  rank_ = vector<int>(N);
  vector<tuple<int, int, int>> edges;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      char wire;
      cin >> wire;
      if (wire == '0') continue;
      int weight;
      if (isupper(wire)) {
        weight = wire - 'A' + 27;
      } else {
        weight = wire - 'a' + 1;
      }
      edges.push_back({weight, i, j});
    }
  }
  sort(edges.begin(), edges.end());
  int sum_of_lengths = 0;
  for (const auto &edge : edges) {
    auto [weight, from, to] = edge;
    if (find_set(from) == find_set(to)) {
      sum_of_lengths += weight;
      continue;
    }
    union_set(from, to);
  }
  int num_of_sets = 0;
  for (int i = 0; i < N; ++i) {
    if (parent[i] == i) {
      ++num_of_sets;
    }
  }
  cout << (num_of_sets > 1 ? -1 : sum_of_lengths);
  return 0;
}

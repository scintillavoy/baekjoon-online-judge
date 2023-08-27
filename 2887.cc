#include <algorithm>
#include <cmath>
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
  vector<tuple<int, int, int, int>> coordinates;
  for (int i = 0; i < N; ++i) {
    int x, y, z;
    cin >> x >> y >> z;
    coordinates.push_back({x, y, z, i});
  }
  vector<tuple<int, int, int>> edges;
  sort(coordinates.begin(), coordinates.end(),
       [](tuple<int, int, int, int> a, tuple<int, int, int, int> b) {
         return get<0>(a) < get<0>(b);
       });
  for (int i = 0; i < N - 1; ++i) {
    auto [x1, y1, z1, a] = coordinates[i];
    auto [x2, y2, z2, b] = coordinates[i + 1];
    edges.push_back({abs(x1 - x2), a, b});
  }
  sort(coordinates.begin(), coordinates.end(),
       [](tuple<int, int, int, int> a, tuple<int, int, int, int> b) {
         return get<1>(a) < get<1>(b);
       });
  for (int i = 0; i < N - 1; ++i) {
    auto [x1, y1, z1, a] = coordinates[i];
    auto [x2, y2, z2, b] = coordinates[i + 1];
    edges.push_back({abs(y1 - y2), a, b});
  }
  sort(coordinates.begin(), coordinates.end(),
       [](tuple<int, int, int, int> a, tuple<int, int, int, int> b) {
         return get<2>(a) < get<2>(b);
       });
  for (int i = 0; i < N - 1; ++i) {
    auto [x1, y1, z1, a] = coordinates[i];
    auto [x2, y2, z2, b] = coordinates[i + 1];
    edges.push_back({abs(z1 - z2), a, b});
  }
  sort(edges.begin(), edges.end());
  int mst_cost = 0;
  for (const auto &edge : edges) {
    auto [weight, from, to] = edge;
    if (find_set(from) == find_set(to)) continue;
    union_set(from, to);
    mst_cost += weight;
  }
  cout << mst_cost;
  return 0;
}

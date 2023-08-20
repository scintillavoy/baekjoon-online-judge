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
  int n;
  cin >> n;
  vector<pair<double, double>> coordinates;
  for (int i = 0; i < n; ++i) {
    double x, y;
    cin >> x >> y;
    coordinates.push_back({x, y});
  }
  parent = vector<int>(n);
  for (int i = 0; i < n; ++i) {
    parent[i] = i;
  }
  rank_ = vector<int>(n);
  vector<tuple<double, int, int>> edges;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      double distance =
          sqrt(pow(coordinates[i].first - coordinates[j].first, 2) +
               pow(coordinates[i].second - coordinates[j].second, 2));
      edges.push_back({distance, i, j});
    }
  }
  sort(edges.begin(), edges.end());
  double mst_cost = 0.0;
  for (const auto &edge : edges) {
    auto [weight, from, to] = edge;
    if (find_set(from) == find_set(to)) continue;
    union_set(from, to);
    mst_cost += weight;
  }
  cout.precision(2);
  cout << fixed << mst_cost;
  return 0;
}

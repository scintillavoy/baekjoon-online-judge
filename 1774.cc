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
  int N, M;
  cin >> N >> M;
  parent = vector<int>(N);
  for (int i = 0; i < N; ++i) {
    parent[i] = i;
  }
  rank_ = vector<int>(N);
  vector<pair<int, int>> positions;
  for (int i = 0; i < N; ++i) {
    int X, Y;
    cin >> X >> Y;
    positions.push_back({X, Y});
  }
  for (int i = 0; i < M; ++i) {
    int from, to;
    cin >> from >> to;
    union_set(from - 1, to - 1);
  }
  vector<tuple<double, int, int>> edges;
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      double weight = sqrt(pow(positions[i].first - positions[j].first, 2) +
                           pow(positions[i].second - positions[j].second, 2));
      edges.push_back({weight, i, j});
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
  mst_cost = round(mst_cost * pow(10, 2)) / pow(10, 2);
  cout.precision(2);
  cout << fixed << mst_cost;
  return 0;
}

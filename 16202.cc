#include <iostream>
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
  if (x == y) {
    return;
  }
  if (rank_[x] > rank_[y]) {
    swap(x, y);
  } else if (rank_[x] == rank_[y]) {
    ++rank_[y];
  }
  parent[x] = y;
}

void initialize_disjoint_set(int N) {
  parent = vector<int>(N);
  for (int i = 0; i < N; ++i) {
    parent[i] = i;
  }
  rank_ = vector<int>(N);
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, M, K;
  cin >> N >> M >> K;
  vector<pair<int, int>> edges;
  for (int i = 1; i <= M; ++i) {
    int x, y;
    cin >> x >> y;
    edges.push_back({x, y});
  }
  for (int i = 1; i <= K; ++i) {
    initialize_disjoint_set(N + 1);
    int mst_cost = 0;
    for (int j = i; j <= edges.size(); ++j) {
      auto [x, y] = edges[j - 1];
      if (find_set(x) == find_set(y)) {
        continue;
      }
      mst_cost += j;
      union_set(x, y);
    }
    int num_of_trees = 0;
    for (int j = 1; j <= N; ++j) {
      if (parent[j] == j) {
        ++num_of_trees;
      }
    }
    if (num_of_trees >= 2) {
      while (i <= K) {
        cout << 0 << ' ';
        ++i;
      }
      break;
    }
    cout << mst_cost << ' ';
  }
  return 0;
}

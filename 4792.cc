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
  if (x == y) return;
  if (rank_[x] > rank_[y]) {
    swap(x, y);
  } else if (rank_[x] == rank_[y]) {
    ++rank_[y];
  }
  parent[x] = y;
}

void initialize_disjoint_set(int n) {
  parent = vector<int>(n + 1);
  for (int i = 1; i <= n; ++i) {
    parent[i] = i;
  }
  rank_ = vector<int>(n + 1);
}

int main() {
  while (true) {
    int n, m, k;
    cin >> n >> m >> k;
    if (n == 0 && m == 0 && k == 0) {
      break;
    }
    vector<pair<int, int>> blue_edges, red_edges;
    for (int i = 0; i < m; ++i) {
      char c;
      int f, t;
      cin >> c >> f >> t;
      if (c == 'B') {
        blue_edges.push_back({f, t});
      } else if (c == 'R') {
        red_edges.push_back({f, t});
      }
    }

    initialize_disjoint_set(n);
    int max_num_of_blue_edges = 0;
    for (const auto &edge : blue_edges) {
      auto [from, to] = edge;
      if (find_set(from) == find_set(to)) {
        continue;
      }
      union_set(from, to);
      ++max_num_of_blue_edges;
    }
    for (const auto &edge : red_edges) {
      auto [from, to] = edge;
      if (find_set(from) == find_set(to)) {
        continue;
      }
      union_set(from, to);
    }
    int num_of_sets = 0;
    for (int i = 1; i <= n; ++i) {
      if (parent[i] == i) {
        ++num_of_sets;
      }
    }
    if (num_of_sets > 1) {
      cout << 0 << '\n';
      continue;
    }

    initialize_disjoint_set(n);
    int min_num_of_blue_edges = 0;
    for (const auto &edge : red_edges) {
      auto [from, to] = edge;
      if (find_set(from) == find_set(to)) {
        continue;
      }
      union_set(from, to);
    }
    for (const auto &edge : blue_edges) {
      auto [from, to] = edge;
      if (find_set(from) == find_set(to)) {
        continue;
      }
      union_set(from, to);
      ++min_num_of_blue_edges;
    }
    num_of_sets = 0;
    for (int i = 1; i <= n; ++i) {
      if (parent[i] == i) {
        ++num_of_sets;
      }
    }
    if (num_of_sets > 1) {
      cout << 0 << '\n';
      continue;
    }

    if (min_num_of_blue_edges <= k && k <= max_num_of_blue_edges) {
      cout << 1;
    } else {
      cout << 0;
    }
    cout << '\n';
  }
  return 0;
}

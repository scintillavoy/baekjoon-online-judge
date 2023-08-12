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
  }
  parent[x] = y;
  if (rank_[x] == rank_[y]) {
    ++rank_[y];
  }
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    int n, k;
    cin >> n >> k;
    parent = vector<int>(n);
    for (int i = 0; i < n; ++i) {
      parent[i] = i;
    }
    rank_ = vector<int>(n);
    while (k--) {
      int a, b;
      cin >> a >> b;
      union_set(a, b);
    }
    int m;
    cin >> m;
    cout << "Scenario " << i << ":\n";
    while (m--) {
      int u, v;
      cin >> u >> v;
      cout << (find_set(u) == find_set(v) ? 1 : 0) << '\n';
    }
    cout << '\n';
  }
  return 0;
}

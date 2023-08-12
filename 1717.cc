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
  int n, m;
  cin >> n >> m;
  parent = vector<int>(n + 1);
  rank_ = vector<int>(n + 1);
  for (int i = 0; i <= n; ++i) {
    parent[i] = i;
  }
  while (m--) {
    int op, a, b;
    cin >> op >> a >> b;
    switch (op) {
      case 0:
        union_set(a, b);
        break;
      case 1:
        cout << (find_set(a) == find_set(b) ? "YES" : "NO") << '\n';
        break;
    }
  }
  return 0;
}

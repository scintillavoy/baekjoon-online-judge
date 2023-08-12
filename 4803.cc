#include <iostream>
#include <utility>
#include <vector>
using namespace std;

vector<int> parent;
vector<int> rank_;
vector<bool> is_cycle;

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
    is_cycle[x] = is_cycle[y] = true;
    return;
  }
  if (rank_[x] > rank_[y]) {
    swap(x, y);
  }
  if (is_cycle[x]) {
    is_cycle[y] = true;
  }
  parent[x] = y;
  if (rank_[x] == rank_[y]) {
    ++rank_[y];
  }
}

int main() {
  for (int T = 1; true; ++T) {
    int n, m;
    cin >> n >> m;
    if (n == 0 && m == 0) break;
    parent = vector<int>(n + 1);
    for (int i = 1; i <= n; ++i) {
      parent[i] = i;
    }
    rank_ = vector<int>(n + 1);
    is_cycle = vector<bool>(n + 1);
    while (m--) {
      int x, y;
      cin >> x >> y;
      union_set(x, y);
    }
    int count = 0;
    for (int i = 1; i <= n; ++i) {
      if (find_set(i) == i && !is_cycle[i]) {
        ++count;
      }
    }
    cout << "Case " << T << ": ";
    switch (count) {
      case 0:
        cout << "No trees.";
        break;
      case 1:
        cout << "There is one tree.";
        break;
      default:
        cout << "A forest of " << count << " trees.";
        break;
    }
    cout << '\n';
  }
  return 0;
}

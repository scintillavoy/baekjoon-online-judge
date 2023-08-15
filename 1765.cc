#include <iostream>
#include <utility>
#include <vector>
using namespace std;

vector<int> rank_;
vector<int> parent;

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
  int n, m;
  cin >> n >> m;
  rank_ = vector<int>(n + 1);
  parent = vector<int>(n + 1);
  for (int i = 1; i <= n; ++i) {
    parent[i] = i;
  }
  vector<int> enemy(n + 1);
  while (m--) {
    char type;
    int p, q;
    cin >> type >> p >> q;
    switch (type) {
      case 'F':
        union_set(p, q);
        break;
      case 'E':
        if (enemy[p] != 0) {
          union_set(q, enemy[p]);
        } else {
          enemy[p] = q;
        }
        if (enemy[q] != 0) {
          union_set(p, enemy[q]);
        } else {
          enemy[q] = p;
        }
        break;
    }
  }
  int count = 0;
  for (int i = 1; i <= n; ++i) {
    if (parent[i] == i) ++count;
  }
  cout << count;
  return 0;
}

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

bool union_set(int x, int y) {
  x = find_set(x);
  y = find_set(y);
  if (x == y) return true;
  if (rank_[x] > rank_[y]) {
    swap(x, y);
  }
  parent[x] = y;
  if (rank_[x] == rank_[y]) {
    ++rank_[y];
  }
  return false;
}

int main() {
  int n, m;
  cin >> n >> m;
  parent = vector<int>(n);
  for (int i = 0; i < n; ++i) {
    parent[i] = i;
  }
  rank_ = vector<int>(n);
  int result = 0;
  for (int i = 1; i <= m; ++i) {
    int x, y;
    cin >> x >> y;
    if (union_set(x, y) && result == 0) {
      result = i;
    }
  }
  cout << result;
  return 0;
}

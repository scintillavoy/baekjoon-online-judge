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
  int N;
  cin >> N;
  parent = vector<int>(N);
  for (int i = 0; i < N; ++i) {
    parent[i] = i;
  }
  rank_ = vector<int>(N);
  for (int i = 1; i <= N - 2; ++i) {
    int x, y;
    cin >> x >> y;
    union_set(x - 1, y - 1);
  }
  int parent_0 = find_set(0);
  for (int i = 1; i < N; ++i) {
    if (parent_0 != find_set(i)) {
      cout << 1 << ' ' << i + 1;
      break;
    }
  }
  return 0;
}

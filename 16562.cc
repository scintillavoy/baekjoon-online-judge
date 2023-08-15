#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

vector<int> rank_;
vector<int> parent;
vector<int> A;

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
  A[y] = min(A[y], A[x]);
}

int main() {
  int N, M, k;
  cin >> N >> M >> k;
  rank_ = vector<int>(N + 1);
  parent = vector<int>(N + 1);
  for (int i = 1; i <= N; ++i) {
    parent[i] = i;
  }
  A = vector<int>(N + 1);
  for (int i = 1; i <= N; ++i) {
    cin >> A[i];
  }
  while (M--) {
    int v, w;
    cin >> v >> w;
    union_set(v, w);
  }
  int min_cost = 0;
  for (int i = 1; i <= N; ++i) {
    if (i == parent[i]) {
      min_cost += A[i];
    }
  }
  if (min_cost > k) {
    cout << "Oh no";
  } else {
    cout << min_cost;
  }
  return 0;
}

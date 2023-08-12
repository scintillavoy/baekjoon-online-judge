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
  int N, M;
  cin >> N >> M;
  parent = vector<int>(N);
  for (int i = 0; i < N; ++i) {
    parent[i] = i;
  }
  rank_ = vector<int>(N);
  while (M--) {
    int i, j;
    cin >> i >> j;
    union_set(i - 1, j - 1);
  }
  int curr = -1;
  int count = 0;
  for (int i = 0; i < N; ++i) {
    int A;
    cin >> A;
    int next = find_set(A - 1);
    if (curr != next) {
      curr = next;
      ++count;
    }
  }
  cout << count - 1;
  return 0;
}

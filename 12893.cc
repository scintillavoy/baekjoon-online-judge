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
  int N, M;
  cin >> N >> M;
  rank_ = vector<int>(N + 1);
  parent = vector<int>(N + 1);
  vector<int> enemy(N + 1);
  for (int i = 1; i <= N; ++i) {
    parent[i] = i;
  }
  bool answer = true;
  while (M--) {
    int A, B;
    cin >> A >> B;
    if (find_set(A) == find_set(B)) {
      answer = false;
    } else {
      if (enemy[A] != 0) {
        union_set(enemy[A], B);
      } else {
        enemy[A] = B;
      }
      if (enemy[B] != 0) {
        union_set(enemy[B], A);
      } else {
        enemy[B] = A;
      }
    }
  }
  cout << (answer ? 1 : 0);
  return 0;
}

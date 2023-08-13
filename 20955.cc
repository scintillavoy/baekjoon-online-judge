#include <iostream>
#include <utility>
#include <vector>
using namespace std;

vector<int> rank_;
vector<int> parent;
int num_of_operations = 0;

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
    ++num_of_operations;
    return;
  }
  if (rank_[x] > rank_[y]) {
    swap(x, y);
  } else if (rank_[x] == rank_[y]) {
    ++rank_[y];
  }
  parent[x] = y;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  rank_ = vector<int>(N + 1);
  parent = vector<int>(N + 1);
  for (int i = 1; i <= N; ++i) {
    parent[i] = i;
  }
  while (M--) {
    int u, v;
    cin >> u >> v;
    union_set(u, v);
  }
  for (int i = 1; i <= N; ++i) {
    if (i == find_set(i)) {
      ++num_of_operations;
    }
  }
  --num_of_operations;
  cout << num_of_operations;
  return 0;
}

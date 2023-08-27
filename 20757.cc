#include <iostream>
#include <utility>
#include <vector>
using namespace std;

vector<int> parent;
vector<int> rank_;
vector<int> size_;

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
  size_[y] += size_[x];
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    parent = vector<int>(N);
    for (int i = 0; i < N; ++i) {
      parent[i] = i;
    }
    rank_ = vector<int>(N);
    size_ = vector<int>(N, 1);
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        int num;
        cin >> num;
        if (num == 0) continue;
        union_set(i, j);
      }
    }
    int num_of_roads = 0;
    for (int i = 0; i < N; ++i) {
      if (find_set(i) != i) continue;
      num_of_roads += size_[i] - 1;
    }
    cout << num_of_roads << '\n';
  }
  return 0;
}

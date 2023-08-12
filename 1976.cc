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
  parent = vector<int>(N + 1);
  for (int i = 0; i < N + 1; ++i) {
    parent[i] = i;
  }
  rank_ = vector<int>(N + 1);
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      int is_connected;
      cin >> is_connected;
      if (is_connected == 1) {
        union_set(i, j);
      }
    }
  }
  int num;
  cin >> num;
  int curr = find_set(num);
  for (int i = 1; i < M; ++i) {
    cin >> num;
    int next = find_set(num);
    if (curr != next) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}

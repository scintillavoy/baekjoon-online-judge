#include <iostream>
#include <tuple>
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
  if (x == y) {
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
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<tuple<int, int, int>> areas(N);
    for (int i = 0; i < N; ++i) {
      auto& [x, y, R] = areas[i];
      cin >> x >> y >> R;
    }
    parent = vector<int>(N);
    for (int i = 0; i < N; ++i) {
      parent[i] = i;
    }
    rank_ = vector<int>(N);
    for (int i = 0; i < N; ++i) {
      auto [x1, y1, R1] = areas[i];
      for (int j = i + 1; j < N; ++j) {
        auto [x2, y2, R2] = areas[j];
        if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <=
            (R1 + R2) * (R1 + R2)) {
          union_set(i, j);
        }
      }
    }
    int count = 0;
    for (int i = 0; i < N; ++i) {
      if (parent[i] == i) {
        ++count;
      }
    }
    cout << count << '\n';
  }
  return 0;
}

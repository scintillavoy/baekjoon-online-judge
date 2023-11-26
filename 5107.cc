#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
using namespace std;

unordered_map<string, string> parent;
unordered_map<string, int> rank_;

string find_set(string x) {
  if (parent[x] != x) {
    parent[x] = find_set(parent[x]);
  }
  return parent[x];
}

void union_set(string x, string y) {
  x = parent[x];
  y = parent[y];
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
  for (int t = 1; true; ++t) {
    int N;
    cin >> N;
    if (N == 0) {
      break;
    }
    parent.clear();
    rank_.clear();
    int count = 0;
    for (int i = 0; i < N; ++i) {
      string x, y;
      cin >> x >> y;
      if (parent.count(x) == 0) {
        parent[x] = x;
      }
      if (parent.count(y) == 0) {
        parent[y] = y;
      }
      if (rank_.count(x) == 0) {
        rank_[x] = 0;
      }
      if (rank_.count(y) == 0) {
        rank_[y] = 0;
      }
      if (find_set(x) == find_set(y)) {
        ++count;
      } else {
        union_set(x, y);
      }
    }
    cout << t << ' ' << count << '\n';
  }
  return 0;
}

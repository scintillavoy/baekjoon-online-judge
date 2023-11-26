#include <iostream>
#include <queue>
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
  int p, w;
  cin >> p >> w;
  parent = vector<int>(p);
  for (int i = 0; i < p; ++i) {
    parent[i] = i;
  }
  rank_ = vector<int>(p);
  int c, v;
  cin >> c >> v;
  priority_queue<tuple<int, int, int>> pq;
  for (int i = 0; i < w; ++i) {
    int start, end, width;
    cin >> start >> end >> width;
    pq.push({width, start, end});
  }
  while (!pq.empty()) {
    auto [width, start, end] = pq.top();
    pq.pop();
    union_set(start, end);
    if (find_set(c) == find_set(v)) {
      cout << width;
      break;
    }
  }
  return 0;
}

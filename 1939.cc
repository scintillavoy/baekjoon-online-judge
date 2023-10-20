#include <iostream>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

vector<int> parent;
vector<int> rank_;
vector<int> limits;

int find_set(int x) {
  if (parent[x] != x) {
    parent[x] = find_set(parent[x]);
  }
  return parent[x];
}

void union_set(int x, int y, int limit) {
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
  limits[y] = limit;
}

int main() {
  int N, M;
  cin >> N >> M;
  parent = vector<int>(N + 1);
  for (int i = 0; i < N + 1; ++i) {
    parent[i] = i;
  }
  rank_ = vector<int>(N + 1);
  limits = vector<int>(N + 1);
  priority_queue<tuple<int, int, int>> edges;
  for (int i = 0; i < M; ++i) {
    int from, to, limit;
    cin >> from >> to >> limit;
    edges.push({limit, from, to});
  }
  int source, destination;
  cin >> source >> destination;
  while (find_set(source) != find_set(destination)) {
    auto [limit, from, to] = edges.top();
    edges.pop();
    union_set(from, to, limit);
  }
  cout << limits[find_set(source)];
  return 0;
}

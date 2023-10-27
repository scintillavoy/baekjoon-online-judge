#include <functional>
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
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, M, K;
  cin >> N >> M >> K;
  parent = vector<int>(N + 1);
  for (int i = 1; i <= N; ++i) {
    parent[i] = i;
  }
  rank_ = vector<int>(N + 1);
  int generator;
  cin >> generator;
  for (int i = 1; i < K; ++i) {
    int k;
    cin >> k;
    union_set(generator, k);
  }
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                 greater<tuple<int, int, int>>>
      pq;
  for (int i = 0; i < M; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    pq.push({w, u, v});
  }
  int mst_cost = 0;
  while (!pq.empty()) {
    auto [weight, x, y] = pq.top();
    pq.pop();
    if (find_set(x) == find_set(y)) {
      continue;
    }
    union_set(x, y);
    mst_cost += weight;
  }
  cout << mst_cost;
  return 0;
}

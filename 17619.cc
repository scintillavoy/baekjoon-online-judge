#include <algorithm>
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

vector<int> rank_;
vector<int> parent;
vector<tuple<int, int, int>> logs;

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
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, Q;
  cin >> N >> Q;
  rank_ = vector<int>(N + 1);
  parent = vector<int>(N + 1);
  for (int i = 1; i <= N; ++i) {
    parent[i] = i;
  }
  logs = vector<tuple<int, int, int>>(N);
  for (int i = 1; i <= N; ++i) {
    int x1, x2, y;
    cin >> x1 >> x2 >> y;
    logs[i - 1] = {i, x1, x2};
  }
  sort(logs.begin(), logs.end(),
       [](const tuple<int, int, int> a, tuple<int, int, int> b) {
         if (get<1>(a) != get<1>(b)) {
           return get<1>(a) < get<1>(b);
         }
         return get<2>(a) < get<2>(b);
       });
  int last_x2 = get<2>(logs[0]);
  for (int i = 1; i <= N - 1; ++i) {
    if (get<1>(logs[i]) <= last_x2) {
      union_set(get<0>(logs[i - 1]), get<0>(logs[i]));
      last_x2 = max(last_x2, get<2>(logs[i]));
    } else {
      last_x2 = get<2>(logs[i]);
    }
  }
  while (Q--) {
    int a, b;
    cin >> a >> b;
    cout << (find_set(a) == find_set(b) ? 1 : 0) << '\n';
  }
  return 0;
}

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

vector<int> rank_;
vector<int> parent;
vector<int> size_;
vector<int> candy;

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
  candy[y] += candy[x];
}

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  rank_ = vector<int>(N + 1);
  parent = vector<int>(N + 1);
  for (int i = 1; i <= N; ++i) {
    parent[i] = i;
  }
  size_ = vector<int>(N + 1, 1);
  candy = vector<int>(N + 1);
  for (int i = 1; i <= N; ++i) {
    cin >> candy[i];
  }
  while (M--) {
    int a, b;
    cin >> a >> b;
    union_set(a, b);
  }
  vector<int> dp(K);
  for (int i = 1; i <= N; ++i) {
    if (parent[i] != i) continue;
    for (int j = K - 1; j - size_[i] >= 0; --j) {
      dp[j] = max(dp[j], dp[j - size_[i]] + candy[i]);
    }
  }
  cout << dp.back();
  return 0;
}

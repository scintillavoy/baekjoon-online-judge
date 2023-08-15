#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

vector<int> rank_;
vector<int> parent;
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
  int N, M;
  cin >> N >> M;
  rank_ = vector<int>(N + 1);
  parent = vector<int>(N + 1);
  for (int i = 1; i <= N; ++i) {
    parent[i] = i;
  }
  size_ = vector<int>(N + 1, 1);
  while (M--) {
    int X, Y;
    cin >> X >> Y;
    union_set(X, Y);
  }
  int C, H, K;
  cin >> C >> H >> K;
  priority_queue<int> pq;
  int C_set = find_set(C);
  int H_set = find_set(H);
  for (int i = 1; i <= N; ++i) {
    if (parent[i] == i && i != C_set && i != H_set) {
      pq.push(size_[i]);
    }
  }
  int count = size_[find_set(C)];
  for (int i = 0; !pq.empty() && i < K; ++i) {
    count += pq.top();
    pq.pop();
  }
  cout << count;
  return 0;
}

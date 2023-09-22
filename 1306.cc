#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

vector<int> A;
vector<int> tree;

void init(int node, int start, int end) {
  if (start == end) {
    tree[node] = A[start];
    return;
  }
  init(node * 2, start, (start + end) / 2);
  init(node * 2 + 1, (start + end) / 2 + 1, end);
  tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

int query(int node, int start, int end, int left, int right) {
  if (left > end || right < start) {
    return numeric_limits<int>::min();
  }
  if (left <= start && end <= right) {
    return tree[node];
  }
  int left_query = query(node * 2, start, (start + end) / 2, left, right);
  int right_query =
      query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
  return max(left_query, right_query);
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  A = vector<int>(N);
  for (auto &x : A) {
    cin >> x;
  }
  tree = vector<int>(1 << ((int)ceil(log2(N)) + 1));
  init(1, 0, N - 1);
  for (int i = M - 1; i < N - M + 1; ++i) {
    cout << query(1, 0, N - 1, i - M + 1, i + M - 1) << ' ';
  }
  return 0;
}

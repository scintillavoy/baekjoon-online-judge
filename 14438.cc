#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
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
  tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

void update(int node, int start, int end, int index, int value) {
  if (index < start || end < index) {
    return;
  }
  if (start == end) {
    A[index] = value;
    tree[node] = A[index];
    return;
  }
  update(node * 2, start, (start + end) / 2, index, value);
  update(node * 2 + 1, (start + end) / 2 + 1, end, index, value);
  tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

int query(int node, int start, int end, int left, int right) {
  if (left > end || right < start) {
    return numeric_limits<int>::max();
  }
  if (left <= start && end <= right) {
    return tree[node];
  }
  int left_query = query(node * 2, start, (start + end) / 2, left, right);
  int right_query =
      query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
  return min(left_query, right_query);
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  A = vector<int>(N);
  for (auto &x : A) {
    cin >> x;
  }
  tree = vector<int>(1 << ((int)ceil(log2(N)) + 1));
  init(1, 0, N - 1);
  int M;
  cin >> M;
  while (M--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 1) {
      update(1, 0, N - 1, b - 1, c);
    } else if (a == 2) {
      cout << query(1, 0, N - 1, b - 1, c - 1) << '\n';
    }
  }
  return 0;
}

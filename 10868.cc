#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

vector<int> numbers;
vector<int> tree;

void init(int node, int start, int end) {
  if (start == end) {
    tree[node] = numbers[start];
    return;
  }
  init(node * 2, start, (start + end) / 2);
  init(node * 2 + 1, (start + end) / 2 + 1, end);
  tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

int query(int node, int start, int end, int left, int right) {
  if (left > end || right < start) {
    return numeric_limits<int>::max();
  }
  if (left <= start && end <= right) {
    return tree[node];
  }
  int left_min = query(node * 2, start, (start + end) / 2, left, right);
  int right_min = query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
  return min(left_min, right_min);
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  numbers = vector<int>(N);
  for (auto &x : numbers) {
    cin >> x;
  }
  tree = vector<int>(1 << ((int)ceil(log2(N)) + 1));
  init(1, 0, N - 1);
  while (M--) {
    int a, b;
    cin >> a >> b;
    cout << query(1, 0, N - 1, a - 1, b - 1) << '\n';
  }
  return 0;
}

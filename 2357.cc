#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <utility>
#include <vector>
using namespace std;

vector<int> numbers;
vector<pair<int, int>> tree;

void init(int node, int start, int end) {
  if (start == end) {
    tree[node] = {numbers[start], numbers[start]};
    return;
  }
  init(node * 2, start, (start + end) / 2);
  init(node * 2 + 1, (start + end) / 2 + 1, end);
  pair<int, int> left_child = tree[node * 2];
  pair<int, int> right_child = tree[node * 2 + 1];
  tree[node] = {min(left_child.first, right_child.first),
                max(left_child.second, right_child.second)};
}

pair<int, int> query(int node, int start, int end, int left, int right) {
  if (left > end || right < start) {
    return {numeric_limits<int>::max(), numeric_limits<int>::min()};
  }
  if (left <= start && end <= right) {
    return tree[node];
  }
  pair<int, int> left_query =
      query(node * 2, start, (start + end) / 2, left, right);
  pair<int, int> right_query =
      query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
  return {min(left_query.first, right_query.first),
          max(left_query.second, right_query.second)};
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
  tree = vector<pair<int, int>>(1 << ((int)ceil(log2(N)) + 1));
  init(1, 0, N - 1);
  while (M--) {
    int a, b;
    cin >> a >> b;
    pair<int, int> query_result = query(1, 0, N - 1, a - 1, b - 1);
    cout << query_result.first << ' ' << query_result.second << '\n';
  }
  return 0;
}

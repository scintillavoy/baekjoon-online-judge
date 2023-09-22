#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <utility>
#include <vector>
using namespace std;

vector<int> heights;
vector<pair<int, int>> tree;

void init(int node, int start, int end) {
  if (start == end) {
    tree[node] = {heights[start], heights[start]};
    return;
  }
  init(node * 2, start, (start + end) / 2);
  init(node * 2 + 1, (start + end) / 2 + 1, end);
  tree[node] = {max(tree[node * 2].first, tree[node * 2 + 1].first),
                min(tree[node * 2].second, tree[node * 2 + 1].second)};
}

pair<int, int> query(int node, int start, int end, int left, int right) {
  if (left > end || right < start) {
    return {numeric_limits<int>::min(), numeric_limits<int>::max()};
  }
  if (left <= start && end <= right) {
    return tree[node];
  }
  pair<int, int> left_query =
      query(node * 2, start, (start + end) / 2, left, right);
  pair<int, int> right_query =
      query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
  return {max(left_query.first, right_query.first),
          min(left_query.second, right_query.second)};
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, Q;
  cin >> N >> Q;
  heights = vector<int>(N);
  for (auto &height : heights) {
    cin >> height;
  }
  tree = vector<pair<int, int>>(1 << ((int)ceil(log2(N)) + 1));
  init(1, 0, N - 1);
  while (Q--) {
    int A, B;
    cin >> A >> B;
    auto [max_height, min_height] = query(1, 0, N - 1, A - 1, B - 1);
    cout << max_height - min_height << '\n';
  }
  return 0;
}

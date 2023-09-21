#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

vector<int> counts;
vector<int> tree;

void update(int node, int start, int end, int index, int value) {
  if (index < start || end < index) {
    return;
  }
  if (start == end) {
    counts[index] = value;
    tree[node] = value;
    return;
  }
  update(node * 2, start, (start + end) / 2, index, value);
  update(node * 2 + 1, (start + end) / 2 + 1, end, index, value);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int start, int end, int left, int right) {
  if (left > end || right < start) {
    return 0;
  }
  if (left <= start && end <= right) {
    return tree[node];
  }
  int left_sum = query(node * 2, start, (start + end) / 2, left, right);
  int right_sum = query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
  return left_sum + right_sum;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  vector<pair<int, int>> edges(M);
  for (auto& edge : edges) {
    cin >> edge.first >> edge.second;
  }
  sort(edges.begin(), edges.end());
  counts = vector<int>(N);
  tree = vector<int>(1 << ((int)ceil(log2(N)) + 1));
  long long total_counts = 0;
  for (const auto& [from, to] : edges) {
    total_counts += query(1, 0, N - 1, to, N - 1);
    update(1, 0, N - 1, to - 1, counts[to - 1] + 1);
  }
  cout << total_counts;
  return 0;
}

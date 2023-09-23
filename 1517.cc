#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

vector<int> tree;

void update(int node, int start, int end, int index, int value) {
  if (index < start || end < index) {
    return;
  }
  if (start == end) {
    tree[node] += value;
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
  int left_query = query(node * 2, start, (start + end) / 2, left, right);
  int right_query =
      query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
  return left_query + right_query;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<pair<int, int>> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i].first;
    A[i].second = i;
  }
  sort(A.begin(), A.end());
  tree = vector<int>(1 << ((int)ceil(log2(N)) + 1));
  long long num_of_swaps = 0;
  for (int i = 0; i < N; ++i) {
    num_of_swaps += query(1, 0, N - 1, A[i].second + 1, N - 1);
    update(1, 0, N - 1, A[i].second, 1);
  }
  cout << num_of_swaps;
  return 0;
}

#include <cmath>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

vector<int> A;
vector<pair<int, int>> tree;

void init(int node, int start, int end) {
  if (start == end) {
    if (A[start] % 2 == 0) {
      ++tree[node].first;
    } else {
      ++tree[node].second;
    }
    return;
  }
  init(node * 2, start, (start + end) / 2);
  init(node * 2 + 1, (start + end) / 2 + 1, end);
  tree[node] = {tree[node * 2].first + tree[node * 2 + 1].first,
                tree[node * 2].second + tree[node * 2 + 1].second};
}

void update(int node, int start, int end, int index, int value) {
  if (index < start || end < index) {
    return;
  }
  if (start == end) {
    A[index] = value;
    tree[node] = {0, 0};
    if (A[index] % 2 == 0) {
      ++tree[node].first;
    } else {
      ++tree[node].second;
    }
    return;
  }
  update(node * 2, start, (start + end) / 2, index, value);
  update(node * 2 + 1, (start + end) / 2 + 1, end, index, value);
  tree[node] = {tree[node * 2].first + tree[node * 2 + 1].first,
                tree[node * 2].second + tree[node * 2 + 1].second};
}

pair<int, int> query(int node, int start, int end, int left, int right) {
  if (left > end || right < start) {
    return {0, 0};
  }
  if (left <= start && end <= right) {
    return tree[node];
  }
  pair<int, int> left_query =
      query(node * 2, start, (start + end) / 2, left, right);
  pair<int, int> right_query =
      query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
  return {left_query.first + right_query.first,
          left_query.second + right_query.second};
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
  tree = vector<pair<int, int>>(1 << ((int)ceil(log2(N)) + 1));
  init(1, 0, N - 1);
  int M;
  cin >> M;
  while (M--) {
    int a, b, c;
    cin >> a >> b >> c;
    switch (a) {
      case 1:
        update(1, 0, N - 1, b - 1, c);
        break;
      case 2:
        cout << query(1, 0, N - 1, b - 1, c - 1).first << '\n';
        break;
      case 3:
        cout << query(1, 0, N - 1, b - 1, c - 1).second << '\n';
        break;
    }
  }
  return 0;
}

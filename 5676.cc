#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

vector<int> X;
vector<int> tree;

void init(int node, int start, int end) {
  if (start == end) {
    if (X[start] > 0) {
      tree[node] = 1;
    } else if (X[start] < 0) {
      tree[node] = -1;
    } else {
      tree[node] = 0;
    }
    return;
  }
  init(node * 2, start, (start + end) / 2);
  init(node * 2 + 1, (start + end) / 2 + 1, end);
  tree[node] = tree[node * 2] * tree[node * 2 + 1];
}

void update(int node, int start, int end, int index, int value) {
  if (index < start || end < index) {
    return;
  }
  if (start == end) {
    X[index] = value;
    if (value > 0) {
      tree[node] = 1;
    } else if (value < 0) {
      tree[node] = -1;
    } else {
      tree[node] = 0;
    }
    return;
  }
  update(node * 2, start, (start + end) / 2, index, value);
  update(node * 2 + 1, (start + end) / 2 + 1, end, index, value);
  tree[node] = tree[node * 2] * tree[node * 2 + 1];
}

int query(int node, int start, int end, int left, int right) {
  if (left > end || right < start) {
    return 1;
  }
  if (left <= start && end <= right) {
    return tree[node];
  }
  int left_query = query(node * 2, start, (start + end) / 2, left, right);
  int right_query =
      query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
  return left_query * right_query;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, K;
  while (cin >> N >> K) {
    X = vector<int>(N);
    for (auto &x : X) {
      cin >> x;
    }
    tree = vector<int>(1 << ((int)ceil(log2(N)) + 1));
    init(1, 0, N - 1);
    while (K--) {
      char type;
      cin >> type;
      int a, b;
      cin >> a >> b;
      if (type == 'C') {
        update(1, 0, N - 1, a - 1, b);
      } else if (type == 'P') {
        int result = query(1, 0, N - 1, a - 1, b - 1);
        if (result > 0) {
          cout << '+';
        } else if (result < 0) {
          cout << '-';
        } else {
          cout << 0;
        }
      }
    }
    cout << '\n';
  }
  return 0;
}

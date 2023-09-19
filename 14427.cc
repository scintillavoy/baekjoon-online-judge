#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

vector<int> A;
vector<pair<int, int>> tree;

void init(int node, int start, int end) {
  if (start == end) {
    tree[node] = {A[start], start};
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
    tree[node] = {value, index};
    return;
  }
  update(node * 2, start, (start + end) / 2, index, value);
  update(node * 2 + 1, (start + end) / 2 + 1, end, index, value);
  tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  A = vector<int>(N);
  tree = vector<pair<int, int>>(1 << ((int)ceil(log2(N)) + 1));
  for (auto &a : A) {
    cin >> a;
  }
  init(1, 0, N - 1);
  int M;
  cin >> M;
  while (M--) {
    int type;
    cin >> type;
    if (type == 1) {
      int i, v;
      cin >> i >> v;
      update(1, 0, N - 1, i - 1, v);
    } else if (type == 2) {
      cout << tree[1].second + 1 << '\n';
    }
  }
  return 0;
}

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

#define MAX 1'000'000

vector<int> tree;

void update(int node, int start, int end, int index, int value) {
  if (index < start || index > end) {
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

int query(int node, int start, int end, int count) {
  if (start == end) {
    return start;
  }
  if (tree[node * 2] >= count) {
    return query(node * 2, start, (start + end) / 2, count);
  }
  return query(node * 2 + 1, (start + end) / 2 + 1, end,
               count - tree[node * 2]);
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  tree = vector<int>(1 << ((int)ceil(log2(MAX + 1)) + 1));
  while (n--) {
    int A;
    cin >> A;
    if (A == 1) {
      int B;
      cin >> B;
      int query_result = query(1, 1, MAX, B);
      cout << query_result << '\n';
      update(1, 1, MAX, query_result, -1);
    } else if (A == 2) {
      int B, C;
      cin >> B >> C;
      update(1, 1, MAX, B, C);
    }
  }
  return 0;
}

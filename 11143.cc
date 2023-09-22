#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

vector<int> boxes;
vector<int> tree;

void update(int node, int start, int end, int index, int value) {
  if (index < start || index > end) {
    return;
  }
  if (start == end) {
    boxes[index] += value;
    tree[node] = boxes[index];
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
  int T;
  cin >> T;
  while (T--) {
    int B, P, Q;
    cin >> B >> P >> Q;
    boxes = vector<int>(B);
    tree = vector<int>(1 << ((int)ceil(log2(B)) + 1));
    for (int i = 0; i < P + Q; ++i) {
      char type;
      int a, b;
      cin >> type >> a >> b;
      if (type == 'P') {
        update(1, 0, B - 1, a - 1, b);
      } else if (type == 'Q') {
        cout << query(1, 0, B - 1, a - 1, b - 1) << '\n';
      }
    }
  }
  return 0;
}

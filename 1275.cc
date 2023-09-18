#include <cmath>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

vector<int> numbers;
vector<long long> tree;

void init(int node, int start, int end) {
  if (start == end) {
    tree[node] = numbers[start];
    return;
  }
  init(node * 2, start, (start + end) / 2);
  init(node * 2 + 1, (start + end) / 2 + 1, end);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void update(int node, int start, int end, int index, int value) {
  if (index < start || index > end) {
    return;
  }
  if (start == end) {
    numbers[index] = value;
    tree[node] = value;
    return;
  }
  update(node * 2, start, (start + end) / 2, index, value);
  update(node * 2 + 1, (start + end) / 2 + 1, end, index, value);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long query(int node, int start, int end, int left, int right) {
  if (left > end || right < start) {
    return 0;
  }
  if (left <= start && end <= right) {
    return tree[node];
  }
  long long left_sum = query(node * 2, start, (start + end) / 2, left, right);
  long long right_sum =
      query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
  return left_sum + right_sum;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, Q;
  cin >> N >> Q;
  numbers = vector<int>(N);
  for (int i = 0; i < N; ++i) {
    cin >> numbers[i];
  }
  tree = vector<long long>(1 << ((int)ceil(log2(N)) + 1));
  init(1, 0, N - 1);
  for (int i = 0; i < Q; ++i) {
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    if (x > y) {
      swap(x, y);
    }
    cout << query(1, 0, N - 1, x - 1, y - 1) << '\n';
    update(1, 0, N - 1, a - 1, b);
  }
  return 0;
}

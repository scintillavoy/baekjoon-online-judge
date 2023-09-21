#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

vector<long long> numbers;
vector<long long> tree;

void update(int node, int start, int end, int index, long long value) {
  if (index < start || end < index) {
    return;
  }
  if (start == end) {
    numbers[index] += value;
    tree[node] = numbers[index];
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
  long long left_query = query(node * 2, start, (start + end) / 2, left, right);
  long long right_query =
      query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
  return left_query + right_query;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, Q;
  cin >> N >> Q;
  numbers = vector<long long>(N);
  tree = vector<long long>(1 << ((int)ceil(log2(N)) + 1));
  while (Q--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 1) {
      update(1, 0, N - 1, b - 1, c);
    } else if (a == 2) {
      cout << query(1, 0, N - 1, b - 1, c - 1) << '\n';
    }
  }
  return 0;
}

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

#define MOD 1'000'000'007

vector<int> numbers;
vector<int> tree;

void init(int node, int start, int end) {
  if (start == end) {
    tree[node] = numbers[start];
    return;
  }
  init(node * 2, start, (start + end) / 2);
  init(node * 2 + 1, (start + end) / 2 + 1, end);
  tree[node] = (long long)tree[node * 2] * tree[node * 2 + 1] % MOD;
}

void update(int node, int start, int end, int index, int value) {
  if (index < start || end < index) {
    return;
  }
  if (start == end) {
    numbers[index] = value;
    tree[node] = value;
    return;
  }
  update(node * 2, start, (start + end) / 2, index, value);
  update(node * 2 + 1, (start + end) / 2 + 1, end, index, value);
  tree[node] = (long long)tree[node * 2] * tree[node * 2 + 1] % MOD;
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
  return (long long)left_query * right_query % MOD;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, M, K;
  cin >> N >> M >> K;
  numbers = vector<int>(N);
  for (auto &x : numbers) {
    cin >> x;
  }
  tree = vector<int>(1 << ((int)ceil(log2(N)) + 1));
  init(1, 0, N - 1);
  for (int i = 0; i < M + K; ++i) {
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

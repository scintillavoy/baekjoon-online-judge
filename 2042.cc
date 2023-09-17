#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

vector<long long> vec;
vector<long long> tree;

void init(int node, int start, int end) {
  if (start == end) {
    tree[node] = vec[start];
    return;
  }
  init(node * 2, start, (start + end) / 2);
  init(node * 2 + 1, (start + end) / 2 + 1, end);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void update(int node, int start, int end, int index, long long value) {
  if (index < start || index > end) {
    return;
  }
  if (start == end) {
    vec[index] = value;
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
  int N, M, K;
  cin >> N >> M >> K;
  for (int i = 0; i < N; ++i) {
    long long num;
    cin >> num;
    vec.push_back(num);
  }
  tree = vector<long long>(1 << ((int)ceil(log2(N)) + 1));
  init(1, 0, N - 1);
  for (int i = 0; i < M + K; ++i) {
    long long a, b, c;
    cin >> a >> b >> c;
    if (a == 1) {
      update(1, 0, N - 1, b - 1, c);
    } else if (a == 2) {
      cout << query(1, 0, N - 1, b - 1, c - 1) << '\n';
    }
  }
  return 0;
}

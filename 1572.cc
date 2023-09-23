#include <cmath>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

#define MAX 65536

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
  int N, K;
  cin >> N >> K;
  tree = vector<int>(1 << ((int)ceil(log2(MAX + 1)) + 1));
  deque<int> dq;
  for (int i = 0; i < K - 1; ++i) {
    int number;
    cin >> number;
    dq.push_back(number);
    update(1, 0, MAX, number, 1);
  }
  long long answer = 0;
  for (int i = 0; i < N - K + 1; ++i) {
    int number;
    cin >> number;
    dq.push_back(number);
    update(1, 0, MAX, number, 1);
    answer += query(1, 0, MAX, (K + 1) / 2);
    int front = dq.front();
    dq.pop_front();
    update(1, 0, MAX, front, -1);
  }
  cout << answer;
  return 0;
}

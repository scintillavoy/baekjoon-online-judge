#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

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
  int mid = (start + end) / 2;
  int left_count = mid - start + 1 - tree[node * 2];
  if (left_count >= count) {
    return query(node * 2, start, mid, count);
  }
  return query(node * 2 + 1, mid + 1, end, count - left_count);
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  tree = vector<int>(1 << ((int)ceil(log2(N)) + 1));
  vector<int> numbers(N);
  for (int i = 1; i <= N; ++i) {
    int inversions;
    cin >> inversions;
    int index = query(1, 0, N - 1, inversions + 1);
    numbers[index] = i;
    update(1, 0, N - 1, index, 1);
  }
  for (const auto &number : numbers) {
    cout << number << '\n';
  }
  return 0;
}

#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
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
  int mid = (start + end) / 2;
  update(node * 2, start, mid, index, value);
  update(node * 2 + 1, mid + 1, end, index, value);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long query(int node, int start, int end, int left, int right) {
  if (left > end || right < start) {
    return 0;
  }
  if (left <= start && end <= right) {
    return tree[node];
  }
  int mid = (start + end) / 2;
  return query(node * 2, start, mid, left, right) +
         query(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int N, M, K;
    cin >> N >> M >> K;
    tree = vector<int>(1 << ((int)ceil(log2(M + 1)) + 1));
    vector<pair<int, int>> roads;
    for (int i = 0; i < K; ++i) {
      int a, b;
      cin >> a >> b;
      roads.push_back({a, b});
    }
    sort(roads.begin(), roads.end());
    long long num_of_intersections = 0;
    for (int i = 0; i < roads.size(); ++i) {
      num_of_intersections += query(1, 1, M, roads[i].second + 1, M);
      update(1, 1, M, roads[i].second, 1);
    }
    cout << "Test case " << t << ": " << num_of_intersections << '\n';
  }
  return 0;
}

#include <iostream>
#include <utility>
#include <vector>
using namespace std;

vector<pair<int, int>> tree;
vector<vector<int>> columns_by_level;
int current_column = 0;

void dfs(int curr, int level) {
  auto [left, right] = tree[curr];
  if (left != -1) {
    dfs(left, level + 1);
  }
  ++current_column;
  columns_by_level[level].push_back(current_column);
  if (right != -1) {
    dfs(right, level + 1);
  }
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  tree = vector<pair<int, int>>(N + 1);
  columns_by_level = vector<vector<int>>(N + 1);
  vector<bool> is_root(N + 1, true);
  for (int i = 0; i < N; ++i) {
    int parent, left, right;
    cin >> parent >> left >> right;
    tree[parent] = {left, right};
    if (left != -1) {
      is_root[left] = false;
    }
    if (right != -1) {
      is_root[right] = false;
    }
  }
  for (int i = 1; i <= N; ++i) {
    if (is_root[i]) {
      dfs(i, 1);
      break;
    }
  }
  int max_width = 1;
  int level = 1;
  for (int i = 1; i <= N; ++i) {
    if (columns_by_level[i].size() <= 1) {
      continue;
    }
    int width = columns_by_level[i].back() - columns_by_level[i].front() + 1;
    if (max_width < width) {
      max_width = width;
      level = i;
    }
  }
  cout << level << ' ' << max_width;
  return 0;
}

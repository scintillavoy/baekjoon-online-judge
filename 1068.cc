#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> tree;
int deleted;
int count_ = 0;

void dfs(int curr) {
  vector<int> children = tree[curr];
  if (children.empty() || children.size() == 1 && children.front() == deleted) {
    ++count_;
  } else {
    for (const auto &child : children) {
      if (child == deleted) {
        continue;
      }
      dfs(child);
    }
  }
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  tree = vector<vector<int>>(N);
  int root;
  for (int i = 0; i < N; ++i) {
    int parent;
    cin >> parent;
    if (parent == -1) {
      root = i;
    } else {
      tree[parent].push_back(i);
    }
  }
  cin >> deleted;
  if (root != deleted) {
    dfs(root);
  }
  cout << count_;
  return 0;
}

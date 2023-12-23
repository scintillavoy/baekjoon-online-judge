#include <iostream>
#include <vector>
using namespace std;

vector<int> tree;

int left_child(int curr) { return curr * 2 + 1; }

int right_child(int curr) { return curr * 2 + 2; }

void inorder(int curr) {
  if (curr < tree.size() / 2) {
    inorder(left_child(curr));
  }
  cin >> tree[curr];
  if (curr < tree.size() / 2) {
    inorder(right_child(curr));
  }
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int K;
  cin >> K;
  tree = vector<int>((1 << K) - 1);
  inorder(0);
  int index = 0;
  for (int i = 0; i < K; ++i) {
    for (int j = 0; j < (1 << i); ++j) {
      cout << tree[index] << ' ';
      ++index;
    }
    cout << '\n';
  }
  return 0;
}

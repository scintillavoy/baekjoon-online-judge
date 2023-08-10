#include <iostream>
#include <utility>
#include <vector>
using namespace std;

vector<pair<int, int>> tree;

void print_preorder(int curr) {
  if (curr == '.' - 'A') return;
  cout << char(curr + 'A');
  print_preorder(tree[curr].first);
  print_preorder(tree[curr].second);
}

void print_inorder(int curr) {
  if (curr == '.' - 'A') return;
  print_inorder(tree[curr].first);
  cout << char(curr + 'A');
  print_inorder(tree[curr].second);
}

void print_postorder(int curr) {
  if (curr == '.' - 'A') return;
  print_postorder(tree[curr].first);
  print_postorder(tree[curr].second);
  cout << char(curr + 'A');
}

int main() {
  int N;
  cin >> N;
  tree = vector<pair<int, int>>(N);
  for (int i = 0; i < N; ++i) {
    char parent, left, right;
    cin >> parent >> left >> right;
    tree[parent - 'A'] = {left - 'A', right - 'A'};
  }
  print_preorder(0);
  cout << '\n';
  print_inorder(0);
  cout << '\n';
  print_postorder(0);
  return 0;
}

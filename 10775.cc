#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

vector<int> rank_;
vector<int> parent;
vector<int> next_gate;

int find_set(int x) {
  if (parent[x] != x) {
    parent[x] = find_set(parent[x]);
  }
  return parent[x];
}

void union_set(int x, int y) {
  x = find_set(x);
  y = find_set(y);
  if (x == y) return;
  if (rank_[x] > rank_[y]) {
    swap(x, y);
  } else if (rank_[x] == rank_[y]) {
    ++rank_[y];
  }
  parent[x] = y;
  next_gate[y] = min(next_gate[x], next_gate[y]);
}

int main() {
  int G, P;
  cin >> G >> P;
  rank_ = vector<int>(G + 1);
  parent = vector<int>(G + 1);
  next_gate = vector<int>(G + 1);
  for (int i = 1; i <= G; ++i) {
    parent[i] = i;
    next_gate[i] = i;
  }
  int count = 0;
  while (P--) {
    int g;
    cin >> g;
    g = find_set(g);
    if (next_gate[g] == 0) break;
    union_set(g, next_gate[g] - 1);
    ++count;
  }
  cout << count;
  return 0;
}

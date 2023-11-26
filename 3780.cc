#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;
vector<int> distance_;

int find_set(int x) {
  if (parent[x] != x) {
    int new_parent = find_set(parent[x]);
    distance_[x] += distance_[parent[x]];
    parent[x] = new_parent;
  }
  return parent[x];
}

void union_set(int x, int y) {
  parent[x] = y;
  distance_[x] = abs(x - y) % 1000;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
outer_loop:
  while (T--) {
    int N;
    cin >> N;
    parent = vector<int>(N + 1);
    for (int i = 1; i <= N; ++i) {
      parent[i] = i;
    }
    distance_ = vector<int>(N + 1);
    while (true) {
      char command;
      cin >> command;
      int I, J;
      switch (command) {
        case 'E':
          cin >> I;
          find_set(I);
          cout << distance_[I] << '\n';
          break;
        case 'I':
          cin >> I >> J;
          union_set(I, J);
          break;
        case 'O':
          goto outer_loop;
      }
    }
  }
  return 0;
}

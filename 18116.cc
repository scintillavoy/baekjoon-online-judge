#include <iostream>
#include <utility>
#include <vector>
using namespace std;

#define MAX 1'000'001

vector<int> parent(MAX);
vector<int> rank_(MAX);
vector<int> size_(MAX, 1);

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
  }
  parent[x] = y;
  size_[y] += size_[x];
  if (rank_[x] == rank_[y]) {
    ++rank_[y];
  }
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  for (int i = 0; i < MAX; ++i) {
    parent[i] = i;
  }
  int N;
  cin >> N;
  while (N--) {
    char type;
    int a, b;
    cin >> type;
    switch (type) {
      case 'I':
        cin >> a >> b;
        union_set(a, b);
        break;
      case 'Q':
        cin >> a;
        cout << size_[find_set(a)] << '\n';
        break;
    }
  }
  return 0;
}

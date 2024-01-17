#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

vector<int> parents;
vector<int> ranks;
vector<int> sizes;

int find_set(int x) {
  if (parents[x] != x) {
    parents[x] = find_set(parents[x]);
  }
  return parents[x];
}

void union_set(int x, int y) {
  x = find_set(x);
  y = find_set(y);
  if (x == y) {
    return;
  }
  if (ranks[x] > ranks[y]) {
    swap(x, y);
  } else if (ranks[x] == ranks[y]) {
    ++ranks[y];
  }
  parents[x] = y;
  sizes[y] += sizes[x];
}

int ccw(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
  int s = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
  s -= p2.first * p1.second + p3.first * p2.second + p1.first * p3.second;
  if (s > 0) {
    return 1;
  }
  if (s < 0) {
    return -1;
  }
  return 0;
}

bool lines_intersect(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3,
                     pair<int, int> p4) {
  int p1p2 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
  int p3p4 = ccw(p3, p4, p1) * ccw(p3, p4, p2);
  if (p1p2 == 0 && p3p4 == 0) {
    if (p1 > p2) {
      swap(p1, p2);
    }
    if (p3 > p4) {
      swap(p3, p4);
    }
    return p3 <= p2 && p1 <= p4;
  }
  return p1p2 <= 0 && p3p4 <= 0;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  parents = vector<int>(N);
  for (int i = 0; i < parents.size(); ++i) {
    parents[i] = i;
  }
  ranks = vector<int>(N);
  sizes = vector<int>(N, 1);
  vector<pair<pair<int, int>, pair<int, int>>> lines(N);
  for (int i = 0; i < lines.size(); ++i) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    lines[i] = {{x1, y1}, {x2, y2}};
  }
  for (int i = 0; i < lines.size(); ++i) {
    for (int j = i + 1; j < lines.size(); ++j) {
      if (lines_intersect(lines[i].first, lines[i].second, lines[j].first,
                          lines[j].second)) {
        union_set(i, j);
      }
    }
  }
  int count = 0;
  int max_size = 0;
  for (int i = 0; i < parents.size(); ++i) {
    if (parents[i] == i) {
      ++count;
      max_size = max(max_size, sizes[i]);
    }
  }
  cout << count << '\n';
  cout << max_size;
  return 0;
}

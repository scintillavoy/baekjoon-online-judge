#include <iostream>
#include <utility>
#include <vector>
using namespace std;

vector<vector<int>> rank_;
vector<vector<pair<int, int>>> parent;

pair<int, int> find_set(pair<int, int> x) {
  if (parent[x.first][x.second] != x) {
    parent[x.first][x.second] = find_set(parent[x.first][x.second]);
  }
  return parent[x.first][x.second];
}

void union_set(pair<int, int> x, pair<int, int> y) {
  x = find_set(x);
  y = find_set(y);
  if (x == y) return;
  if (rank_[x.first][x.second] > rank_[y.first][y.second]) {
    swap(x, y);
  } else if (rank_[x.first][x.second] == rank_[y.first][y.second]) {
    ++rank_[y.first][y.second];
  }
  parent[x.first][x.second] = y;
}

int main() {
  int N, M;
  cin >> N >> M;
  rank_ = vector<vector<int>>(N, vector<int>(M));
  parent = vector<vector<pair<int, int>>>(N, vector<pair<int, int>>(M));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      parent[i][j] = {i, j};
    }
  }
  vector<vector<char>> vec(N, vector<char>(M));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> vec[i][j];
      switch (vec[i][j]) {
        case 'U':
          union_set({i, j}, {i - 1, j});
          break;
        case 'D':
          union_set({i, j}, {i + 1, j});
          break;
        case 'L':
          union_set({i, j}, {i, j - 1});
          break;
        case 'R':
          union_set({i, j}, {i, j + 1});
          break;
      }
    }
  }
  int count = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (parent[i][j] == make_pair(i, j)) {
        ++count;
      }
    }
  }
  cout << count;
  return 0;
}

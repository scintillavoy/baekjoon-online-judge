#include <algorithm>
#include <cmath>
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

vector<vector<pair<int, int>>> parent;
vector<vector<int>> rank_;

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
  int N;
  cin >> N;
  parent = vector<vector<pair<int, int>>>(N, vector<pair<int, int>>(N));
  rank_ = vector<vector<int>>(N, vector<int>(N));
  vector<vector<int>> heights(N, vector<int>(N));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      parent[i][j] = {i, j};
      cin >> heights[i][j];
    }
  }
  vector<tuple<int, pair<int, int>, pair<int, int>>> edges;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k < 4; ++k) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (x < 0 || x >= N || y < 0 || y >= N) continue;
        edges.push_back({abs(heights[i][j] - heights[x][y]), {i, j}, {x, y}});
      }
    }
  }
  sort(edges.begin(), edges.end());
  for (const auto &edge : edges) {
    auto [weight, from, to] = edge;
    if (find_set(from) == find_set(to)) continue;
    union_set(from, to);
    if (find_set({0, 0}) == find_set({N - 1, N - 1})) {
      cout << weight;
      return 0;
    }
  }
  cout << 0;
  return 0;
}

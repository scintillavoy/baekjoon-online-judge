#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, M, T, D;
  cin >> N >> M >> T >> D;
  vector<vector<int>> mountain(N, vector<int>(M));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      char height;
      cin >> height;
      if (isupper(height)) {
        mountain[i][j] = height - 'A';
      } else {
        mountain[i][j] = height - 'a' + 26;
      }
    }
  }
  vector<vector<int>> distance_(
      N * M, vector<int>(N * M, numeric_limits<int>::max() / 2));
  for (int i = 0; i < N * M; ++i) {
    distance_[i][i] = 0;
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      for (int k = 0; k < 4; ++k) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (x < 0 || x >= N || y < 0 || y >= M ||
            abs(mountain[i][j] - mountain[x][y]) > T) {
          continue;
        }
        int weight;
        if (mountain[i][j] >= mountain[x][y]) {
          weight = 1;
        } else {
          int diff = mountain[x][y] - mountain[i][j];
          weight = diff * diff;
        }
        distance_[i * M + j][x * M + y] = weight;
      }
    }
  }
  for (int k = 0; k < N * M; ++k) {
    for (int i = 0; i < N * M; ++i) {
      for (int j = 0; j < N * M; ++j) {
        if (distance_[i][j] > distance_[i][k] + distance_[k][j]) {
          distance_[i][j] = distance_[i][k] + distance_[k][j];
        }
      }
    }
  }
  int max_height = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (distance_[0][i * M + j] + distance_[i * M + j][0] <= D) {
        max_height = max(max_height, mountain[i][j]);
      }
    }
  }
  cout << max_height;
  return 0;
}

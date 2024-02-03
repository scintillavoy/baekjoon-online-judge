#include <algorithm>
#include <deque>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, M, K;
  cin >> N >> M >> K;
  vector<vector<int>> A(N + 1, vector<int>(N + 1));
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      cin >> A[i][j];
    }
  }
  deque<tuple<int, int, int>> trees;
  for (int i = 0; i < M; ++i) {
    int x, y, age;
    cin >> x >> y >> age;
    trees.push_back({x, y, age});
  }
  sort(trees.begin(), trees.end());
  vector<vector<int>> nutrient(N + 1, vector<int>(N + 1, 5));
  while (K--) {
    deque<tuple<int, int, int>> next_trees;
    vector<vector<int>> nutrient_diff(N + 1, vector<int>(N + 1));
    for (const auto [x, y, age] : trees) {
      if (nutrient[x][y] < age) {
        nutrient_diff[x][y] += age / 2;
      } else {
        nutrient[x][y] -= age;
        next_trees.push_back({x, y, age + 1});
        if ((age + 1) % 5 == 0) {
          for (int i = 0; i < 8; ++i) {
            int x2 = x + dx[i];
            int y2 = y + dy[i];
            if (x2 <= 0 || x2 > N || y2 <= 0 || y2 > N) {
              continue;
            }
            next_trees.push_front({x2, y2, 1});
          }
        }
      }
    }
    for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= N; ++j) {
        nutrient[i][j] += nutrient_diff[i][j] + A[i][j];
      }
    }
    trees = next_trees;
  }
  cout << trees.size();
  return 0;
}

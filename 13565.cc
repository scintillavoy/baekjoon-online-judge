#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int M, N;
  cin >> M >> N;
  vector<vector<bool>> cells(M, vector<bool>(N));
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      char input;
      cin >> input;
      cells[i][j] = (input == '0' ? true : false);
    }
  }
  queue<pair<int, int>> q;
  for (int i = 0; i < N; ++i) {
    if (cells[0][i]) {
      cells[0][i] = false;
      q.push({0, i});
    }
  }
  while (!q.empty()) {
    auto [curr_x, curr_y] = q.front();
    q.pop();
    if (curr_x == M - 1) {
      cout << "YES";
      return 0;
    }
    for (int i = 0; i < 4; ++i) {
      int next_x = curr_x + dx[i];
      int next_y = curr_y + dy[i];
      if (next_x < 0 || next_x >= M || next_y < 0 || next_y >= N ||
          !cells[next_x][next_y]) {
        continue;
      }
      cells[next_x][next_y] = false;
      q.push({next_x, next_y});
    }
  }
  cout << "NO";
  return 0;
}

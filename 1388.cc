#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<char>> boards;
vector<vector<bool>> visited;

void dfs(int x, int y) {
  visited[x][y] = true;
  if (boards[x][y] == '-') {
    if (y - 1 >= 0 && boards[x][y] == boards[x][y - 1] && !visited[x][y - 1]) {
      dfs(x, y - 1);
    }
    if (y + 1 < M && boards[x][y] == boards[x][y + 1] && !visited[x][y + 1]) {
      dfs(x, y + 1);
    }
  } else {
    if (x - 1 >= 0 && boards[x][y] == boards[x - 1][y] && !visited[x - 1][y]) {
      dfs(x - 1, y);
    }
    if (x + 1 < N && boards[x][y] == boards[x + 1][y] && !visited[x + 1][y]) {
      dfs(x + 1, y);
    }
  }
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cin >> N >> M;
  boards = vector<vector<char>>(N, vector<char>(M));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> boards[i][j];
    }
  }
  visited = vector<vector<bool>>(N, vector<bool>(M));
  int count = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (visited[i][j]) {
        continue;
      }
      ++count;
      dfs(i, j);
    }
  }
  cout << count;
  return 0;
}

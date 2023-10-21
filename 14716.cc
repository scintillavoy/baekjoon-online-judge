#include <iostream>
#include <vector>
using namespace std;

const int dx[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
const int dy[8] = {-1, 0, 1, -1, 0, 1, -1, 1};

int M, N;
vector<vector<bool>> banner;

void dfs(int x, int y) {
  banner[x][y] = false;
  for (int i = 0; i < 8; ++i) {
    int x2 = x + dx[i];
    int y2 = y + dy[i];
    if (x2 < 0 || x2 >= M || y2 < 0 || y2 >= N || !banner[x2][y2]) {
      continue;
    }
    dfs(x2, y2);
  }
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cin >> M >> N;
  cin >> noboolalpha;
  banner = vector<vector<bool>>(M, vector<bool>(N));
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      bool input;
      cin >> input;
      banner[i][j] = input;
    }
  }
  int count = 0;
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      if (!banner[i][j]) {
        continue;
      }
      ++count;
      dfs(i, j);
    }
  }
  cout << count;
  return 0;
}

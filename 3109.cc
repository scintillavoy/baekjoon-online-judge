#include <iostream>
#include <vector>
using namespace std;

const int dx[3] = {-1, 0, 1};

int R, C;
vector<vector<bool>> vec;

int dfs(int x, int y) {
  if (y == C - 1) {
    return 1;
  }
  for (int i = 0; i < 3; ++i) {
    int x2 = x + dx[i];
    int y2 = y + 1;
    if (x2 < 0 || x2 >= R || y2 < 0 || y2 >= C || vec[x2][y2]) {
      continue;
    }
    vec[x2][y2] = true;
    int result = dfs(x2, y2);
    if (result != 0) {
      return result;
    }
  }
  return 0;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cin >> R >> C;
  vec = vector<vector<bool>>(R, vector<bool>(C));
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      char input;
      cin >> input;
      if (input == 'x') {
        vec[i][j] = true;
      }
    }
  }
  int count = 0;
  for (int i = 0; i < R; ++i) {
    count += dfs(i, 0);
  }
  cout << count;
  return 0;
}

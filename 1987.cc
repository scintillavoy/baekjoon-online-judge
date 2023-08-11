#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int R, C;
vector<vector<char>> vec;
bitset<26> is_visited;
int max_depth = 0;

void dfs(int x, int y, int depth) {
  max_depth = max(max_depth, depth);
  for (int i = 0; i < 4; ++i) {
    int x2 = x + dx[i], y2 = y + dy[i];
    if (x2 < 0 || x2 >= R || y2 < 0 || y2 >= C ||
        is_visited.test(vec[x2][y2] - 'A')) {
      continue;
    }
    is_visited.set(vec[x2][y2] - 'A');
    dfs(x2, y2, depth + 1);
    is_visited.reset(vec[x2][y2] - 'A');
  }
}

int main() {
  cin >> R >> C;
  vec = vector<vector<char>>(R, vector<char>(C));
  for (auto &row : vec) {
    for (auto &x : row) {
      cin >> x;
    }
  }
  is_visited.set(vec[0][0] - 'A');
  dfs(0, 0, 1);
  cout << max_depth;
  return 0;
}

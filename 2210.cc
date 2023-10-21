#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

vector<vector<char>> board(5, vector<char>(5));
unordered_set<string> numbers;

void dfs(int x, int y, string number) {
  if (number.size() == 6) {
    numbers.insert(number);
    return;
  }
  for (int i = 0; i < 4; ++i) {
    int x2 = x + dx[i];
    int y2 = y + dy[i];
    if (x2 < 0 || x2 > 4 || y2 < 0 || y2 > 4) {
      continue;
    }
    dfs(x2, y2, number + board[x][y]);
  }
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      cin >> board[i][j];
    }
  }
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      dfs(i, j, "");
    }
  }
  cout << numbers.size();
  return 0;
}

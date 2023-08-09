#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

const int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
const int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int main() {
  int T;
  cin >> T;
  while (T--) {
    int l;
    cin >> l;
    pair<int, int> source, destination;
    cin >> source.first >> source.second;
    cin >> destination.first >> destination.second;
    vector<vector<bool>> board(l, vector<bool>(l, false));
    vector<vector<int>> distance(l, vector<int>(l, -1));
    queue<pair<int, int>> bfs_queue;
    board[source.first][source.second] = true;
    distance[source.first][source.second] = 0;
    bfs_queue.push(source);
    while (!bfs_queue.empty()) {
      pair<int, int> curr = bfs_queue.front();
      bfs_queue.pop();
      if (curr == destination) {
        cout << distance[curr.first][curr.second] << '\n';
        break;
      }
      for (int i = 0; i < 8; ++i) {
        pair<int, int> next{curr.first + dx[i], curr.second + dy[i]};
        if (next.first < 0 || next.first >= l || next.second < 0 ||
            next.second >= l || board[next.first][next.second]) {
          continue;
        }
        board[next.first][next.second] = true;
        distance[next.first][next.second] =
            distance[curr.first][curr.second] + 1;
        bfs_queue.push(next);
      }
    }
  }
  return 0;
}

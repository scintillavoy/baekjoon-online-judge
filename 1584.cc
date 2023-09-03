#include <deque>
#include <iostream>
#include <limits>
#include <utility>
#include <vector>
using namespace std;

#define SIZE 501

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int main() {
  vector<vector<int>> area(SIZE, vector<int>(SIZE));
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    int X1, Y1, X2, Y2;
    cin >> X1 >> Y1 >> X2 >> Y2;
    if (X1 > X2) {
      swap(X1, X2);
    }
    if (Y1 > Y2) {
      swap(Y1, Y2);
    }
    for (int x = X1; x <= X2; ++x) {
      for (int y = Y1; y <= Y2; ++y) {
        area[x][y] = 1;
      }
    }
  }
  int M;
  cin >> M;
  for (int i = 0; i < M; ++i) {
    int X1, Y1, X2, Y2;
    cin >> X1 >> Y1 >> X2 >> Y2;
    if (X1 > X2) {
      swap(X1, X2);
    }
    if (Y1 > Y2) {
      swap(Y1, Y2);
    }
    for (int x = X1; x <= X2; ++x) {
      for (int y = Y1; y <= Y2; ++y) {
        area[x][y] = 2;
      }
    }
  }
  vector<vector<int>> distance_(SIZE,
                                vector<int>(SIZE, numeric_limits<int>::max()));
  deque<pair<int, int>> dq;
  distance_[0][0] = 0;
  dq.push_front({0, 0});
  while (!dq.empty()) {
    auto [curr_x, curr_y] = dq.front();
    dq.pop_front();
    for (int i = 0; i < 4; ++i) {
      int next_x = curr_x + dx[i];
      int next_y = curr_y + dy[i];
      if (next_x < 0 || next_x >= SIZE || next_y < 0 || next_y >= SIZE ||
          area[next_x][next_y] == 2) {
        continue;
      }
      int weight = area[next_x][next_y];
      if (distance_[next_x][next_y] > distance_[curr_x][curr_y] + weight) {
        distance_[next_x][next_y] = distance_[curr_x][curr_y] + weight;
        if (weight == 0) {
          dq.push_front({next_x, next_y});
        } else {
          dq.push_back({next_x, next_y});
        }
      }
    }
  }
  cout << (distance_[SIZE - 1][SIZE - 1] == numeric_limits<int>::max()
               ? -1
               : distance_[SIZE - 1][SIZE - 1]);
  return 0;
}

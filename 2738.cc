#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> A(N, vector<int>(M));
  for (auto &row : A) {
    for (auto &x : row) {
      cin >> x;
    }
  }
  for (auto &row : A) {
    for (auto &x : row) {
      int y;
      cin >> y;
      cout << x + y << ' ';
    }
    cout << '\n';
  }
  return 0;
}

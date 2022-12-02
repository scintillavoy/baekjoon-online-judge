#include <iostream>
using namespace std;

int main() {
  int arr[100][100] = {0};
  int N, M;
  cin >> N >> M;
  while (N--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for (int i = x1; i <= x2; ++i) {
      for (int j = y1; j <= y2; ++j) {
        ++arr[i - 1][j - 1];
      }
    }
  }
  int count = 0;
  for (const auto &row : arr) {
    for (const auto &elem : row) {
      if (elem > M) {
        ++count;
      }
    }
  }
  cout << count;
  return 0;
}

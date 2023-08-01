#include <algorithm>
#include <iostream>
#include <limits>
using namespace std;

int main() {
  int N;
  cin >> N;
  int M;
  cin >> M;
  int prev_x = 0, x;
  cin >> x;
  int min_height = x;
  prev_x = x;
  for (int i = 1; i < M; ++i) {
    cin >> x;
    min_height = max(min_height, (x - prev_x) / 2 + (x - prev_x) % 2);
    prev_x = x;
  }
  min_height = max(min_height, N - x);
  cout << min_height;
  return 0;
}

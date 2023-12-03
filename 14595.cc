#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  int M;
  cin >> M;
  vector<pair<int, int>> vec(M);
  for (int i = 0; i < M; ++i) {
    cin >> vec[i].first >> vec[i].second;
  }
  sort(vec.begin(), vec.end());
  int count = 0;
  int last_x = 0, last_y = 0;
  for (int i = 0; i < M; ++i) {
    auto [x, y] = vec[i];
    if (x <= last_y) {
      last_y = max(last_y, y);
    } else {
      count += last_y - last_x;
      last_x = x;
      last_y = y;
    }
  }
  count += last_y - last_x;
  cout << N - count;
  return 0;
}

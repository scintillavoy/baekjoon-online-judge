#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<pair<int, int>> points(N);
  for (auto &x : points) {
    cin >> x.first >> x.second;
  }
  sort(points.begin(), points.end());
  for (const auto &x : points) {
    cout << x.first << ' ' << x.second << '\n';
  }
  return 0;
}

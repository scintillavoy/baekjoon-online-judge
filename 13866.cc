#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  vector<int> levels(4);
  for (auto &level : levels) {
    cin >> level;
  }
  sort(levels.begin(), levels.end());
  cout << abs(levels[3] + levels[0] - levels[2] - levels[1]);
  return 0;
}

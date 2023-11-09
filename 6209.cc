#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int d, n, m;
  cin >> d >> n >> m;
  vector<int> positions(n);
  for (int i = 0; i < positions.size(); ++i) {
    cin >> positions[i];
  }
  positions.push_back(0);
  positions.push_back(d);
  sort(positions.begin(), positions.end());
  int left = 1, right = d;
  while (left <= right) {
    int mid = (left + right) / 2;
    int count = 0;
    int last_position = positions[0];
    for (int i = 1; i < positions.size(); ++i) {
      if (positions[i] - last_position < mid) {
        ++count;
      } else {
        last_position = positions[i];
      }
    }
    if (count > m) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  cout << left - 1;
  return 0;
}

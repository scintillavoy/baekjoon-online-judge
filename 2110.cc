#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, C;
  cin >> N >> C;
  vector<int> positions(N);
  for (int i = 0; i < positions.size(); ++i) {
    cin >> positions[i];
  }
  sort(positions.begin(), positions.end());
  int left = 1, right = positions.back() - positions.front();
  while (left <= right) {
    int mid = (left + right) / 2;
    int count = 1;
    int last_position = positions[0];
    for (int i = 1; i < positions.size(); ++i) {
      if (last_position + mid <= positions[i]) {
        ++count;
        last_position = positions[i];
      }
    }
    if (count < C) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  cout << left - 1;
  return 0;
}

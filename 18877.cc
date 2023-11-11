#include <algorithm>
#include <iostream>
#include <limits>
#include <utility>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  vector<pair<long long, long long>> intervals(M);
  for (int i = 0; i < intervals.size(); ++i) {
    cin >> intervals[i].first >> intervals[i].second;
  }
  sort(intervals.begin(), intervals.end());
  long long left = 0, right = 1e18;
  while (left <= right) {
    long long mid = (left + right) / 2;
    int count = 0;
    long long last_position = numeric_limits<long long>::min();
    int curr = 0;
    while (curr < intervals.size()) {
      ++count;
      last_position = max(intervals[curr].first, last_position + mid);
      while (curr < intervals.size() &&
             last_position + mid > intervals[curr].second) {
        ++curr;
      }
    }
    if (count < N) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  cout << left - 1;
  return 0;
}

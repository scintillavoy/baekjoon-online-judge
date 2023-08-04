#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n, K;
    cin >> n >> K;
    vector<int> vec(n);
    for (auto &x : vec) {
      cin >> x;
    }
    sort(vec.begin(), vec.end());
    int count = 0;
    int min_diff = abs(vec[0] + vec[n - 1] - K);
    int left = 0, right = n - 1;
    while (left < right) {
      int diff = abs(vec[left] + vec[right] - K);
      if (diff == min_diff) {
        ++count;
      } else if (diff < min_diff) {
        min_diff = diff;
        count = 1;
      }
      if (vec[left] + vec[right] - K < 0) {
        ++left;
      } else {
        --right;
      }
    }
    cout << count << '\n';
  }
  return 0;
}

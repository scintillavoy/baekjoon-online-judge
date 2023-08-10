#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> curr(3);
  cin >> curr[1];
  for (int i = 2; i <= n; ++i) {
    vector<int> next(i + 2);
    for (int j = 1; j <= i; ++j) {
      cin >> next[j];
      next[j] += max(curr[j - 1], curr[j]);
    }
    curr = next;
  }
  cout << *max_element(curr.cbegin(), curr.cend());
  return 0;
}

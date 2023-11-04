#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int x;
  while (cin >> x) {
    x *= 10'000'000;
    int n;
    cin >> n;
    vector<int> l(n);
    for (int i = 0; i < n; ++i) {
      cin >> l[i];
    }
    sort(l.begin(), l.end());
    bool is_possible = false;
    for (int i = 0; i < n - 1; ++i) {
      int left = i + 1, right = n - 1;
      while (left <= right) {
        int mid = (left + right) / 2;
        if (l[i] + l[mid] >= x) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      }
      if (left < n && l[i] + l[left] == x) {
        cout << "yes " << l[i] << ' ' << l[left] << '\n';
        is_possible = true;
        break;
      }
    }
    if (!is_possible) {
      cout << "danger\n";
    }
  }
  return 0;
}

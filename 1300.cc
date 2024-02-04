#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  int k;
  cin >> k;
  int left = 0, right = 1'000'000'000;
  while (left <= right) {
    int mid = (left + right) / 2;
    int lte = 0;
    for (int i = 1; i <= N; ++i) {
      lte += min(N, mid / i);
    }
    if (k <= lte) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  cout << left;
  return 0;
}

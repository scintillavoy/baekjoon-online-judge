#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> vec(N);
  for (auto &x : vec) {
    cin >> x;
  }
  int left = 1, right = 1'000'000'000;
outer_loop:
  while (left <= right) {
    int mid = (left + right) / 2;
    int balance = 0;
    int count = 0;
    for (auto &x : vec) {
      if (x > mid) {
        left = mid + 1;
        goto outer_loop;
      }
      if (balance < x) {
        ++count;
        balance = mid;
      }
      balance -= x;
    }
    if (count > M) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  cout << left;
  return 0;
}

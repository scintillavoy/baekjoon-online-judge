#include <iostream>
#include <vector>
using namespace std;

int main() {
  int S, C;
  cin >> S >> C;
  vector<int> L(S);
  for (auto &l : L) {
    cin >> l;
  }
  int left = 1, right = 1'000'000'000;
  while (left <= right) {
    int mid = (left + right) / 2;
    long long count = 0;
    for (auto &l : L) {
      count += l / mid;
    }
    if (count >= C) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  long long sum = 0;
  for (auto &l : L) {
    sum += l;
  }
  cout << sum - (long long)(left - 1) * C;
  return 0;
}

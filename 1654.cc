#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int K, N;
  cin >> K >> N;
  vector<int> lengths(K);
  for (auto &x : lengths) {
    cin >> x;
  }
  long long left = 1, right = *max_element(lengths.cbegin(), lengths.cend());
  while (left <= right) {
    long long mid = (left + right) / 2;
    long long count = 0;
    for (const auto &x : lengths) {
      count += x / mid;
    }
    if (count >= N) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  cout << left - 1;
  return 0;
}

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
  int N, K, B;
  cin >> N >> K >> B;
  vector<bool> vec(N + 1, false);
  while (B--) {
    int num;
    cin >> num;
    vec[num] = true;
  }
  int left = 1, right = K;
  int count = 0;
  for (int i = left; i <= right; ++i) {
    if (vec[i]) ++count;
  }
  int min_count = count;
  while (right <= N) {
    if (vec[left]) --count;
    ++left, ++right;
    if (vec[right]) ++count;
    min_count = min(min_count, count);
  }
  cout << min_count;
  return 0;
}

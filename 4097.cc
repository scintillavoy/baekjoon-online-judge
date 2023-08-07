#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int main() {
  while (true) {
    int N;
    cin >> N;
    if (N == 0) break;
    long long max_sum = numeric_limits<long long>::min();
    long long sum = 0;
    while (N--) {
      long long P;
      cin >> P;
      sum += P;
      max_sum = max(max_sum, sum);
      if (sum < 0) {
        sum = 0;
      }
    }
    cout << max_sum << '\n';
  }
  return 0;
}

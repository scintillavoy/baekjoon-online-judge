#include <algorithm>
#include <iostream>
#include <limits>
using namespace std;

int main() {
  int n;
  cin >> n;
  int max_sum = numeric_limits<int>::min();
  int current_sum = 0;
  while (n--) {
    int number;
    cin >> number;
    current_sum += number;
    max_sum = max(max_sum, current_sum);
    if (current_sum < 0) {
      current_sum = 0;
    }
  }
  cout << max_sum;
  return 0;
}

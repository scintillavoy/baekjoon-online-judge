#include <algorithm>
#include <iostream>
#include <limits>
using namespace std;

int main() {
  int N;
  cin >> N;
  int min_num = numeric_limits<int>::max();
  int max_num = numeric_limits<int>::min();
  while (N--) {
    int number;
    cin >> number;
    min_num = min(min_num, number);
    max_num = max(max_num, number);
  }
  cout << min_num << ' ' << max_num;
  return 0;
}

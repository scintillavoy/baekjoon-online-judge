#include <iostream>
#include <limits>
using namespace std;

int main() {
  int max_num = numeric_limits<int>::min();
  int max_pos = -1;
  for (int i = 0; i < 9; ++i) {
    int num;
    cin >> num;
    if (num > max_num) {
      max_num = num;
      max_pos = i;
    }
  }
  cout << max_num << '\n' << max_pos + 1;
  return 0;
}

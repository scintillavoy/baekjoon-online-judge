#include <iostream>
using namespace std;

int main() {
  while (true) {
    int number;
    cin >> number;
    if (number == 0) break;
    int count = 0;
    int left = 2, right = 100;
    if (number % 2 == 1) {
      ++count;
      left = 1, right = 99;
    }
    while (left <= right) {
      ++count;
      int mid = (left + right) / 2;
      if (mid % 2 != number % 2) {
        --mid;
      }
      if (mid == number) {
        break;
      } else if (mid < number) {
        left = mid + 2;
      } else {
        right = mid - 2;
      }
    }
    cout << count << '\n';
  }
  return 0;
}

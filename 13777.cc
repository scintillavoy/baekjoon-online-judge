#include <iostream>
using namespace std;

int main() {
  while (true) {
    int number;
    cin >> number;
    if (number == 0) break;
    int left = 1, right = 50;
    while (left <= right) {
      int mid = (left + right) / 2;
      cout << mid << ' ';
      if (mid == number) {
        break;
      } else if (mid < number) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    cout << '\n';
  }
  return 0;
}

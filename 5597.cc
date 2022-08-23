#include <iostream>
using namespace std;

int main() {
  int submission = 0;
  for (int i = 0; i < 28; ++i) {
    int attendance_number;
    cin >> attendance_number;
    submission |= 1 << attendance_number;
  }
  for (int i = 1; i <= 30; ++i) {
    if ((submission & (1 << i)) != 1 << i) {
      cout << i << '\n';
    }
  }
  return 0;
}

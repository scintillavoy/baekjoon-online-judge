#include <iostream>
using namespace std;

int main() {
  int number;
  cin >> number;
  int value = 0;
  if (number % 7 == 0) {
    ++value;
  }
  while (number > 0) {
    if (number % 10 == 7) {
      value += 2;
      break;
    }
    number /= 10;
  }
  cout << value;
  return 0;
}

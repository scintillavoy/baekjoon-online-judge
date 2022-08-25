#include <iostream>
using namespace std;

int main() {
  int sum_of_squared = 0;
  for (int i = 0; i < 5; ++i) {
    int number;
    cin >> number;
    sum_of_squared += number * number;
  }
  cout << sum_of_squared % 10;
  return 0;
}

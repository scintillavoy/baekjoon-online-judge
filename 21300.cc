#include <iostream>
using namespace std;

int main() {
  int sum = 0;
  for (int i = 0; i < 6; ++i) {
    int number;
    cin >> number;
    sum += number;
  }
  cout << sum * 5;
  return 0;
}
